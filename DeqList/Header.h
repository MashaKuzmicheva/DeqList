#pragma once
#include <iostream>
#include "Header1.h"

using namespace std;

template<class T>
class DeqList;

template<class T>
class Iterator
{
 
private:
    DeqList<T>* List;
    typename DeqList<T>::ListNode* CurrentNode;

    int step_;
   
    Iterator(DeqList<T>* Deque, int index) { // 0 - голова, 1-хвост 
        List = Deque;
        step_ = 1;
        if (index == 0)	CurrentNode = Deque->head;
        if (index == 1) CurrentNode = Deque->tail;
    }
    
  
public:
    friend class DeqList<T>;
    Iterator(const Iterator& i)
    {
        List = i.List;
        CurrentNode = i.CurrentNode;
    }
    Iterator(DeqList<T>* p = nullptr, typename DeqList<T>::ListNode* pos = nullptr)
    {
        List = p;
        CurrentNode = pos;
    }
   
    
  

    void print() {
       
        cout << "OurIterDeque _ " << List << endl;
        cout << "CrrentIt_ " << CurrentNode << endl;
        cout << "Step_" << step_ << endl;
    }
    void parametrs(int start, int step) {
        step_ = step;
        for (int i = 0; i < start; i++) {
            CurrentNode = CurrentNode->next;
        }
    }

    void operator=(const Iterator& i)
    {
        List = i.List;
        CurrentNode = i.CurrentNode;
    }
    bool operator!=(const Iterator& i)
    {
        return (List != i.List) || (CurrentNode != i.CurrentNode);
    }
    bool operator==(const Iterator& i)
    {
        return (List == i.List) && (CurrentNode == i.CurrentNode);
    }
    Iterator& operator++()
    {
        CurrentNode = CurrentNode->next;
        
        return *this;
    }
    Iterator& operator--()
    {
        CurrentNode = CurrentNode->prev;
        return *this;
    }
    T& operator*()
    {
        return CurrentNode->value; 
    }

    
};




template<class T>
class DeqList
{
    friend class Iterator<T>;
private:
    struct ListNode
    {
        T value;
        ListNode* prev;
        ListNode* next;
        ListNode()
        {
            next = this;
            prev = this;
        }
        void LinkNext(ListNode* p)
        {
            next = p;
            p->prev = this;
        }
        void LinkPrev(ListNode* p)
        {
            prev = p;
            p->next = this;
        }
        ListNode(T x, ListNode* Next = NULL, ListNode* Prev = NULL) { //конструктор узла  
            value = x;
            next = Next;
            prev = Prev;
        }
    };
    ListNode* head;
    ListNode* tail;
    int Size;
    void swap(DeqList<T>::ListNode* First, DeqList<T>::ListNode* Second);//меняем местами два узла

    void copy(DeqList<T>::ListNode* S, DeqList<T>::ListNode* O); //копируем 
public:
    DeqList()
    {
        try {
           
            head = NULL;
            tail = NULL;
            Size = 0; //
        }
        catch (const bad_alloc& e) {
            throw new MyException("DeqList<T>: memory allocation error\n", EC_MEMORY);
        }
    }
 

    ~DeqList()
    {
        while (Size) pop_front();
    }

    void push_front(const T& x); // добавляем в голову
    void push_back(const T& x); // добавляем в хвост

    void pop_front(); //удаляем из головы
    void pop_back(); //удаляем из хвоста
    
    
    
    int GetSize() const { return Size; }


    Iterator<T> Head()
    {
        return Iterator<T>(this, head);
    }
    Iterator<T> begin() {
        
        Iterator<T> it(this, 0);
       // DeqList<int>* p = it.CurrentNode;
       // cout << p;
       // cout <<it.CurrentNode << it.List<< endl;
        return it;
    }
    Iterator<T> end() {
        Iterator<T> it(this, 1);
       
        //cout << it.CurrentNode <<  endl;
        return it;
    }


    /*ostream& operator<<(ostream& os, Iterator<int>& i)
    {
        cout << i.CurrentNode;
        return os;
    }*/
    

    template<class P>
    friend ostream& operator<<(ostream& os, const DeqList<P>& L);
};



template<class T>
ostream& operator<<(ostream& os, const DeqList<T>& L)
{
    typename DeqList<T>::ListNode* p = L.head;
   
    cout << "[" << L.GetSize() << "] ";
   
    for (int i = 0; i < L.GetSize(); i++) {
        cout << p->value  <<" ";
        p = p->next;
    }
    cout << endl;
    return os;
}




template<class T>
void  DeqList<T>::push_front(const T& x)
{
    try
    {
        head = new ListNode(x, head, tail);

        if (Size == 0) {
            tail = head;
            head->next = head->prev = head;
        }

        else {
            tail->next = head;
            (head->next)->prev = head;
        }

        ++Size;
        
    }
    catch (const bad_alloc& e)
    {
        throw new MyException("DeqList<T>::push_front: memory allocation error\n", EC_MEMORY);
    }
}

template<class T>
void  DeqList<T>::push_back(const T& x)
{
    try
    {
        tail = new ListNode(x, head, tail);

        if (Size == 0) {
            head = tail;
            tail->next = tail->prev = tail;
        }
        else {
            head->prev = tail;
            (tail->prev)->next = tail;
        }
        ++Size;
    }
    catch (const bad_alloc& e)
    {
        throw new MyException("DeqList<T>::push_back: memory allocation error\n", EC_MEMORY);
    }
   
}

template<class T>
void DeqList<T>::pop_front()
{
   
    //try {
        if (Size > 0)
        {
            ListNode* temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
            --Size;

        }
        else
        {
          // throw - 1;
            throw MyException("DeqList<T>::pop_front: size <= 0\n", EC_SIZE);
        }
    //}
    // catch(int a)   
      //  {
         // throw MyException ("DeqList<T>::pop_front: size <= 0\n", EC_SIZE);
      //   MyException("DeqList<T>::pop_front: size <= 0\n", EC_SIZE);
       // }
  
}


template<typename T>
void DeqList<T>::pop_back() {

    //try {
        if (Size > 0) {

            ListNode* temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
            --Size;
        }
        else
            throw new MyException("DeqList<T>::pop_back: size <= 0\n", EC_SIZE);
            //throw - 1;
   // }
   // catch (int a)
    //{
       //  throw new MyException("DeqList<T>::pop_back: size <= 0\n", EC_SIZE);
    //}
    
}

template <typename T>
void DeqList<T>::copy(DeqList<T>::ListNode* S, DeqList<T>::ListNode* O) {
    S->value = O->value;
    
}


template <typename T>
void DeqList<T>::swap(DeqList<T>::ListNode* First, DeqList<T>::ListNode* Second) {
    DeqList<T>::ListNode* temp = new ListNode(0, NULL, NULL);
    
    copy(temp, First);
    copy(First, Second);
    copy(Second, temp);
    delete temp;
}


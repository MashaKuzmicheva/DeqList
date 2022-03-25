
#include <iostream>
#include<string>
#include "Header.h"
#include <cmath>

#define Pi 3.14159265358979323846

int main()
{
    try {
        int V = 0;
        double P = 0;
        DeqList<int> a;
        DeqList<double> b;
        DeqList<string> c;
        DeqList<int> d;

        //тесты на добавление, удаление 
        cout << "Adding and removing elements from deck a"s << endl;
        for (int k = 0; k < 10; ++k)
        {
            V = V + 1;
            a.push_front(V);
            a.push_back(V);
        }

        cout << a;

        a.pop_back();
        cout << a;

        a.pop_front();
        cout << a;

        a.pop_front();
        cout << a;

        a.pop_back();
        cout << a;
        cout << endl;

        cout << "Adding and removing elements from deck b(type double)"s << endl;
        for (int k = 0; k < 10; ++k)
        {
            P = sin(P + Pi * Pi);
            b.push_front(P);
            b.push_back(P);
        }
        cout << b;


        for (int k = 0; k < 10; ++k)
        {
            b.pop_front();
            b.pop_back();
        }
        cout << b;
      //  b.pop_back();
      //  cout << b;
        cout << endl;

        cout << "Adding and removing elements from deck b(type string)"s << endl;

        c.push_front("cat"s);
        c.push_front("and"s);
        c.push_front("dog"s);

        c.push_back("eat"s);
        c.push_back("meat"s);

        cout << c;

        c.pop_front();
        c.pop_front();

        c.pop_back();
        cout << c;
        cout << endl;

        cout << "Adding and removing elements from deck d"s << endl;
        for (int k = 0; k < 100; ++k)
        {
            d.push_front(k);

        }
        Iterator<int> j = d.begin();

        //cout << endl;
        bool flag = true;

        for (j = d.begin(); j != d.end(); (++j)) {
            if (flag == true)
            {
                flag = false;
                *j *= 10;
            }
            else
            {
                flag = true;
                *j *= 2;
            }
        }



        // *j *= 10;

        cout << d;
        d.pop_front();


        cout << d;
        cout << endl;

        cout << "Deck in deck"s << endl;

        DeqList<DeqList<int>> A;
        DeqList<int> t, t1, t2;
        A.push_back(t);
        A.push_back(t1);
        A.push_back(t2);
        Iterator<DeqList<int>> i3;
        for (i3 = A.begin(); i3 != A.end(); ++i3) {
            for (int k = 1; k <= 10; ++k) {
                (*i3).push_back(k);
            }

        }
        i3 = A.end();
        for (int k = 1; k <= 10; ++k) {
            (*i3).push_back(k);
        }

        cout << A;
        cout << endl;


        cout << "Deck in deck"s << endl;

        DeqList<DeqList<int>> A1;
        DeqList<int> o, o1, o2;
        A1.push_back(o);
        A1.push_back(o1);
        A1.push_back(o2);
        Iterator<DeqList<int>> i4;
        int s = 15;
        for (i4 = A1.begin(); i4 != A1.end(); ++i4) {
            for (int k = 1; k <= s; ++k) {
                (*i4).push_back(k);
            }
            ++s;
        }
        i3 = A1.end();
        for (int k = 1; k <= s; ++k) {
            (*i3).push_back(k);
        }

        cout << A1;
        cout << endl;

      //  DeqList<int> H;
       // i4 = A1.begin();
      //   H = *i4;
      //  H.push_front(100);
      //  cout << H;
     //   cout << *i4;
        //return 0;
    }
    catch (MyException* e) {
        //throw new MyException ("DList<T>::DelFirst: size error\n", EC_SIZE);
        cout << e->Message();
        //return 0;
    }
    return 0;
   
}

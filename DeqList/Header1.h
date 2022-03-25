#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string.h>
using namespace std;


class MyException
{
    char message[256];
    int code;
public:
    MyException(const char* msg, int c) {
        code = c;
        strncpy_s(message, msg, 255);
       // cout << message;
        //const char* Message() const { return message; }
    }
    const char* Message() const { return message; }
    int Code() { return code; }
};


enum ErrorCodes
{
    EC_UNKNOWN = 0,
    EC_MEMORY = -1,
    EC_INDEX = -2,
    EC_ACCESS = -3,
    EC_SIZE = -4
};

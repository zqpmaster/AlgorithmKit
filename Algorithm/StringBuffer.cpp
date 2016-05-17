//
//  StringBuffer.cpp
//  CppTest
//
//  Created by ZQP on 14-9-24.
//  Copyright (c) 2014年 ZQP. All rights reserved.
//

#include "StringBuffer.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;


class StringBuffer {
public:
    StringBuffer(){
        
    }
    char *stringBuffer=new char[5];
    int logicLength=0;
    int allocLength=5;
    void append(char x){
        if (logicLength==allocLength) {
            char *temp=new char[allocLength*2];
            for (int i=0; i<logicLength; i++) {
                temp[i]=stringBuffer[i];
            }
            allocLength*=2;
            stringBuffer=temp;
            delete [] temp;
        }
        stringBuffer[logicLength]=x;
        logicLength++;
    }
    string toString(){
        string temp=stringBuffer;
        return temp;
    }
};


void testBuffer()
{
    
    
    char * query = "aaaaa";
    char * test = "calccbabb";
    
    StringBuffer *buffer=new StringBuffer;
    for (int i=0; i<5; i++) {
        buffer->append(query[i]);
    }
    for (int i=0; i<9; i++) {
        buffer->append(test[i]);
    }
    
    cout<<"组合字符串是"<<buffer->toString()<<endl;
}

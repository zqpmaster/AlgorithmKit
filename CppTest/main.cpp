//
//  main.cpp
//  CppTest
//
//  Created by ZQP on 14-5-26.
//  Copyright (c) 2014年 ZQP. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "Recursion.h"

#include "SubStringOfAli.h"

using namespace std;

int main(int argc, const char * argv[])
{
    
    
    char * query="KLccb";
    char * test="calccbabb";
//    int length=queryTest(test,query);
    
//    printf("%d",length);
    
    queryText(test, query);
    
    return 0;
    
}



void prt(int n);
void quick_sort (int data[], size_t left,
                 size_t right);
int a[]= { 1, 2, 8, 7, 9, 5, 6, 4, 3, 66, 77, 33, 22, 11 };


int queryTest(char *test,char *query){
    
    
    int length=0;
    int longLength=0;
    bool saming=true;
    int j=0;
    
    for (int i=0;i<sizeof(test) ; i++) {

        char x=test[i];
        
        for (; j<sizeof(query); j++) {
            char z=query[j];
            if(x==z){
                saming=true;
                length++;
                j++;
                break;//保存j
            }else{
                if (saming) {
                    if (length>longLength) {
                        longLength=length;

                    }
                    length=0;
                    saming=false;
                    j=0;
                }
            }
        }
        
    }
    return longLength;
}











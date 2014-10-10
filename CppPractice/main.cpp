//
//  main.cpp
//  CppTest
//
//  Created by ZQP on 14-5-26.
//  Copyright (c) 2014年 ZQP. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <cassert>

#include "Recursion.h"
#include "StringBuffer.h"
#include "SubStringOfAli.h"
#include "XiaoMiWrittenQuestion.h"

using namespace std;


void testList();
int main(int argc, const char * argv[])
{
    
    
    char * query="aaaaa";
    char * test="calccbabb";
    
//    int length=queryTest(test,query);
    
//    printf("%d",length);

//    queryText(test, query);
    testList();
    
    xiaomi *mi=new xiaomi();
    if(mi->huiWenChuan(12)){
        assert(false);
    }
    
    
    return 0;
    
}


struct ListNode {
    int num;
    ListNode *next;
    
};

void testList(){
    
    
//    ListNode *node = new ListNode();
//    ListNode *header=node;
//    for (int i=0; i<5; i++) {
//        node->next=new ListNode();
//        node->num=i;
//        node=node->next;
//    }
    
    int i=0;
    ListNode *node=new ListNode();
    node->num=i;
    ListNode *header=node;
    while (i!=5) {
        node->next=new ListNode();
        node=node->next;
        i++;
        node->num=i;
    }
    
    
    node=header;
    while (node) {
        cout<<node->num<<endl;
        node=node->next;
    }
    
//    do {
//        cout<<node->num<<"list"<<endl;
//        node=node->next;
//    } while (node);
    
}



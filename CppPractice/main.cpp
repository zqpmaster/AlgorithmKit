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

#define HashSize 101
struct    nlist{
    struct    nlist    *next;
    string    key;
    string    value;
};
static vector<nlist*> hashTabel;
void initHashTable();
int hashValue(string key);
nlist* getStr(string key);
void set(string key,string value);
void setAll(string value);


void initHashTable(){
    for (int i=0; i<HashSize; i++) {
        hashTabel[i]=nullptr;
    }
}
int hashValue(string key){
    hash<std::string> hash_fn;
    size_t hash = hash_fn(key);
    return hash%HashSize;
}
nlist* getStr(string key){
    int hash=hashValue(key);
    nlist *nl=hashTabel[hash];
    for (; nl!=nullptr; nl=nl->next) {
        if (key==nl->key) {
            return nl;
        }
    }
    return nullptr;
}
void set(string key,string value){
    unsigned int hash=0;
    nlist* nl;
    if ((nl=getStr(key))==nullptr) {
        hash=hashValue(key);
        nl=new nlist();
        nl->key=key;
        nl->value=value;
        nl->next=hashTabel[hash];
        hashTabel[hash]=nl;
    }else{
        nl->value=value;
    }
}

void setAll(string value){
    vector<nlist*>::iterator iter=hashTabel.begin();
    while (iter!=hashTabel.end()) {
        nlist *nl=*iter;
        if (!nl) continue;
        while (nl!=nullptr) {
            nl->value=value;
            nl=nl->next;
        }
        iter++;
    }
}

int KindOfSeperateRMB(int num){
    int fen100=num/100;
    num=num%100;
    int fen50=num/50;
    num=num%50;
    int fen20=num/20;
    num=num%20;
    int fen10=num/10;
    num=num%10;
    int fen5=num/5;
    num=num%5;
    int fen2=num/2;
    num=num%2;
    int fen1=num/1;
    
    int numOfKinds=fen100*102010*102010*fen50*102010*fen20*101*fen10*10*fen5*3*fen2*2*fen1;
    return numOfKinds;
}




void testList();
int main(int argc, const char * argv[])
{
    
    
//    char * query="aaaaa";
//    char * test="calccbabb";
    
//    int length=queryTest(test,query);
    
//    printf("%d",length);

//    queryText(test, query);
//    testList();
//    
//    xiaomi *mi=new xiaomi();
//    if(mi->huiWenChuan(12)){
//        assert(false);
//    }
    
    int num=KindOfSeperateRMB(51);
    cout<<num<<endl;
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



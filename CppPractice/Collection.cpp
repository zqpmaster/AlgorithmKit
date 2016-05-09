//
//  Collection.cpp
//  Algorithm
//
//  Created by ZQP on 16/5/9.
//  Copyright © 2016年 ZQP. All rights reserved.
//

#include "Collection.hpp"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <cassert>
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



void testList();


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

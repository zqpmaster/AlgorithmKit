//
//  Recursion.cpp
//  CppTest
//
//  Created by ZQP on 14-6-23.
//  Copyright (c) 2014年 ZQP. All rights reserved.
//

#include "Recursion.h"
#include "String.h"

void recPermute(string sofar,string rest){
    if (rest=="") {
        cout<<sofar<<endl;
    }else{
        for (size_t i=0; i<rest.size(); i++) {
            string next=sofar+rest[i];
            string remaing=rest.substr(0,i)+rest.substr(i+1);
            recPermute(next, remaing);
        }
    }
}

void Recursion::testPermute(string testStr){
    recPermute("",testStr);
}

void recSubsets(string sofar,string rest){
    
    if (rest=="") {
        cout<<sofar<<endl;
    }else{
        recSubsets(sofar+rest[0],rest.substr(1));
        recSubsets(sofar,rest.substr(1));
    }
}

void Recursion::testSubsets(string testStr){
    recSubsets("", testStr);
}



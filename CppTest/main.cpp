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

using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    cout << "Hello, World!\n";
    vector<int> vecInts;
    vecInts.push_back(440);
    vecInts.push_back(111);
    vecInts.push_back(432);
    vecInts.push_back(532);
    vecInts.push_back(261);
    vecInts.push_back(277);

    sort(vecInts.begin(),vecInts.end());

    for (vector<int>::iterator iter=vecInts.begin(); iter!=vecInts.end(); iter++) {
        cout<<*iter<<endl;
    }
    
    Recursion *recursio=new Recursion();
    
    printf("//递归全排序//\n");
    recursio->testPermute("test");//递归全排序
    
    printf("//递归子集//\n");
    recursio->testSubsets("test");//递归子集
    

    return 0;

}

void testString(){
    string str="yaaaa";
    str.substr(0);
}
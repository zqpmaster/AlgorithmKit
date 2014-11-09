//
//  XiaoMiWrittenQuestion.cpp
//  CppPractice
//
//  Created by ZQP on 14-10-10.
//  Copyright (c) 2014年 ZQP. All rights reserved.
//

#include "XiaoMiWrittenQuestion.h"
#include <string>
using namespace std;

bool huiWenChuanWithStream(int num){
//    stringstream stream;
//    stream <<num;
    return false;
    
}


bool xiaomi::huiWenChuan(int num){
    char *buf=new char();
    sprintf(buf, "%d",num);
    string strBuf=buf;
    size_t length=strBuf.length();
    for(int i=0;i<length;i++){
        if(strBuf[i]!=strBuf[length-1-i]){
            return false;
        }
    }
    return true;
}
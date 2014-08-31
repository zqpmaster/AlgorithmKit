//
//  SubStringOfAli.cpp
//  CppTest
//
//  Created by ZQP on 14-8-31.
//  Copyright (c) 2014年 ZQP. All rights reserved.
//

#include "SubStringOfAli.h"

static char *text;
static int longLength=0;

void queryText(char *text,char *query){
    
    ::text=text;
    subStringOfTest(query);
    
    printf("%d",longLength);
    
    
}

void updatetheMaxLength(int length){
    if(length>longLength){
        longLength=length;
    }
}

void isTheTextContainQuery( char * query){
    
    if(sizeof(query)>sizeof(text)) return;
    
    string textS=text;
    string queryS=query;
    for(int i=0;i<sizeof(text);i++){
    
        if(text[i]==query[0]){
            for(int j=0;j<sizeof(query);j++){
                if(text[i+j]!=query[j]){
                    break;
                }
                if(j==sizeof(query)-1){
                    updatetheMaxLength(++j);
                }
            }
        }
        
    }

}
void subString(string text,string rest){
    
    char* textOtherConst=const_cast<char *>(text.c_str());
    
    isTheTextContainQuery(textOtherConst);
    
    if (rest.length()<=0) {
        return;
    }
    
    text=text+rest[0];
    
    //    printf("%s",text.c_str());
    
    rest=rest.substr(1);
    
    subString(text,rest);
    
    
    
}

void subStringOfTest(string text){
    
    for (size_t i=0; i<text.length(); i++) {
        
        string rest=text.substr(i+1);
        
        string chaSt=text.substr(i,1);
        
        subString(chaSt,rest);
    }
}


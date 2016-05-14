//
//  SubStringOfAli.c
//  CppTest
//
//  Created by ZQP on 14-8-31.
//  Copyright (c) 2014年 ZQP. All rights reserved.
//

#include <stdio.h>

struct node {
    struct node * left;
    struct node * right;
    int  number;
};

static int maxNumber=0;
void maxNumberInTree(struct node *node){
    
    if (node==NULL) {
        return;
    }
    
    int number=node->number;
    if (number>maxNumber) {
        maxNumber=number;
    }
    
    maxNumberInTree(node->left);
    maxNumberInTree(node->right);
    
    
}

static int minNumber=0;
void minNumberInTree(struct node *node){
    
    if (node==NULL) {
        return;
    }
    
    int number=node->number;
    if (number<minNumber) {
        minNumber=number;
    }
    
    minNumberInTree(node->left);
    minNumberInTree(node->right);
    
}

int printTheMaxDistinct(struct node* root){
    maxNumber=0;
    minNumber=0;
    
    maxNumberInTree(root);
    minNumberInTree(root);
    
    int theMaxAbsoultValue=maxNumber-minNumber;
    
    printf("最大值为%d", theMaxAbsoultValue);
    
    return 0;
}

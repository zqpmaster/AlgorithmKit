//
//  BinarySearchTree.hpp
//  Algorithm
//
//  Created by ZQP on 16/5/14.
//  Copyright © 2016年 ZQP. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>

typedef int ValueType;
struct Node
{
    ValueType value;
    Node *leftNode;
    Node *rightNode;
};

//TODO test

//搜索
bool searchBST(Node *root, ValueType value, Node **node);
//删除
bool deleteBST(Node *root, ValueType value);
//增加
bool addBST(Node *root, ValueType value);

//二叉树遍历
void traverseBST(Node *root, void function(ValueType));

//反转二叉树
void reverseBST(Node *root);

#endif /* BinarySearchTree_hpp */

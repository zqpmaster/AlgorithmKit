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

//int searchBST(Node *root, ValueType value);
bool deleteBST(Node *root, ValueType value);//TODO test
//int addBST(Node *root, ValueType value);

#endif /* BinarySearchTree_hpp */

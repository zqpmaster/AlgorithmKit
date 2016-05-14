//
//  BinarySearchTree.cpp
//  Algorithm
//
//  Created by ZQP on 16/5/14.
//  Copyright © 2016年 ZQP. All rights reserved.
//

#include "BinarySearchTree.hpp"

bool _DeleteNode(Node *node)
{
 
    Node *target = node;
    
    if (!target->leftNode && !target->rightNode)
    {
        delete target;
    }else if (!target->leftNode)
    {
        Node *rightNode = target->rightNode;
        target->value = rightNode->value;
        target->leftNode = rightNode->leftNode;
        target->rightNode = rightNode->rightNode;
        
        delete rightNode;
    }else if (!target->rightNode)
    {
        Node *leftNode = target->rightNode;
        target->value = leftNode->value;
        target->leftNode = leftNode->leftNode;
        target->rightNode = leftNode->rightNode;
        
        delete leftNode;
    }else
    {//这里可以取左子树最右边最底层的值或者右子数最左边最底层的值
        //以下是取左边的值
        
        Node *q = target->leftNode;
        Node *r = target;
        
        while (q->rightNode)
        {
            r = q;
            q = q->rightNode;
        }
        
        
        target->value = q->value;
        
        if (r == target)
        {
            r->leftNode = q->leftNode;
        }else
        {
            r->rightNode = q->leftNode;
        }

        delete q;
    }
    
    return true;
}


bool deleteBST(Node *root, ValueType value)
{
    if (!root)
    {
        return false;
    }

    if (root->value == value)
    {
        return _DeleteNode(root);
    }else if (root->value > value)
    {
        return deleteBST(root->leftNode , value);
    }else
    {
        return deleteBST(root->rightNode, value);
    }
}


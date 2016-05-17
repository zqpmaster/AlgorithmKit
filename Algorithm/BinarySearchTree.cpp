//
//  BinarySearchTree.cpp
//  Algorithm
//
//  Created by ZQP on 16/5/14.
//  Copyright © 2016年 ZQP. All rights reserved.
//

#include "BinarySearchTree.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

bool _DeleteNode(Node **node)
{
    if (nullptr == node)
    {
        return false;
    }

    Node *target = *node;
    
    if (nullptr == target)
    {
        return false;
    }

    
    if (!target->leftNode && !target->rightNode)
    {
        delete target;
        *node = nullptr;
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


bool _deleteBST(Node **root, ValueType value)
{
    if (nullptr == root)
    {
        return false;
    }
    
    Node *r = *root;
    if (!r)
    {
        return false;
    }

    if (r->value == value)
    {
        return _DeleteNode(root);
    }else if (r->value > value)
    {
        return _deleteBST(&r->leftNode , value);
    }else
    {
        return _deleteBST(&r->rightNode, value);
    }
}

bool deleteBST(Node *root, ValueType value)
{
    return _deleteBST(&root , value);
}


bool searchBST(Node *root, ValueType value, Node **node)
{
    if (root == nullptr)
    {
        return false;
    }
    
    if (root->value == value)
    {
        *node = root;
        return true;
    }else if (root->value < value)
    {
        return searchBST(root->rightNode, value, node);
    }else
    {
        return searchBST(root->leftNode, value, node);
    }
    
    return false;
}

bool _addBST(Node **root, ValueType value)
{
    if (nullptr == root)
    {
        return false;
    }

    Node *r = *root;
    
    if (nullptr == r)
    {
        Node *node = new Node;
        node->value = value;
        
        *root = node;
        return true;
    }
    
    if (value == r->value)
    {
        return false;
    }else if (r->value > value)
    {
        return _addBST(&r->leftNode, value);
    }else
    {
        return _addBST(&r->rightNode, value);
    }
    
}

bool addBST(Node *root, ValueType value)
{
    return _addBST(&root, value);
}


void traverseBST(Node *root, void function(ValueType))
{
    if (nullptr == root)
    {
        return;
    }
    
    //前序
    function(root->value);
    traverseBST(root->leftNode, function);
    traverseBST(root->rightNode, function);
    
    //中序
    traverseBST(root->leftNode, function);
    function(root->value);
    traverseBST(root->rightNode, function);

    //后序
    traverseBST(root->leftNode, function);
    traverseBST(root->rightNode, function);
    function(root->value);

}

void reverseBST(Node *root)
{
    if (nullptr == root)
    {
        return;
    }
    
    Node *temp = root->leftNode;
    root->leftNode = root->rightNode;
    root->rightNode = temp;
    
    reverseBST(root->leftNode);
    reverseBST(root->rightNode);

}

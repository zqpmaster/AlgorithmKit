//
//  HashMap.c
//  Algorithm
//
//  Created by ZQP on 16/5/26.
//  Copyright © 2016年 ZQP. All rights reserved.
//

#include "HashMap.h"
#include <stdlib.h>

typedef int Value;
typedef char* Key;
typedef unsigned int Hash;


typedef struct Item
{
    Key key;
    Hash hashValue;
    Value value;
    
    struct Item *next;
}Item;


typedef struct HashMap
{
    size_t usege;
    size_t size;
    Item **table;
    
}HashMap;

HashMap * _pushInHead(HashMap *table, Item *item, int index);

HashMap * _pushInList(HashMap *table, Item *item, int index);



void creatTable(size_t size)
{
    HashMap *table = calloc(1, sizeof(HashMap));
    table->size = size;
    table->usege = 0;
    
    table->table = calloc(size, sizeof(Item));
}


Hash hashCode(Key key)
{
    Hash hashCode = 0;
    int offset = 5;
    
    while (*key)
    {
        hashCode = (hashCode << offset) + *key;
        key++;
    }
    
    return hashCode;
}

HashMap * pushTable(HashMap *table, Item *item)
{
    if (item == NULL)
    {
        return table;
    }
    
    Hash hashcode = hashCode(item -> key);
    
    int index = hashcode & (table->size - 1);
    Item *orItem = table->table[index];
    
    if (!orItem)
    {
        //put in head
        return _pushInHead(table, item, index);
    }else
    {
        //put in list
        return _pushInList(table, item, index);
    }
    
    
}

HashMap * _pushInHead(HashMap *table, Item *item, int index)
{
    return table;
}

HashMap * _pushInList(HashMap *table, Item *item, int index)
{
    return table;
}


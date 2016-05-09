//
//  QuickSort.c
//  CppPractice
//
//  Created by ZQP on 16/5/9.
//  Copyright © 2016年 ZQP. All rights reserved.
//

#include "QuickSort.h"


void z_swap(int *a,int *b)
{
    int temp = *a;
    *b = *a;
    *a = temp;
}
size_t z_partition(int *ary, size_t len, size_t pivot_i){
    
    int i=0;
    int small_len=0;
    int pivo=ary[pivot_i];
    z_swap(&ary[pivot_i], &ary[len-1]);
    for(;i<len;i++){
        if(ary[i]<pivo){
            z_swap(&ary[small_len], &ary[i]);
            small_len++;
        }
    }
    z_swap(&ary[small_len], &ary[len-1]);
    return small_len;
}
void z_quick_sort(int *ary ,size_t len){
    if(len==0 || len==1)return;
    size_t small_len=z_partition(ary, len, 0);
    z_quick_sort(ary, small_len);
    z_quick_sort(&ary[small_len+1], len-small_len-1);
}

int test_quick_sort(void)
{
    int ary[] = {2,4,2,5,3,5,3,1,7,6};
    size_t len = sizeof(ary) / sizeof(ary[0]);
    z_quick_sort(ary, len);
    for(int i=0;i<len;i++)
    {
        printf("%d\n",ary[i]);
    }
    return 0;
}
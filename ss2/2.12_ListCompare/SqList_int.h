//
// Created by wang on 17-3-9.
//
////////////////////////////
//用动态数组表示的线性表
////////////////////////////
#ifndef INC_2_11_INSERT_SQLIST_INT_H
#define INC_2_11_INSERT_SQLIST_INT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIST_INIT 10   //初始最大容量
#define INCREASE 5 //每次扩充容量
#define ERROR 0 //错误
#define OK 1    //正确

typedef struct list{
    int * list;//线性表
    int size;//尺寸
    int used;//已用空间
} SqList;

int InitSqlist(SqList * list) ;//顺序表初始化
int EnlargeSqlist(SqList * list);//扩容
int Insert(int i,int elem,SqList *list) ;//在位置i插入元素elem（如果容量不够自动扩容）
void DisplayList(SqList * list);//display顺序表
void RandomList(SqList* list);//生成一个随机数据与容量的线性表（数据按非递减排列）
void CreatTestList(SqList* list);//生成一个元素递增5的等差数列测试用顺序表
void CreatMyList(SqList* list,int myarray[],int array_size);//生成一个我指定的顺序表

#endif //INC_2_11_INSERT_SQLIST_INT_H

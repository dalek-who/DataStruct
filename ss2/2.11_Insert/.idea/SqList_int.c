//
// Created by wang on 17-3-9.
//
#include "SqList_int.h"


/*typedef struct list{
    int * list;//线性表
    int size;//尺寸
    int used;//已用空间
} SqList;
*/
//初始化线性表
int InitSqlist(SqList * list){
    list->list=(int*)malloc(LIST_INIT* sizeof(int));
    if(!list->list)
        exit(ERROR);
    list->size=LIST_INIT;
    list->used=0;
    return OK;
}
//扩容
int EnlargeSqlist(SqList * list){
    int *newbase;
    newbase=(int*)realloc(list->list,(list->size+INCREASE)*sizeof(int));
    if(!newbase)
        exit(ERROR);
    list->list=newbase;
    list->size+=INCREASE;
    return OK;
}

//打印
void DisplayList(SqList * list){
    int i;
    for(i=0;i<list->used;++i) {
        printf("%d\t",i);
        printf("%d\t",list->list[i]);
    }
    printf("\n");
}

//插入
int Insert(int i,int elem,SqList *list) {
    int *p,*q;
    //在错位置插入
    if (i >= list->used || i < 0)
        return ERROR;
    //容量不足则先扩容
    if (list->used + 1 > list->size)
        EnlargeSqlist(list);
    //插入
    p = &(list->list[i]);
    q = &(list->list[list->used - 1]);
    for (; q >= p; --q) {
        *(q + 1) = *q;
    }
    *p = elem;
    return OK;
}

//删除
//int Delete(int i, )
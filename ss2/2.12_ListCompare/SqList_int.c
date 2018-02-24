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
        printf("%d..",i);
        printf("%d\t",list->list[i]);
    }
    printf("\n");
}

//插入
int Insert(int i,int elem,SqList *list) {
    int *p,*q;
    //在错位置插入
    if (i > list->used || i < 0)//i等于used，则是插在尾部
        return ERROR;
    //容量不足则先扩容
    if (list->used + 1 > list->size)
        EnlargeSqlist(list);
    //插入
    if(i==list->used) {//插到表尾
        list->list[list->used] = elem;
        ++list->used;
    } else {//插到不是表尾的位置
        p = &(list->list[i]);
        q = &(list->list[list->used - 1]);
        for (; q >= p; --q) {
            *(q + 1) = *q;
        }
        *p = elem;
        ++list->used;
    }
    return OK;
}
//随机生成一个递增线性表,数据和表长都是随机的
void RandomList(SqList* list){
    int i,size,data;

    srand((unsigned)time(NULL));
    size=rand()%30;
    //初始化
    InitSqlist(list);

    //扩容到相应容量
    while (list->size<size)
        EnlargeSqlist(list);

    //生成随机的递增顺序表
    list->list[0]=rand()%100;
    for(i=1;i<size;++i){
        while((data=rand()%300)<list->list[i-1])
            ;
        list->list[i]=data;
        ++list->used;
    }//for
}

//生成一个有序的test线性表，每两个元素差5
void CreatTestList(SqList* list){
    int i,size,data;

    size=20;
    //初始化
    InitSqlist(list);

    //扩容到相应容量
    while (list->size<size)
        EnlargeSqlist(list);

    //生成随机的递增顺序表
    for(i=0,data=10;i<size;++i){
        list->list[i]=data;
        ++list->used;
        data+=5;
    }//for
}

//生成我指定的顺序表
void CreatMyList(SqList* list,int myarray[],int array_size){
    int* p;
    int i;
    InitSqlist(list);

    //扩容到相应容量
    while (list->size<array_size)
        EnlargeSqlist(list);

    //将指定data导入线性表
    for (i = 0,p=&(list->list[0]); i < array_size; ++i,++p) {
        *p=myarray[i];
    }
    list->used=array_size;
}

//删除
//int Delete(int i, )

//
// Created by wang on 17-3-9.
//
#include "SqList.h"

/*typedef struct list{
    ElemType * list;//线性表
    int size;//尺寸
    int used;//已用空间
} SqList;
*/
/////////////////////////////////////////////////////////////////
//初始化线性表
int InitSqlist(SqList * list){
    list->list=(ElemType*)malloc(LIST_INIT* sizeof(ElemType));
    if(!list->list)
        exit(ERROR);
    list->size=LIST_INIT;
    list->used=0;
    return OK;
}
/////////////////////////////////////////////////////////////////
//扩容
int EnlargeSqlist(SqList * list){
    ElemType *newbase;
    newbase=(ElemType*)realloc(list->list,(list->size+INCREASE)*sizeof(ElemType));
    if(!newbase)
        exit(ERROR);
    list->list=newbase;
    list->size+=INCREASE;
    return OK;
}
/////////////////////////////////////////////////////////////////
//打印
void DisplayList(SqList * list){
    int i;
    for(i=0;i<list->used;++i) {
        printf("%d..",i);
        printf("%d\t",list->list[i]);
    }
    printf("\n");
}
/////////////////////////////////////////////////////////////////
//在位置i插入
int Insert(int i,ElemType elem,SqList *list) {
    ElemType *p,*q;
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
/////////////////////////////////////////////////////////////////
//在表尾插入
void TailInsert(ElemType elem,SqList *list){
    //容量不足则先扩容
    if (list->used + 1 > list->size)
        EnlargeSqlist(list);
    //插入
    list->list[list->used] = elem;
    ++list->used;
}
/////////////////////////////////////////////////////////////////
/*
//随机生成一个递增线性表,数据和表长都是随机的
void RandomList(SqList* list){
    int i,size,data;

    srand((unsigned)time(NULL)+rand()+rand());//加两个rand。否则在同时生成多个随机数时，生成的是一样的
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
 */
/////////////////////////////////////////////////////////////////
/*
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
 */
/////////////////////////////////////////////////////////////////
//生成我指定的顺序表
void CreatMyList(SqList* list,ElemType myarray[],int array_size){
    ElemType* p;
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
///////////////////////////////////////////////////////////////////////////////

//在有序线性表中实现二分查找
int BinSearch(ElemType x, ElemType a[], int size){
    int min,max,mid;
    min=0,max=size-1,mid=(min+max)/2;
    //查找
    while (x!=a[mid] && max>min){
        if(x>a[mid])
            min=mid+1;
        else
            max=mid;
        mid=(max+min)/2;
    }

    //由于/是向下取整，所以如果做到mid==max这一步而依然x！=a[mid],那么x就在mid左边，否则x就比最大的数还大
    if(x==a[mid])
        return mid;//匹配到

    ///////////////////////////////////////
    /// 未匹配到的情况，返回值有如下两种模式供选择
    /////////////////////////////////////

        //模式1：
        // 返回UNFIND（-1）
        /////////////////
    else
        return UNFIND;//未找到
    ////////////

        //模式2
        // 返回第一个比x大的数的角标。如果x比最大的数还大，则返回size（最大角标是size-1）
        ////////////
    /*
    else if(max<=min && x<a[min])
        return min;//未匹配到，但是有比x大的
    else if(x>a[size-1])//未匹配到，且x比最大的还大
        return size;//返回size而不是size+1，因为原本的a[size]位置没有元素
    else {
        printf("二分查找出现未考虑的情况，请检查最后的if-else\n");
        return 0;
    }
    */
}
/////////////////////////////////////////////////////////////////////////////////////
//删除
//int Delete(int i, )

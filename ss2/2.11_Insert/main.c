#include <stdio.h>
#include "SqList_int.h"
//将元素插入有序的线性表中，main函数

int BinSearch(int x, int a[], int size);
void OrderingInsert(int x,SqList *list);


int main() {
 //   printf("Hello, World!\n");
    int elem;
    SqList list;
    printf("please input element ");scanf("%d",&elem);

    //随机生成线性表的数据（随机但是有序）
//    RandomList(&list);

    //生成测试线性表
    CreatTestList(&list);

    //生成某个指定的顺序表
 //   CreatMyList(&list);

    //打印线性表
    printf("old list: ");DisplayList(&list);
    //插入元素elem
    OrderingInsert(elem,&list);
    //打印线性表
    printf("new list: ");DisplayList(&list);
    return 0;
}

//最后返回的是等于x的角标，或者第一个比x大的数的角标，或者如果x比最大的数还则返回size+1
//x:被查找的数 size:数组尺寸
int BinSearch(int x, int a[], int size){
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
    else if(max<=min && x<a[min])
        return min;//未匹配到，但是有比x大的
    else if(x>a[size-1])//未匹配到，且x比最大的还大
        return size;//返回size而不是size+1，因为原本的a[size]位置没有元素
    else {
        printf("二分查找出现未考虑的情况，请检查最后的if-else\n");
        return 0;
    }
}


//将元素插入有序的顺序表中.容量不足的扩容已经在Insert函数中解决了
void OrderingInsert(int x,SqList *list){
    int index;
    index=BinSearch(x,list->list,list->used);
    Insert(index,x,list);
}

















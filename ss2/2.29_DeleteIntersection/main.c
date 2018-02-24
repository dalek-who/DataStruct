#include <stdio.h>
#include "SqList_int.h"

//删去递增的顺序表A、B中相同的元素，将剩余的元素按递增顺序放入新的顺序表C
void DeleteIntersection(SqList* Newlist,SqList* list_A,SqList* list_B) {
    int *pA = list_A->list,
            *pB = list_B->list;
    int searchedA=0,
        searchedB=0;

    //A,B不空
    //while (pA <= &list_A->list[list_A->used - 1]
    //       && pB <= &list_B->list[list_B->used - 1]) {
    while (     searchedA < list_A->used
            &&  searchedB < list_B->used ){
        //值相等，跳过
        if (*pA == *pB) {
            ++pA;++searchedA;
            ++pB;++searchedB;
        }//if

            //值不等
        else if (*pA < *pB) {
            if ((BinSearch(*pA, list_B->list, list_B->used)) == UNFIND) {//将*pA插入NewList
                TailInsert(*pA, Newlist);
                ++pA;++searchedA;
            }//if
            else
                ++pA,++searchedA;
        }//else if

        else if (*pA > *pB) {
            if ((BinSearch(*pB, list_A->list, list_A->used)) == UNFIND) {//将*pB插入NewList
                TailInsert(*pB, Newlist);
                ++pB;++searchedB;
            }//if
            else
                ++pB,++searchedB;
        }//else if

    }//while

    //一个表空了
    //if (pA > &list_A->list[list_A->used - 1]) {//A空了
      //  while (pB <= &list_B->list[list_B->used - 1]) {
    if (searchedA >= list_A->used) {//A空了
        while ( searchedB < list_B->used ) {
            if ((BinSearch(*pB, list_A->list, list_A->used)) == UNFIND) {//将*pB插入NewList
                TailInsert(*pB, Newlist);
                ++pB;++searchedB;
            }//if
            else
                ++pB,++searchedB;
        }
    }//if
 //   else if (pB > &list_B->list[list_B->used - 1]) {//B空了
   //     while (pA <= &list_A->list[list_A->used - 1]) {
    else if (searchedB >= list_B->used) {//A空了
        while ( searchedA < list_A->used ) {

            if ((BinSearch(*pA, list_B->list, list_B->used)) == UNFIND) {//将*pA插入NewList
                TailInsert(*pA, Newlist);
                ++pA;++searchedA;
            }//if
            else
                ++pA,++searchedA;
        }//while
    }//else if


}

int main() {
    //printf("Hello, World!\n");
    SqList listA,listB,listC;
    int a[]={1,2,3,4,5},
        b[]={1,2,3,4,5};

    InitSqlist(&listC);

    //创建测试用顺序表A，B
    //InitSqlist(&listA);//创建空表测试
    CreatMyList(&listA,a,sizeof(a)/sizeof(int));CreatMyList(&listB,b,sizeof(b)/sizeof(int));//创建指定测试顺序表
    //RandomList(&listA);RandomList(&listB);//创建数据随机的递增顺序表

    printf("A:  ");DisplayList(&listA);
    printf("B:  ");DisplayList(&listB);

    //去掉A，B中相交的元素，得到C
    DeleteIntersection(&listC,&listA,&listB);
    printf("C:  ");DisplayList(&listC);

    return 0;
}
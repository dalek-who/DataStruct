#include <stdio.h>
#include "SqList_int.h"
#define EMPTY 0     //空
#define UNEMPTY 1   //非空

//比较两个顺序表的大小
//返回值result，若A>B,result=1; A==B,result=0; A<B,result==-1
int CompareList(SqList * listA,SqList * listB){
    int *pa,*pb,*qa_last,*qb_last;
    int a_,b_,result;
    //ListA/B的尾节点
    qa_last=&(listA->list[listA->used-1]);
    qb_last=&(listB->list[listB->used-1]);

    pa=listA->list;
    pb=listB->list;

    //判空
    for(    ;
            *pa==*pb && pa!=qa_last && pb!=qb_last;
            ++pa,++pb)
        ;

        //A`，B`都不空
    if      (*pa!=*pb)
        a_=b_=UNEMPTY;
        //A`,B`都空
    else if (*pa==*pb && pa==qa_last && pb==qb_last)
        a_=b_=EMPTY;
        //A`空，B`不空
    else if (*pa==*pb && pa==qa_last && pb!=qb_last)
        a_=EMPTY,b_=UNEMPTY;
        //A`不空，B`空
    else if (*pa==*pb && pb==qb_last && pa!=qa_last)
        a_=UNEMPTY,b_=EMPTY;


    //比较大小
    if(a_==EMPTY && b_==EMPTY)
        result=0;//A==B
    else if(       (a_!=EMPTY && b_==EMPTY)
                || (a_!=EMPTY && b_!=EMPTY && *pa>*pb)
            )
        result=1;//A>B
    else if(       (a_==EMPTY && b_!=EMPTY)
                || (a_!=EMPTY && b_!=EMPTY && *pa<*pb)
            )
        result=-1;//A>B
    else{
        printf("比较大小出现未考虑的情况，请检查");
        result=0;
    }
    return result;

}

int main() {
  //  printf("Hello, World!\n");
    //test数据
    int A[]={1,2,3,4,5},
        B[]={1,2,3,4,5};
    int result;
    SqList listA,listB;

    //创建两个顺序表，数据为我上面指定的两组test数据
    CreatMyList(&listA,A,5);
    CreatMyList(&listB,B,5);

    //打印两个顺序表
    DisplayList(&listA);
    DisplayList(&listB);

    //比较
    result=CompareList(&listA,&listB);

    //输出结果
    if(result==0)
        printf("A==B\n");
    else if (result>0)
        printf("A>B\n");
    else
        printf("A<B\n");

    return 0;
}
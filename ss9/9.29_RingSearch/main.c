//#include <stdio.h>
#include "LinkList.h"

//数据结构：环形查找链表
typedef struct RingSearchList{
    //单向循环链表。链表中的元素升序排列，并且最后要成环（tail->next指向head->next）
    // 头结点只是为了在制造链表时方便操作
    LinkList list;
    Node *h,*t;// 两个指针，h指向key最小的元素，t指向上次查找后最后指向的位置
}RingSearchList;



//初始化环形查找表
RingSearchList InitRing(){
    RingSearchList ring;
    InitLinkList(&ring.list);
    ring.h=NULL;
    ring.t=NULL;
    return ring;
}
/////////////////////////////////////////////////////////////////////////////////////

//创建环形查找链表
//默认DataArray[]中的元素已经按照升序排列排好序了
RingSearchList CreatRing(int NodeNumber,ElemType DataArray[]){

    //初始化
    RingSearchList ring;
    ring = InitRing();

    //插入元素
    for (int i = 0; i < NodeNumber; ++i)
        TailInsertNode(&ring.list,DataArray[i]);

    //成环
    ring.list.tail->next = ring.list.head->next;

    //h,t指针
    ring.h = ring.t = ring.list.head->next;

    return ring;
}

/////////////////////////////////////////////////////////////////////////////////////
//打印环
void DisplayRing(RingSearchList ring){
    Node *p;
    int FinishRing=0;
    for(p=ring.list.head->next;p!=NULL && !FinishRing; ){
        printf("%d ",p->data);

        p=p->next;
        if(p == ring.list.head->next)
            FinishRing = 1;
    }
}
/////////////////////////////////////////////////////////////////////////////////////
//在环中搜索
void SearchRing(RingSearchList *ring,ElemType key){
    static int flag1=0,flag2=0;

    printf("%s",(flag1 == 0)?"":"\n");
    flag1=1;

    //t->data == key
    if(ring->t->data == key) {
        printf("%s%d",(flag2 == 0)?"":" ",ring->t->data);
        flag2 = 1;
    }

    //t->data < key
    else if(ring->t->data < key){
     //从t开始向后搜索
        //搜索停止：1.t->data == key：搜索到
        //          2.t->data > key:  未搜索到
        //          3.t==h：回到起点依然没找到
        //          (这种情况不会有t->data > key，因为如果最终到达t==h，意味着key比最大的值还要大）

        //先判断t一开始是不是在h。因为需要区别是t重新回到h还是一开始就在h
        int restart = 0;
        for( ; !restart && ring->t->data<key ; ){
            printf("%s%d",(flag2 == 0)?"":" ",ring->t->data);
            flag2 = 1;

            ring->t = ring->t->next;
            restart = (ring->t == ring->h)?1:0;
        }

        printf("%s%d",(flag2 == 0)?"":" ",ring->t->data);
        flag2 = 1;
    }


    //t->data > key
    else{
        //从h开始向后搜索
        //搜索停止：1.t->data == key：搜索到
        //          2.t->data >  key：回到起点依然没找到
        printf("%s%d",(flag2 == 0)?"":" ",ring->t->data);
        flag2 = 1;

        for( ring->t = ring->h ; ring->t->data<key ; ring->t = ring->t->next){
            printf("%s%d",(flag2 == 0)?"":" ",ring->t->data);
            flag2 = 1;
        }

        printf("%s%d",(flag2 == 0)?"":" ",ring->t->data);
        flag2 = 1;
    }

    flag2 = 0;
    return;
}

/////////////////////////////////////////////////////////////////////////////////////
int main() {
   // printf("Hello, World!\n");

    //oj输入
    //数据的数量
    int DataNumber; scanf("%d",&DataNumber);
    //数据
    ElemType DataArray[DataNumber];
    for (int i = 0; i <DataNumber ; ++i)
        scanf(" %d",&DataArray[i]);
    //操作的数量
    int OpreationNumber; scanf("%d",&OpreationNumber);
    //查找的关键词key
    ElemType key[OpreationNumber];
    for (int j = 0; j <OpreationNumber ; ++j)
        scanf(" %d",&key[j]);

    //创建环
    RingSearchList ring;
    ring = CreatRing(DataNumber,DataArray);

  //  DisplayRing(ring);
    for (int k = 0; k <OpreationNumber ; ++k) {
    //    char next;scanf("%c",&next);
        SearchRing(&ring,key[k]);
    }

    return 0;
}
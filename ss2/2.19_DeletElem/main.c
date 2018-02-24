#include <stdio.h>
#include "LinkList_int.h"

//删去data大于mink，小于maxk的节点
void DeleteSubLineLink(LinkList* list, int mink, int maxk){
    Node* p=NULL;

    //不需要操作，直接返回
    if (mink>=maxk)
        return;

    //跳过前面的不是介于mink与maxk之间的结点
    for(p=list->head;
        p->next->data<=mink || p->next->data >=maxk;
            p=p->next)
        ;

    //删去介于mink与maxk之间的结点
    //p一直是不变的，mink左边的第一个结点
    for(; p->next!=NULL  &&  p->next->data > mink  &&  p->next->data < maxk ; )
        DeleteNextNode(list,p);
}

int main() {
//    printf("Hello, World!\n");
    LinkList listA;
    int mink,maxk;

    //创建listA
    CreatTestLinkList(&listA);
    //打印链表
    DisplayLinkList(&listA);

    //输入mink，maxk
    printf("please input mink "); scanf("%d",&mink);
    printf("please input maxk "); scanf("%d",&maxk);

    //删去data大于mink，小于maxk的节点
    DeleteSubLineLink(&listA,mink,maxk);
    //打印链表
    DisplayLinkList(&listA);

    return 0;
}
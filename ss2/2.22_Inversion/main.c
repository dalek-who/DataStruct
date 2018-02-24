#include <stdio.h>
#include "LinkList_int.h"

//将链表就地逆置
//用递归的方式写。
//先将所有节点逆置
void InversionAllNode(Node* pnode){
    static int i=1;//用来在debug时观察当前的递归层数
    int now_deep=i;
    ++i;//每进入一次，层数都加1

    //如果next不是null，则递归，否则返回
    if(pnode->next!=NULL) {
        InversionAllNode(pnode->next);
    }
    else
        return;
    //先从头一层层递归到尾，再从尾到头在每一层p->next->=p,从尾到头一层层操作并退出，最终就能实现将所有节点逆置
    pnode->next->next=pnode;
    return;
}
//逆置节点后，重新设置头尾节点，从而将链表逆置
void InversionLinkList(LinkList *list){
    Node *old_tail=list->tail,*p=NULL;


    //如果是空链表
    if (list->head==list->tail)
        return;

    //如果不是空链表
    //先用递归将所有结点逆置
    InversionAllNode(list->head->next);

    //重新设置逆置后的头尾节点
    list->tail=list->head->next;
    list->tail->next=NULL;
    list->head->next=old_tail;
}

int main() {
    //printf("Hello, World!\n");

    LinkList listA;

    //创建链表
    CreatTestLinkList(&listA);//等差数列测试用链表
    //RandomLinkList(&listA);//随机递增数列测试链表
   // InitLinkList(&listA);//测试用空链表
    DisplayLinkList(&listA);
    //逆置
    InversionLinkList(&listA);
    DisplayLinkList(&listA);


    return 0;
}
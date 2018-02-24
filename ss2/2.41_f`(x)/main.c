#include <stdio.h>
#include "LinkList.h"

//将普通链表尾节点的next指向head->next，形成循环链表
void RingLinkList(LinkList* list){
    list->tail->next=list->head->next;
}

//删去环形链表的头结点的下一个节点（第一个数据节点）
void Ring_DeleteFirst(LinkList * list){
    Node *p=list->head->next;
    if(IsEmptyList(list))
        return;
        //第一个节点不是tail，则删去第一个节点，把tail->next指向第一个节点
    else if(list->tail!=list->head->next){
        list->tail->next=p->next;
        list->head->next=p->next;
        FreeNode(p);
        --list->len;
    } 
    else{
        //第一个节点是尾节点（即当前只有一个数据节点），则尾指针回到head，释放第一个节点
        list->tail=list->head;
        FreeNode(p);
        list->head->next=NULL;
        --list->len;
    }
}

//创建多项式（先创建为普通链表，最后一步连成循环链表
//head->next次数最低，tail次数最高
void CreatPolynomial(LinkList * Polynomial){
    int n,i;
    Monomial monomial;
    //初始化
    InitLinkList(Polynomial);
    printf("input max n:");scanf("%d",&n);
    //创建多项式
    for ( i = 0; i <= n; ) {
        printf("  次数： ");scanf("%d",&(monomial.n));
        if(monomial.n>n) {
            printf("more than max n\n");
            exit(ERROR);
        }
        i=monomial.n;
        printf("%d次系数： ",i);scanf("%d",&(monomial.a));
        TailInsertNode(Polynomial,monomial);

        //到达n次
        if(monomial.n==n)
            break;
    }
    //将普通链表变成循环链表
    RingLinkList(Polynomial);
}

//求导
void dfx(LinkList* Polynomial){
    Node *p=Polynomial->head->next;
    Monomial monomial;

    if(!IsEmptyList(Polynomial)) {
        //用do while是因为一开始p就是head->next，用while就不执行了
        do {
            p->data.a=p->data.a*p->data.n;
            --p->data.n;
            p=p->next;
        } while(p!=Polynomial->head->next);

        //如果第一个数据节点变为0，则删去
        if(Polynomial->head->next->data.a==0){
            Ring_DeleteFirst(Polynomial);
        }//if
    }//if
    //空多项式置0
    if(IsEmptyList(Polynomial)){
        monomial.n=0;
        monomial.a=0;
        TailInsertNode(Polynomial,monomial);
        ++Polynomial->len;
        RingLinkList(Polynomial);//把链表重新成环
    }
}

void DisplayPolynomial(LinkList* Polynomial){
    Node *p=Polynomial->head->next;
    do{
        printf("次数：%d\t",p->data.n);
        p=p->next;
    }while (p!=Polynomial->head->next);
    printf("\n");
    do{
        printf("系数：%d\t",p->data.a);
        p=p->next;
    }while (p!=Polynomial->head->next);
}


int main() {
    //printf("Hello, World!\n");
    LinkList Polynomial;
    //创建多项式
    CreatPolynomial(&Polynomial);
    //求导
    dfx(&Polynomial);
    //输出结果
    DisplayPolynomial(&Polynomial);
    return 0;
}
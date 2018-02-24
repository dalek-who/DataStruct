//
// Created by wang on 17-3-11.
//
#include "LinkList_int.h"

/*
 * //定义结构
//结点的结构
typedef struct node{
    int data;           //存储的数据
    struct node* next;  //指向下一节点的指针
} Node;

//链表的结构
typedef struct linklist{
    Node *head,*tail,*current;//头结点，尾节点，当前指针
    int len;//链表长度
    int curpos;//current指针的位置
}LinkList;
 */

//初始化
int InitLinkList(LinkList * list){
    Node* p=NULL;
    //申请内存
  //  list=(LinkList*)malloc(sizeof(LinkList));if(!list) exit(ERROR);
    p=(Node*)malloc(sizeof(Node));if(!p) exit(ERROR);
    //结构初始化
    list->head=list->tail=p;
    list->tail->next=NULL;
    list->curpos=0;
    list->current=list->head;
    list->len=0;
    return OK;
/*
    LinkList *head1;
    Node *node1=NULL;//*node2=NULL;//node1是头，node2是尾
    //申请内存
    //头结点
    node1=(Node*)malloc(sizeof(Node));
    if(!node1)
        exit(ERROR);
  */
    //////////////////////////////////////////////////////////
    //尾节点
   /* node2=(Node*)malloc(sizeof(Node));
    if(!node2)
        exit(ERROR)
    */
/////////////////////////////////////////////////////////////
/*
    //链表
    head1=(LinkList*)malloc(sizeof(LinkList));
    if(!head1)
        exit(ERROR);

 //   node1->next=node2;//把头和尾连起来

    head1->head=node1;
    head1->tail=node1;
    head1->tail->next=NULL;
  //  head1->tail=node2;
    head1->len=0;
    head1->current=head1->head;
    head1->curpos=0;

    *list=*head1;
  */
  //  return OK;
}

//current指针归零（放回头结点）
void ResetCurrent(LinkList *list){
    list->current=list->head;
    list->curpos=0;
}

//打印链表
void DisplayLinkList(LinkList *list){

    Node* p;
    int count;
    //如果list本身是空表
    if(list->tail==list->head){
        printf("0..Head***Tail  {Empty LinkList}\n");
        return;
    }
    //如果不是空表
    printf("0..Head -> ");
    for(p=list->head->next,count=1;
            p->next!=NULL;
            p=p->next,++count){
        printf("%d..%d -> ",count,p->data);
    }//for
    printf("%d..%d***Tail\n",count,p->data);
}

//生成具有data==xxxx的节点
Node* CreatNode(int data){
    Node* nd;
    nd=(Node*)malloc(sizeof(Node));
    nd->data=data;
    return nd;
}

//将节点nd加入到链表中，p节点的next位置
void AddNode(Node *to,Node *from,LinkList *list){
    from->next=to->next;
    to->next=from;
    ++list->len;//链表容量++
}
//头部插入数据data的节点
void HeadInsertNode(LinkList *list, int data){
    Node* q=NULL;
    q=CreatNode(data);
    AddNode(list->head,q,list);

    //如果一开始是个空链表，则要把尾节点向后移动
    if(list->tail==list->head)
        list->tail=list->head->next;
}

//尾部插入数据data的节点
void TailInsertNode(LinkList *list, int data){
    Node* q=NULL;
    q=CreatNode(data);
    AddNode(list->tail,q,list);
    list->tail=list->tail->next;//尾部插入后，要把尾指针向后移动一下
}

//释放节点内存
void FreeNode(Node* p){
    free(p);
    p=NULL;
}

//删除一个节点的下一个节点
void DeleteNextNode(LinkList* list,Node* NowNode){
    Node* p=NowNode->next;
    if(p!=NULL){
        NowNode->next=p->next;
        FreeNode(p);
    }
    //如果删去下一节点后导致NowNode变成尾节点
    if(NowNode->next==NULL)
        list->tail=NowNode;
}

//生成用来做测试的各种链表
//随机data与len的链表，data非递减排列
void RandomLinkList(LinkList* list){
    int data,len;
    Node *p,*add=NULL;
    srand((unsigned)time(NULL));
    len=rand()%20;
    //初始化
    InitLinkList(list);

    //插入数据
    TailInsertNode(list,rand()%100);
    for(list->len=1;list->len<len;++list->len){
        while((data=rand()%100)< list->tail->data)
            ;
        TailInsertNode(list,data);
    }//for
/*//原始版的插入数据方法
    //添加第一个数据
    p=list->head;
    CreatNode(add,rand()%100);
    AddNode(p,add,list);

    for (p=p->next;
            list->len<len;
            ++list->len,p=p->next) {
        //产生递增数据
        while ((data=rand()%100) < p->data)
            ;
        //创建添加节点
        CreatNode(add,data);
        AddNode(p,add,list);
    }//for
  */
}

//生成等差数列的链表
void CreatTestLinkList(LinkList* list){
    int len=20,
        tolerance=5,//公差
        data=5;
    Node *p,*add=NULL;
    //初始化
    InitLinkList(list);

    //插入数据
    for(list->len=0;list->len<len;data+=tolerance){
        TailInsertNode(list,data);//插入时自带了++list->len
    }//for


/*//原始版的插入数据方法
    //加入数据
    for(p=list->head;
            list->len<len;
            ++list->len,p=p->next,data+=tolerance){
        //创建并添加节点
        CreatNode(add,data);
        AddNode(p,add,list);
    }//for
*/

}


























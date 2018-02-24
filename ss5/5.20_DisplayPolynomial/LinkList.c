//
// Created by wang on 17-3-11.
//
#include "LinkList.h"

/*
 * //定义结构
//结点的结构
typedef struct node{
    LinkList_ElemType data;           //存储的数据
    struct node* next;  //指向下一节点的指针
} Node;

//链表的结构
typedef struct linklist{
    Node *head,*tail;//头结点，尾节点，当前指针
    int len;//链表长度
}LinkList;
 */


///////////////////////////////////////////////////////////////////////////
//初始化
int InitLinkList(LinkList * list){
    Node* p=NULL;
    //申请内存
    p=(Node*)malloc(sizeof(Node));if(!p) exit(ERROR);
    //结构初始化
    list->head=list->tail=p;
    list->tail->next=NULL;
    list->len=0;
    return OK;
}
///////////////////////////////////////////////////////////////////////////
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
        printf("%d..%c -> ",count,p->data);
    }//for
    printf("%d..%c***Tail\n",count,p->data);
}
//////////////////////////////////////////////////////////////////////////
//生成具有data==xxxx的节点
Node* CreatNode(LinkList_ElemType data){
    Node* nd;
    nd=(Node*)malloc(sizeof(Node));
    nd->data=data;
    return nd;
}
/////////////////////////////////////////////////////////////////////////
//将节点nd加入到链表中，p节点的next位置
void AddNode(Node *to,Node *from,LinkList *list){
    from->next=to->next;
    to->next=from;
    ++list->len;//链表容量++
}
/////////////////////////////////////////////////////////////////////////
//头部插入数据data的节点
void HeadInsertNode(LinkList *list, LinkList_ElemType data){
    Node* q=NULL;
    q=CreatNode(data);
    AddNode(list->head,q,list);

    //如果一开始是个空链表，则要把尾节点向后移动
    if(list->tail==list->head)
        list->tail=list->head->next;
}
/////////////////////////////////////////////////////////////////////////
//尾部插入数据data的节点
void TailInsertNode(LinkList *list, LinkList_ElemType data){
    Node* q=NULL;
    q=CreatNode(data);
    AddNode(list->tail,q,list);
    list->tail=list->tail->next;//尾部插入后，要把尾指针向后移动一下
}
/////////////////////////////////////////////////////////////////////////
//释放节点内存
void FreeNode(Node* p){
    free(p);
    p=NULL;
}
/////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////
int IsEmptyList(LinkList* list){
    if(list->len==0)
        return EMPTY;
    else
        return UNEMPTY;
}
//////////////////////////////////////////////////////////////////////////
//销毁一个链表
void DestroyList(LinkList* list){
    list->len=0;
    while (list->head->next!=NULL)
        //不断删去头结点的下一个节点
        DeleteNextNode(list,list->head);
    //释放头结点
    FreeNode(list->head);
    list=NULL;
}
/////////////////////////////////////////////////////////////////////////
//创建一个测试用链表，数据为一个数组的数据
void CreatMyList(LinkList* listA,LinkList_ElemType s[], int size){
    int i;
    InitLinkList(listA);
    for(i=0;i<size;++i)
        TailInsertNode(listA,s[i]);
}
/////////////////////////////////////////////////////////////////////////
/*
//生成用来做测试的各种链表
//随机data与len的链表，data非递减排列
void RandomLinkList(LinkList* list){
    LinkList_ElemType data;
    int len;
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

}
/////////////////////////////////////////////////////////////////////////////
//生成等差数列的链表
void CreatTestLinkList(LinkList* list){
    int len=5,
        tolerance=5,//公差
        data=5;
    Node *p,*add=NULL;
    //初始化
    InitLinkList(list);

    //插入数据
    for(list->len=0;list->len<len;data+=tolerance){
        TailInsertNode(list,data);//插入时自带了++list->len
    }//for
}
*/
/////////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////////


























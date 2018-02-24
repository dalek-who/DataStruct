//
// Created by wang on 17-3-11.
//
#include "Queue.h"

/*
 typedef struct node{
    ElemType data;           //存储的数据
    struct node* next;  //指向下一节点的指针
} Node;

//队列的结构
typedef struct queue{
    Node *head,*front,*rear;//头结点，队头（与头结点最近的节点），队尾（与头结点最远的节点）
    int len;//队列长度
}Queue;
 */


///////////////////////////////////////////////////////////////////////////
//初始化
int InitQueue(Queue * queue ){
    Node* p=NULL;
    //申请内存
    p=(Node*)malloc(sizeof(Node));if(!p) exit(ERROR);
    //结构初始化
    queue->head=p;
    queue->rear=queue->head;
    queue->rear->next=NULL;
    queue->len=0;
    return OK;
}
///////////////////////////////////////////////////////////////////////////
//判断是否为空队列
int IsEmptyQueue(Queue* queue){
    if(queue->len==0)
        return EMPTY;
    else
        return UNEMPTY;
}
///////////////////////////////////////////////////////////////////////////
/*
//打印队列
void DisplayQueue(Queue *queue ){

    Node* p;
    int count;
    //如果list本身是空表
    if(queue->len==0){
        printf("0..Head....Rear  {Empty Queue}\n");
        return;
    }
    //如果不是空表
 //   printf("0..%d  ",queue->head->next->data);
    for(p=queue->head->next,count=0;
            p->next!=NULL;
            p=p->next,++count){
        printf("%d..%c  ",count,p->data);
    }//for
    printf("%d..%c***Rear\n",count,p->data);
}
 */
//////////////////////////////////////////////////////////////////////////

//生成具有data==xxxx的节点
Node* CreatNode(ElemType data){
    Node* nd;
    nd=(Node*)malloc(sizeof(Node));
    nd->data=data;
    return nd;
}
/////////////////////////////////////////////////////////////////////////

//释放节点内存
void FreeNode(Node* p){
    free(p);
    p=NULL;
}

/////////////////////////////////////////////////////////////////////////
//从尾部入队
void EnQueue(Queue *queue, ElemType data){
    Node* q=NULL;
    q=CreatNode(data);
    queue->rear->next=q;
    queue->rear=q;
    queue->rear->next=NULL;
    ++queue->len;
}
/////////////////////////////////////////////////////////////////////////
//从头部出队
ElemType DeQueue(Queue* queue){
    ElemType c;
    Node* p=queue->head->next;
    if(p==NULL) {
        printf("ERROR: empty queue can't DeQueue\n");
        exit(ERROR);
    }
    c=p->data;
    queue->head->next=p->next;
    FreeNode(p);
    --queue->len;
    //队头出队后，如果不变成空队，则尾指针不用变
    //如果变成空队列，则原本的rear指向的节点被回收，把rear指向head
    if(queue->len==0)
        queue->rear=queue->head;
    return c;
}
///////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////


























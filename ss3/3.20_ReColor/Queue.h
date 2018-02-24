//
// Created by wang on 17-3-11.
//
////////////////////////////////
//队列Queue
//用链表实现的队列
///////////////////////////////

#ifndef INC_2_19_DELETELEM_LINKLIST_INT_H
#define INC_2_19_DELETELEM_LINKLIST_INT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERROR 0
#define OK 1
#define EMPTY 1
#define UNEMPTY 0


//图象中一个点的坐标
typedef struct point{
    int i;//行
    int j;//列
}Point;

//元素类型
typedef Point ElemType;

//定义结构
//结点的结构
typedef struct node{
    ElemType data;           //存储的数据
    struct node* next;  //指向下一节点的指针
} Node;

//队列的结构
typedef struct queue{
    Node *head,*rear;//头结点，队头（与头结点最近的节点），队尾（与头结点最远的节点）
    int len;//队列长度
}Queue;

//函数返回类型
typedef Queue Status;

//相关的操作
int InitQueue(Queue* queue);//队列初始化
void DisplayQueue(Queue *queue);//打印队列
Node* CreatNode(ElemType c);//生成具有data=c的节点
void EnQueue(Queue *queue, ElemType c);//入队（从队尾进入）
ElemType DeQueue(Queue *queue);//出队（从队头出队）
void FreeNode(Node* p);//释放节点内存
int IsEmptyQueue(Queue *queue);//判断队列是否为空

#endif //INC_2_19_DELETELEM_LINKLIST_INT_H

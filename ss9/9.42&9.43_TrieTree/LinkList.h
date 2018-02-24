//
// Created by wang on 17-3-11.
//
////////////////////////////////
//   没有头结点的链表
//
//改进单向链表的头文件
//改进链表有一个链表，头指针，尾指针，链表中的元素长度。没有头结点，头指针head所指向的节点存有第一个数据元素
//元素是int型
///////////////////////////////

#ifndef INC_2_19_DELETELEM_LINKLIST_INT_H
#define INC_2_19_DELETELEM_LINKLIST_INT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ERROR 0
#define OK 1
#define EMPTY 1
#define UNEMPTY 0

//元素类型
typedef char*  ElemType;

//定义结构
//结点的结构
typedef struct node{
    ElemType data;           //存储的数据
    struct node* next;  //指向下一节点的指针
} Node;

//链表的结构
typedef struct linklist{
    Node *head,*tail;
    int len;//链表长度
}LinkList;

//相关的操作
int InitLinkList(LinkList* list);//链表初始化
void DisplayLinkList(LinkList *list);//打印链表
Node* CreatNode(ElemType data);//生成具有data==xxxx的节点
void AddNode(Node *to,Node *from,LinkList *list);//将节点nd加入到链表中，p节点的next位置
void HeadInsertNode(LinkList *list, ElemType data);//头部插入数据data的节点
void TailInsertNode(LinkList *list, ElemType data);//尾部插入数据data的节点
Node* FreeNode(Node* p);//释放节点内存
void DeleteNextNode(LinkList* list,Node* NowNode);//删除一个节点的next节点。如果删去了尾节点，则把新的最后一个节点变成尾节点
void DestroyList(LinkList* list);//销毁一个链表
int IsEmptyList(LinkList *list);//判断链表是否为空
void CreatMyList(LinkList* listA,ElemType s[], int size);//创建一个链表，链表的数据为s[]1

/*
//生成一些特殊的测试用链表
void RandomLinkList(LinkList * list);//随机data与len的链表，data非递减排列
void CreatTestLinkList(LinkList * list);//生成等差数列的链表
*/

#endif //INC_2_19_DELETELEM_LINKLIST_INT_H

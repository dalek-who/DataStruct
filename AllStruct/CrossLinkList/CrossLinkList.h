//
// Created by Administrator on 2017/4/6.
//

#ifndef INC_5_27_MATRIXADD_CROSSLINKLIST_H
#define INC_5_27_MATRIXADD_CROSSLINKLIST_H

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define EMPTY 1
#define UNEMPTY 0

//十字链表（带横向、纵向的头尾结点）
//可以用来表示稀疏矩阵，结点是非零元素

//元素类型
typedef int CrLinkList_ElemType;

////////////////////////////////////////////////////////////
//结构体的定义：
//分三个层次定义出来：结点，一维链表，十字链表
////////////////////////////////////////////////////////////
//结点定义：
typedef struct Node{
    CrLinkList_ElemType data;//数据
    //也可以扩展为高维链表，方法是把指针域扩展为指针数组，每个数组元素存的是一个维度的next指针
    struct Node *rignt,*down;//右方、下方的next
    int i,j;//行、列的下标
}Node;

//一维链表定义：
//与方向无关的定义方法：
typedef struct LinkList{
    Node *head;//头结点
    //Node* tail;// 尾结点
    int len;//长度
}LinkList;

//与方向有关的定义方法：
//此定义方法缺乏扩展性，不便于把十字链表再扩展为高维链表
/*
//向右方向的链表
typedef struct RLinkList{
    Node *head,*Rtail;//头结点，右边的尾结点
    int len;
}RLinkList;
//向下方向的链表
typedef struct DLinkList{
    Node *head,*Dtail;//头结点，右边的尾结点
    int len;
}DLinkList;
*/

//十字链表定义
typedef struct CrLinkList{
    LinkList *Rhead,*Dhead;//存储横向、纵向链表头指针的动态数组
    int mu,//行数
        nu;//列数
    int tu;//用十字链表表示稀疏矩阵时的非零元素个数
}CrLinkList;

/////////////////////////////////////////////////////////////////////////////////////////////
//操作
int InitLinkList(LinkList * list);//一维链表初始化（用来初始化十字链表的所有行、列一维链表）
void Input_mn(CrLinkList *cross);//输入十字矩阵行、列数
// (把输入mn单提出来，是为了能复用初始化函数，以方便用除了输入之外的其他方式来产生十字链表）
int InitCrLinkList(CrLinkList* Cross);//十字链表初始化
int IsEmptyList(LinkList linkList);//判断一维链表是否为空
Node* CreatNode(CrLinkList_ElemType data, int i, int j);//创建节点(包括结点的数据、坐标）
void InsertNode(Node* node,CrLinkList* cross);//将结点按照坐标插入十字链表的正确位置
void CreatCrLinkList(CrLinkList* cross);//创建并赋值十字链表
void DisplayCrossLinkList(CrLinkList cross);//以稀疏矩阵的形式打印十字链表
void InsertElem(CrLinkList* cross,CrLinkList_ElemType elem, int i, int j);//在十字链表的坐标(i,j)处插入元素elem
void FreeNode(Node *node);//释放节点内存并把指针置空
void DeleteNode(CrLinkList* cross,Node* node);//删除十字链表中的一个节点并释放其内存
void ArrayToCrLinkList(CrLinkList *Cross,int m, int n,CrLinkList_ElemType array[m+1][n+1]);//将二维数组转化为十字链表
#endif //INC_5_27_MATRIXADD_CROSSLINKLIST_H

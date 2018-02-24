//
// Created by Administrator on 2017/5/15.
//

//邻接表表示的有向图

#ifndef INC_6_72_PRINTGraph02_Graph_CHILDLINKLIST_H
#define INC_6_72_PRINTGraph02_Graph_CHILDLINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

#define ERROR 0

//元素类型
typedef int Graph_ElemType;

//数据结构
//结点
typedef struct Gnode{
    Graph_ElemType data; //结点存储的数据
    LinkList children;  //孩子链表
}Gnode;
//树
typedef struct Graph{
    int NodeNumber; //节点数量
    Gnode *NodeArray; //节点数组
}Graph;

//基本操作
Graph InitGraph(int NodeNumber); //初始化树 .参数为树的节点数量
Graph CreatGraph();   //创建一棵树（里面包含了初始化）
void AssignData(Graph *graph);//给树的每个节点赋值（为了方便，data就赋值为节点的编号）
void InsertArc(Graph *graph, int form, int to); //插入边，form是起点，to是终点
void DisplayGraph(Graph *graph); //打印图

#endif //INC_6_72_PRINTGraph02_Graph_CHILDLINKLIST_H

//
// Created by Administrator on 2017/5/24.
//

#ifndef INC_7_15_GRAPH_NEIGNBORMATRIX_GRAPH_NEIGNBORMATRIX_H
#define INC_7_15_GRAPH_NEIGNBORMATRIX_GRAPH_NEIGNBORMATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//用邻接矩阵表示的图

#define OK 1
#define ERROR 0

//元素类型
typedef char Graph_ElemType;
//结构定义
typedef struct Graph_NeighborMatrix{
    int VexNumber,ArcNumber; //顶点数，边数]
    Graph_ElemType *Vex; //顶点集
    int **Matrix; //邻接矩阵（长宽都不定的二维数组，可用指向指针的指针表示）
}Graph_NeighborMatrix;

int InitGraph(Graph_NeighborMatrix *graph); //初始化图
int VexIndex(Graph_NeighborMatrix *graph,Graph_ElemType vex); //返回一个顶点的编号
int InsertVex(Graph_NeighborMatrix *graph,Graph_ElemType vex);//插入顶点
int DeleteVex(Graph_NeighborMatrix *graph,Graph_ElemType vex);//删除顶点
int InsertArc(Graph_NeighborMatrix *graph,Graph_ElemType from,Graph_ElemType to);//插入边
int DeleteArc(Graph_NeighborMatrix *graph,Graph_ElemType from,Graph_ElemType to);//删除边
void DisplayGraph(Graph_NeighborMatrix *graph); //打印图的邻接矩阵

#endif //INC_7_15_GRAPH_NEIGNBORMATRIX_GRAPH_NEIGNBORMATRIX_H

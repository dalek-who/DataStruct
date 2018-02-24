//
// Created by Administrator on 2017/5/24.
//

//用邻接矩阵表示的图

#include "Graph_NeignborMatrix.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//初始化图
int InitGraph(Graph_NeighborMatrix *graph){
    graph->ArcNumber=0;
    graph->VexNumber=0;
    graph->Vex=NULL;
    graph->Matrix=(int**)malloc(sizeof(int*)); graph->Matrix[0]= NULL;
    return OK;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //返回一个顶点的编号
int VexIndex(Graph_NeighborMatrix *graph,Graph_ElemType vex){
    for (int i = 1; i <=graph->VexNumber ; ++i) {
        if(vex == graph->Vex[i])
            return i; // 如果发现，返回坐标
        else continue;
    }

    return 0; //没发现则返回0（矩阵0号不存元素）
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//插入顶点
int InsertVex(Graph_NeighborMatrix *graph,Graph_ElemType vex){
     ++graph->VexNumber;
    //注：为了方便操作，矩阵的0行、0列不存顶点
    //扩容
    graph->Vex = (Graph_ElemType *)realloc(graph->Vex,(graph->VexNumber+1)*sizeof(Graph_ElemType));
    if(graph->Vex==NULL) exit(ERROR);
    //加入新顶点
    graph->Vex[graph->VexNumber] = vex;
    //给邻接矩阵扩容
    graph->Matrix = (int**)realloc(graph->Matrix,(graph->VexNumber+1)*sizeof(int*));
    graph->Matrix[graph->VexNumber]=NULL; //新顶点先置空，否则后面分配内存会出问题
    int *newbase;
    for (int i = 1; i <=graph->VexNumber ; ++i) {
        newbase = (int*)realloc(graph->Matrix[i], (graph->VexNumber+1) * sizeof(int));
        graph->Matrix[i] = newbase;
        if(graph->Matrix[i]==NULL) exit(ERROR);
        //将与新顶点相关的边初始化为0
        graph->Matrix[i][graph->VexNumber] = 0;
    }
    for (int j = 0; j < graph->VexNumber ; ++j)
        graph->Matrix[graph->VexNumber][j] = 0;

    return OK;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//删除顶点
int DeleteVex(Graph_NeighborMatrix *graph,Graph_ElemType vex){
    int index= VexIndex(graph,vex);
    if(!index)
        return OK; //如果未发现该顶点，则直接返回
    else{
        //去掉顶点集中的该顶点
        for (int k = index; k <graph->VexNumber ; ++k)
            graph->Vex[k] = graph->Vex[k+1];
        graph->Vex = (Graph_ElemType*)realloc(graph->Vex,graph->VexNumber*sizeof(Graph_ElemType));

        //去掉矩阵中的该顶点
        //矩阵j分量改变
        for (int i = 1; i <=graph->VexNumber ; ++i) {
            //j分量数据前移
            for (int j = index; j <graph->VexNumber ; ++j)
                graph->Matrix[i][j]=graph->Matrix[i][j+1];
     //       free(&graph->Matrix[i][graph->VexNumber]);//释放腾出来的空间

            //重新分配内存。由于0号不存数据，所以原本是（VexNumber+1）*（VexNumber+1）的空间
            // 重新分配变为 VexNumber*VexNumber
            graph->Matrix[i] = (int*)realloc(graph->Matrix[i],(graph->VexNumber)*sizeof(int));
        }//for i

        //矩阵i分量改变
        //数据前移
        for (int k = index; k <graph->VexNumber ; ++k)
            graph->Matrix[k]=graph->Matrix[k+1];
/*
        for (int l = 0; l <=graph->VexNumber-1 ; ++l)
            free(&graph->Matrix[graph->VexNumber][l]);

        free(&graph->Matrix[graph->VexNumber]);

        for (int k = index; k <graph->VexNumber ; ++k)
            graph->Vex[k]=graph->Vex[k+1];

*/  //释放最后位置的int*指针
  //      free(graph->Matrix[graph->VexNumber]);
        //i分量重新分配内存
        graph->Matrix = (int**)realloc(graph->Matrix,(graph->VexNumber)*sizeof(int*));
    }

    --graph->VexNumber;
    return OK;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//插入边
int InsertArc(Graph_NeighborMatrix *graph,Graph_ElemType from,Graph_ElemType to){
    int index_from,index_to;
    index_from = VexIndex(graph,from);
    index_to   = VexIndex(graph,to);
    if(index_from!=0 && index_to!=0) {
        graph->Matrix[index_from][index_to] = 1;
        ++graph->ArcNumber;
        return OK;
    } else
        exit(ERROR);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//删除边
int DeleteArc(Graph_NeighborMatrix *graph,Graph_ElemType from,Graph_ElemType to){
    int index_from,index_to;
    index_from = VexIndex(graph,from);
    index_to   = VexIndex(graph,to);
    if(index_from!=0 && index_to!=0) {
        graph->Matrix[index_from][index_to] = 0;
        --graph->ArcNumber;
        return OK;
    } else
        exit(ERROR);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//打印图的邻接矩阵
void DisplayGraph(Graph_NeighborMatrix *graph){
    int flag=0;
    for (int i = 1; i <= graph->VexNumber; ++i) {
        if(flag!=0 )
            printf("\n");
        flag=1;
        for (int j = 1; j <=graph->VexNumber ; ++j) {
            if (j != 1)
                printf(" ");
            printf("%d", graph->Matrix[i][j]);
        }
    }
    return;
}
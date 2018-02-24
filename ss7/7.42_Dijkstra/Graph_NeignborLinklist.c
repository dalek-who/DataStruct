//
// Created by Administrator on 2017/5/15.
//

//邻接表表示的有向图

#include "Graph_NeighborLinkList.h"

///////////////////////////////////////////////////////////////////////////////
//初始化图
Graph InitGraph(int NodeNumber){
    Graph graph;
    //节点数量
    graph.NodeNumber = NodeNumber;

    //依据节点数量分配结点数组的内存
    //0号元素不存内容，所以要NodeNumber+1个空间
    graph.NodeArray = (Gnode*)malloc((NodeNumber+1) * sizeof(Gnode));
    if(!graph.NodeArray) exit(ERROR);

    //初始化各个结点里面的孩子链表
    int i;
    for(i=0;i<=NodeNumber;++i)
        InitLinkList(&graph.NodeArray[i].children);
    return graph;
}

///////////////////////////////////////////////////////////////////////////////
/*
//插入边，form是起点，to是终点
void InsertArc(Graph *graph, int form, int to){
    if(form>graph->NodeNumber)
        exit(ERROR);
    else
        TailInsertNode(&graph->NodeArray[form].children,to);
    return;
}
*/
///////////////////////////////////////////////////////////////////////////////
/*
Graph CreatGraph(){
    Graph graph;
    int VexNumber,ArcNumber; //顶点数，边数
    //输入顶点数、边数
    scanf("%d %d",&VexNumber,&ArcNumber);
    //初始化图
    graph = InitGraph(VexNumber);

    //插入顶点和边
    int from,to;
    for (int i = 0; i <ArcNumber ; ++i) {
        scanf("%d %d",&from,&to);
        InsertArc(&graph,from,to);
    }

    return graph;
}
*/
/*
//创建一棵树（里面包含了初始化）
Tree CreatTree(){
    Tree tree;
    int node_n;

    //输入节点数量来初始化树
    int NodeNumber; //节点数量
    scanf("%d",&NodeNumber);
    tree = InitTree(NodeNumber);

    //输入各个结点的孩子结点
    //int Child[NodeNumber];
    int i,j;
    for(i=1;i<=NodeNumber;++i){
        j =0;
        do{
            //输入孩子结点并加入到孩子链表
            scanf("%d",&node_n);
            if(node_n!=0){
                TailInsertNode(&tree.NodeArray[i].children,node_n);
                ++j;
            }//if
        }while (node_n!=0 && j<NodeNumber);
    }//for

    return tree;
}
*/
///////////////////////////////////////////////////////////////////////////////
//给图的每个节点赋值（为了方便，data就赋值为节点的编号）
void AssignData(Graph *graph){
    int i;
    for(i=1;i<=graph->NodeNumber;++i)
        graph->NodeArray[i].data = i;
}

///////////////////////////////////////////////////////////////////////////////
//打印图
void DisplayGraph(Graph *graph){
    Node *p;
    for (int i = 1; i <=graph->NodeNumber ; ++i) {
        printf("%d:  ",i);
        for(p=graph->NodeArray[i].children.head->next ; p!=NULL ; p=p->next)
            printf(" ->%d %d ",p->data.to,p->data.weight);
        printf("\n");
    }
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
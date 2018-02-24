#include <stdio.h>
#include "Graph_NeighborLinkList.h"

#define INFINITY 1000 //以一个比所有的权都大很多的数作为无穷大
#define VISIT 1
#define UNVISIT 0


//oj输入有权图
//插入有权边，form是起点，to是终点
void InsertWeightArc(Graph *graph, int form, int to,int weight){
    wArc arc;
    if(form>graph->NodeNumber)
        exit(ERROR);
    else {
        arc.to = to;
        arc.weight = weight;
        TailInsertNode(&graph->NodeArray[form].children,arc);
    }
    return;
}

Graph oj_CreatWeightGraph(){
    Graph graph;
    int VexNumber,ArcNumber,weight; //顶点数，边数,权
    //输入顶点数、边数
    scanf("%d %d",&VexNumber,&ArcNumber);
    //初始化图
    graph = InitGraph(VexNumber);

    //插入顶点和边
    int from,to;
    for (int i = 0; i <ArcNumber ; ++i) {
        scanf("%d %d %d",&from,&to,&weight);
        InsertWeightArc(&graph,from,to,weight);
    }

    return graph;
}



typedef struct Dij{
    int length; //距离
    int visit_flag; //访问的标记
}Dij;

int FindMinDij(Dij DijArray[], int NodeNumber){
    int min=1;
    int flag = 0;
    for (int i = 1; i <=NodeNumber ; ++i) {
        if(DijArray[i].visit_flag == VISIT)
            continue;
        else {

            //min初始设置为第一个未访问的节点
            min = (flag==0)? i : min;
            flag = 1;

            if (DijArray[i].length < DijArray[min].length)
                min = i;
        }
    }
    return min;
}

//计算有权图中一条边的权。如果没有这条边，返回无穷大
int ArcWeight(Graph *graph, int from, int to){
    int weight = INFINITY;
    Node *pnode;
    for(pnode=graph->NodeArray[from].children.head->next ; pnode!=NULL ; pnode=pnode->next){
        if(pnode->data.to == to){
            weight = pnode->data.weight;
            break;
        }//if
    }//for
    return weight;
}

void Dijkstra(Graph *graph, int node){
    int UnVisitNumber=graph->NodeNumber; //未访问的节点数量
    int length[graph->NodeNumber+1]; //存储最短路径结果
    Dij DijArray[graph->NodeNumber+1]; //Dijkstra算法的操作数组


    //初始化数组
    int i;
    for ( i = 0; i <=graph->NodeNumber ; ++i) {
        length[i] = -1; //-1代表不可到达
        DijArray[i].length = INFINITY;
        DijArray[i].visit_flag = UNVISIT;
    }

    //将起点加入数组
    length[node] = 0;
    DijArray[node].length=0;
    DijArray[node].visit_flag = VISIT;
    --UnVisitNumber;

    int new_node = node;
    int new_length;
    int weight;
    while (UnVisitNumber!=0){

        //加入新节点后，更新最短路径
        for (int j = 1; j <=graph->NodeNumber ; ++j) {
            if(DijArray[j].visit_flag == UNVISIT){
                //计算新的可能的最短路径的值
                weight = ArcWeight(graph,new_node,j);
                new_length = (weight==INFINITY)? INFINITY : length[new_node]+weight;
                //更新当前最短路径值
                DijArray[j].length = (new_length < DijArray[j].length )? new_length : DijArray[j].length;
            }//if
        }//for

        //更新新加入的结点
        new_node = FindMinDij(DijArray,graph->NodeNumber);
        DijArray[new_node].visit_flag = VISIT;
        length[new_node] = DijArray[new_node].length;
        --UnVisitNumber;
    }//while

    int flag = 0;
    for(i=1;i<=graph->NodeNumber;++i){

        if(flag!=0) printf("\n");
        flag = 1;

        printf("%d",(length[i]==INFINITY)?-1:length[i]);
    }
}

int main() {
  //  printf("Hello, World!\n");
    Graph graph=oj_CreatWeightGraph();
 //   DisplayGraph(&graph);
    int node;
    scanf("%d",&node);
    Dijkstra(&graph,node);
    return 0;
}
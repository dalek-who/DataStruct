#include <stdio.h>
#include "Graph_NeighborLinkList.h"

//用有向无环图表示的逆波兰表达式
//创建用有向无环图表示的逆波兰表达式
Graph CreatAntiPoland(){
    Graph graph;
    //输入顶点数和边数
    int VexNumber,ArcNumber;
    scanf("%d %d",&VexNumber,&ArcNumber);
    graph = InitGraph(VexNumber);

    //输入结点数据
    for (int i = 1; i <= VexNumber ; ++i)
        scanf(" %c",&graph.NodeArray[i].data);

    //输入图的边（默认1号结点是根节点）
    int from,to;
    for (int j = 0; j < ArcNumber; ++j) {
        scanf("%d %d",&from,&to);
        InsertArc(&graph,from,to);
    }//for

    return graph;
}

//深度优先递归打印逆波兰
void DeepVisit_DisplayAntiPoland(Graph *graph, int node){
    static int flag = 0; //标记是不是打印的第一个点，关系到后面是否要打空格
    Node *pnode;
    for(pnode = graph->NodeArray[node].children.head->next; pnode!=NULL ;pnode = pnode->next)
        DeepVisit_DisplayAntiPoland(graph,pnode->data);
    printf("%s%c",(flag == 0)?"":" ",graph->NodeArray[node].data);
    flag = 1;
    return;
}

//打印逆波兰表达式
void DisplayAntiPoland(Graph *graph){
    DeepVisit_DisplayAntiPoland(graph,1);
    return;
}

int main() {
 //   printf("Hello, World!\n");
    Graph graph;
    graph = CreatAntiPoland();
   // DisplayGraph(&graph);
    DisplayAntiPoland(&graph);
    return 0;
}
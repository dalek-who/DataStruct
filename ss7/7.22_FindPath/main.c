
#include <stdio.h>
#include "Graph_NeighborLinkList.h"

#define VISIT 1
#define NOT_VISIT 0
#define FIND 1
#define NOT_FIND 0

typedef struct Arc{
    int from;
    int to;
}Arc;

int DeepVisitFindPath(Graph *graph, int node, int visit[], int to){
    int find=NOT_FIND;
    Node *pnode;
    if(visit[node] == VISIT)
        find = NOT_FIND;
    else{
        //visit[0]存贮已经访问的节点数量
        visit[node] = VISIT;
        ++visit[0];
        if(node == to)
            find = FIND;
        else {
            for (pnode = graph->NodeArray[node].children.head->next; pnode != NULL; pnode = pnode->next) {
                //递归遍历。如果已经遍历了该节点，进入函数以后会直接退出
                find = DeepVisitFindPath(graph, pnode->data, visit, to);
                if(find == FIND)
                    break;
                else
                    continue;
            }//for
        }//else
    }//else
    return find;
}



int main() {
 //   printf("Hello, World!\n");
    Graph graph;
    graph = CreatGraph();

    int visit[graph.NodeNumber+1];

    int test_number;//测试的数量
    scanf("%d",&test_number);

    Arc arc[test_number];
    for (int j = 0; j < test_number; ++j)
        scanf("%d %d",&arc[j].from,&arc[j].to);

    for (int k = 0; k <test_number ; ++k) {
        for (int i = 0; i <=graph.NodeNumber ; ++i)
            visit[i] = NOT_VISIT;

        printf("%d\n",DeepVisitFindPath(&graph,arc[k].from,visit,arc[k].to));
    }
    //DisplayGraph(&graph);
    return 0;
}
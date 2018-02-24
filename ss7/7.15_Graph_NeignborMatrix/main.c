#include <stdio.h>
#include "Graph_NeignborMatrix.h"

void oj_Operation(Graph_NeighborMatrix *graph){
    int OpNumber;
    scanf("%d",&OpNumber);

    int choose;
    char from,to;
    for (int i = 0; i <OpNumber ; ++i) {
        scanf("%d ",&choose);
        switch (choose){
            case 1:
                scanf(" %c",&from);
                InsertVex(graph,from);
                break;
            case 2:
                scanf(" %c %c",&from,&to);
                InsertArc(graph,from,to);
                break;
            case 3:
                scanf(" %c",&from);
                DeleteVex(graph,from);
                break;
            case 4:
                scanf(" %c %c",&from,&to);
                DeleteArc(graph,from,to);
                break;
            default:
                break;
        }//swtich

        printf("%d\n",i+1);
        DisplayGraph(graph);
    }
}

int main() {
//    printf("Hello, World!\n");
    Graph_NeighborMatrix graph;
    InitGraph(&graph);
    oj_Operation(&graph);
    //DisplayGraph(&graph);

    /*
    int i;
    char a,b,c;
    scanf("%d\n",&i);
    scanf("\n%c %c %c",&a,&b,&c);
    printf("%d %c %c %c",i,a,b,c);
     */
    return 0;
}
#include <stdio.h>
#include "Graph_NeighborLinkList.h"

#define FIND 1
#define UNFIND 0
#define VISIT 1
#define UNVISIT 0

//判断从点from到点to是否有长度为length的简单路径（简单路径：路径中没有重复出现的顶点）
// 运用深度优先遍历所有从from出发的长度为length的路径，看长为length的路径终点是否为to
// 注：若某条路径在长度不到length时就遇到了to，这样的路径也不算

int DeepVisit_JudgeSimplePath(Graph *graph,int node, int to, int length, int visit[]){
    //深度
    //每进入新一层++deep，退出时--deep。为了让根节点deep==0，deep初始化为-1
    static int deep = -1;
    ++deep;

    //标记一个顶点是否在路径上被标记。如果被标记则不能再加入路径。从该顶点退出时要消去标记


    //标记是否找到满足要求的路径的flag
    int find = UNFIND;

    //各种情况
    //如果结点已经被访问，则退出
    if( visit[node] == VISIT ) {
        find = UNFIND;
        --deep;
        return find;
    }

    else visit[node] = VISIT;

    if(deep == length && node == to)
        find = FIND;
    else if(deep == length && node != to)
        find = UNFIND;
    else if(deep < length && node == to)
        find = UNFIND;
    else{
        Node *pnode;
        //深度优先，递归遍历未访问结点
        for(pnode = graph->NodeArray[node].children.head->next ; pnode!=NULL ; pnode = pnode->next){
            find = DeepVisit_JudgeSimplePath(graph,pnode->data,to,length,visit);
            //找到满足题设的路径立刻return
            if(find == FIND)
                break;
            else
                continue;
        }//for
    }//else

    //退出
    //抹去访问标记
    visit[node] = UNVISIT;
    --deep;
    return find;
}

int JudgeSimplePath(Graph *graph,int from, int to, int length){
    int visit[graph->NodeNumber+1];
        for (int i = 0; i <= graph->NodeNumber; ++i)
            visit[i] = UNVISIT;

    int find = DeepVisit_JudgeSimplePath(graph,from,to,length,visit);
    printf("%d\n",find);
    return find;
}

typedef struct Path{
    int from;
    int to;
    int length;
}Path;

int main() {
  //  printf("Hello, World!\n");
    Graph graph;
    graph = CreatGraph_non_direction();

    int test_number;
    scanf("%d",&test_number);
    Path path[test_number];

    for (int i = 0; i <test_number ; ++i)
        scanf("%d %d %d",&path[i].from,&path[i].to,&path[i].length);

    for (int j = 0; j <test_number ; ++j)
        JudgeSimplePath(&graph,path[j].from,path[j].to,path[j].length);

    return 0;

}
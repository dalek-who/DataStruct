#include <stdio.h>
#include "Tree_ChildLinklist.h"
#include "LinkList.h"

#define VISIT 1
#define NOT_VISIT 0

//深度优先遍历一个节点下面的分支
int DeepDisplayNode(Tree *ptree,int node_index, int NodeVisit[]){
    static int deep = 0;
    Tnode *ptnode = &( ptree->NodeArray[node_index] );

    //已经访问过的就不再重复访问了
    if( NodeVisit[node_index] )
        return VISIT;

    //打印空格和数据
    for (int i = 0; i <deep ; ++i)
        printf("0");
    printf("%d\n",ptnode->data);
    NodeVisit[node_index] = VISIT;

    //打印孩子
    Node *p; //Node是链表结点，不是树节点
    //如果孩子链表为空，循环第一次就退出了
    for(p = ptnode->children.head->next;p!=NULL;p=p->next) {
        //一个节点的孩子们深度相同，进入孩子要++deep，退出孩子要--deep
        ++deep;
        DeepDisplayNode(ptree, p->data, NodeVisit);
        --deep;
    }

    //打印完，返回
    return VISIT;
}

//用孩子链表存储一棵树，并用凹入表打印出来
void DisplayTree(Tree *ptree){

    //该数组用来标记一个节点是否已经被访问了
    int NodeVisit[ptree->NodeNumber+1];
    for (int i = 0; i <= ptree->NodeNumber  ; ++i)
        NodeVisit[i] = 0;

    //访问每一棵树
    for (int j = 1; j <= ptree->NodeNumber ; ++j) {
        //访问未访问的结点，并深度优先访问一个节点下面的子孙结点
        //visit是个深度优先的递归函数，递归访问一个节点下面的子孙结点
        if(!NodeVisit[j])
            DeepDisplayNode( ptree,j,NodeVisit);
    }
}


int main() {
    //printf("Hello, World!\n");

    Tree tree;
    tree = CreatTree();

    AssignData(tree);

    DisplayTree(&tree);

    return 0;
}
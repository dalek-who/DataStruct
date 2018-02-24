//
// Created by Administrator on 2017/5/15.
//

#include "Tree_ChildLinklist.h"

///////////////////////////////////////////////////////////////////////////////
//初始化树
Tree InitTree(int NodeNumber){
    Tree tree;
    //节点数量
    tree.NodeNumber = NodeNumber;

    //依据节点数量分配结点数组的内存
    //0号元素不存内容，所以要NodeNumber+1个空间
    tree.NodeArray = (Tnode*)malloc((NodeNumber+1) * sizeof(Tnode));
    if(!tree.NodeArray) exit(ERROR);

    //初始化各个结点里面的孩子链表
    int i;
    for(i=0;i<=NodeNumber;++i)
        InitLinkList(&tree.NodeArray[i].children);
    return tree;
}

///////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////
//给树的每个节点赋值（为了方便，data就赋值为节点的编号）
void AssignData(Tree tree){
    int i;
    for(i=1;i<=tree.NodeNumber;++i)
        tree.NodeArray[i].data = i;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
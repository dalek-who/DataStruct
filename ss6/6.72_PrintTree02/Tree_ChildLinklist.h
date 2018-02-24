//
// Created by Administrator on 2017/5/15.
//

//孩子链表表示的树

#ifndef INC_6_72_PRINTTREE02_TREE_CHILDLINKLIST_H
#define INC_6_72_PRINTTREE02_TREE_CHILDLINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

#define ERROR 0

//元素类型
typedef int Tree_ElemType;

//数据结构
//结点
typedef struct Tnode{
    Tree_ElemType data; //结点存储的数据
    LinkList children;  //孩子链表
}Tnode;
//树
typedef struct Tree{
    int NodeNumber; //节点数量
    Tnode *NodeArray; //节点数组
}Tree;

//基本操作
Tree InitTree(int NodeNumber); //初始化树 .参数为树的节点数量
Tree CreatTree();   //创建一棵树（里面包含了初始化）
void AssignData(Tree tree);//给树的每个节点赋值（为了方便，data就赋值为节点的编号）


#endif //INC_6_72_PRINTTREE02_TREE_CHILDLINKLIST_H

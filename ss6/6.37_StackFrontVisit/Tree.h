//
// Created by Administrator on 2017/5/11.
//
//二叉链表表示的二叉树
#ifndef INC_6_43_EXCHANGESUBTREE_TREE_H
#define INC_6_43_EXCHANGESUBTREE_TREE_H

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define EMPTY 1
#define UNEMPTY 0

//元素类型
typedef int Tree_Elemtype;
//结构定义：
typedef struct TreeNode{
    Tree_Elemtype data; //树存储的数据
    struct TreeNode *left,*right; //左孩子，右孩子
}TreeNode,*Tree;

//操作
Tree InitTree(); //初始化一棵树，给一个树分配一个根节点
int CreatTree(Tree tree,Tree_Elemtype data); //创建一棵树，并为其赋值。Tree本身就是指针类型
void StructDisplayTree(Tree tree); //递归打印一棵树（打印出来可以看清楚树的分支结构）
void FrontDisplayTree(Tree tree); //按前序遍历打印出树
int FrontVisit(Tree tree, int (*visit) (Tree) );//先序遍历树
#endif //INC_6_43_EXCHANGESUBTREE_TREE_H

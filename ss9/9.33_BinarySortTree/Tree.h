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
Tree InsertNode(Tree_Elemtype node);//插入结点


///////////////////////////////////////////
//为方便在oj提交而写的几个函数
/////////////////////////////////////////
//oj平台的树是数组格式的，但已经按树形格式写好了。为了能在oj上提交，补充一个输入为数组形式的树，之后转换成树形格式
typedef struct Tnode{
    int data;
    int left;
    int right;
}Tnode;
/////////////////   操作    ///////////////////////////////////
Tree oj_InsertNode(int node, Tnode TreeArray[]);//利用数组形式的树，递归插入节点形成树形格式的树
Tree oj_CreatTree();//在oj上输入数组形式的树，产生一棵树形的树


#endif //INC_6_43_EXCHANGESUBTREE_TREE_H

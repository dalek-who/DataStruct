#include <stdio.h>
#include "Tree.h"
#include "Queue.h"

//判断一颗链式树是否是完全二叉树
//原理：对二叉树进行广度优先搜索。完全二叉树的空指针域只在最深的一层以及倒数第二层
// 如果是完全二叉树，则广度遍历到空指针时，后面的全是空指针。如果空指针后面还有非空指针，则不是完全二叉树
#define NotCompelteBinaryTree 0
#define CompleteBinaryTree 1


//oj平台的树是数组格式的，但已经按树形格式写好了。为了能在oj上提交，补充一个输入为数组形式的树，之后转换成树形格式
typedef struct Tnode{
    int data;
    int left;
    int right;
}Tnode;



//利用数组形式的树，递归插入节点形成树形格式的树
Tree InsertNode(int node, Tnode TreeArray[]){
    Tree tree=NULL;
    if( node== 0)
        return NULL;
    else{
        tree = InitTree();
        tree->data = TreeArray[node].data;
        tree->left =InsertNode(TreeArray[node].left,TreeArray);
        tree->right=InsertNode(TreeArray[node].right,TreeArray);
    }

    return tree;
}

//在oj上输入数组形式的树，产生一棵树形的树
Tree oj_CreatTree(){
    Tree tree=NULL;

    //输入用数组表示的树
    //输入结点个数
    int NodeNumber;
    scanf("%d",&NodeNumber);
    Tnode TreeArray[NodeNumber+1];

    //输入每个节点的左右孩子
    for (int i = 1; i <=NodeNumber ; ++i) {
        scanf("%d %d",&TreeArray[i].left,&TreeArray[i].right);
        TreeArray[i].data = i;
    }

    //创建树形树
    tree = InsertNode(1,TreeArray);
    return tree;
}

int IsCompleteBinaryTree(Tree tree){
    //广度优先队列
    Queue WideVisitQueue;
    InitQueue(&WideVisitQueue);
    Tree ptree;
    //首先把根节点入队
    EnQueue(&WideVisitQueue,tree);

    //广度优先遍历，直至遇到空指针
    while (!IsEmptyQueue(&WideVisitQueue)){
        ptree=DeQueue(&WideVisitQueue);
        if(ptree == NULL)
            break;
        else{
            EnQueue(&WideVisitQueue,ptree->left);
            EnQueue(&WideVisitQueue,ptree->right);
        }
    }//while

    //广度优先遍历，看后面的是否全是空指针
    while (!IsEmptyQueue(&WideVisitQueue)){
        ptree = DeQueue(&WideVisitQueue);
        if(ptree == NULL)
            continue;
        else
            return NotCompelteBinaryTree;
    }

    return CompleteBinaryTree;
}

int main() {
//    printf("Hello, World!\n");

    //创建树
    Tree tree;
    /*
    tree = InitTree();
    int root_data;
    printf("input root: ");scanf("%d",&root_data);
    CreatTree(tree,root_data);
    StructDisplayTree(tree);

    //判断是否是完全二叉树
    printf("%s complete binary tree\n",(IsCompleteBinaryTree(tree))?"is":"is not");
    */
    tree = oj_CreatTree();
    printf("%d",IsCompleteBinaryTree(tree));

    return 0;
}
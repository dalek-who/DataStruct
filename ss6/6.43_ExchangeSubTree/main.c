#include <stdio.h>
#include "Tree.h"

//交换左右子树
void ExchangeSubTree(Tree tree){
    //空树：return
    if(tree == NULL)
        return;

        //叶子节点：return
    else if( tree->left == NULL && tree->right == NULL)
        return;
    else{
        //非空非叶子结点：递归交换左右子树。注：交换的不是左右指针指向的内存数据，而是两个指针所指的内存地址
        Tree p;
        p = tree->left;
        tree->left = tree->right;
        tree->right = p;
        ExchangeSubTree(tree->left);
        ExchangeSubTree(tree->right);
    }
    return;
}




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

int main() {
    //printf("Hello, World!\n");

    Tree tree;
    /*
    tree = InitTree();
    int root_data;
    scanf("%d",&root_data);
    CreatTree(tree,root_data);
    StructDisplayTree(tree);

  //  FrontDisplayTree(tree);

    printf("\n");
     */
    tree = oj_CreatTree();
    ExchangeSubTree(tree);
    //StructDisplayTree(tree);
    FrontDisplayTree(tree);

    return 0;
}
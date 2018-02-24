#include <stdio.h>
#include "Tree.h"

//以孩子-兄弟二叉树标示的一般的森林（森林是任意叉的）
//打印森林

/*
void DisplayForest(Tree tree){
    static int deep = 0; //树的深度。定义根节点深度为1
    static char sign[]= "lllllllllllllll";
    //这个数组用来标示第deep层正在遍历的是左还是右子树。l标识正在遍历左子树
    //引入这个数组，是为了在打印树的树枝时确定要不要打印某条树枝。如果没有这个标志，可能会打印出多余的树枝来

    int i;

    for(i=0;i<deep;++i) {
        if(sign[i] == 'l')
            printf("|   ");
        else
            printf("    ");
    }

    if(tree == NULL)
        printf("\n");
    else{
        printf("|---%d\n",tree->data);

        //打印左子树
        //因为是深度优先遍历，所以在进入新一层时++deep，在退出一层时要--deep
        //左结点是孩子，需要增加deep
        ++deep;
        DisplayForest(tree->left);
        --deep;
        sign[deep] = 'r';

        //打印右子树
        //因为是深度优先遍历，所以在进入新一层时++deep，在退出一层时要--deep
        //右孩子是兄弟，不需要增加deep
        DisplayForest(tree->right);
        sign[deep] = 'l';
    }

    return;
};
*/

void DisplayForest(Tree tree){
    static int deep = 0; //树的深度。定义根节点深度为1
    static int flag = 0;
   // static char sign[]= "lllllllllllllll";
    //这个数组用来标示第deep层正在遍历的是左还是右子树。l标识正在遍历左子树
    //引入这个数组，是为了在打印树的树枝时确定要不要打印某条树枝。如果没有这个标志，可能会打印出多余的树枝来

    int i;

    if(tree == NULL)
        ;
    else{

        //打印当前结点
        if(flag!=0)  printf("\n");

        flag=1;
        for(i=0;i<deep;++i)
            printf("0");
        printf("%d",tree->data);

        //打印左子树
        //因为是深度优先遍历，所以在进入新一层时++deep，在退出一层时要--deep
        //左结点是孩子，需要增加deep
        ++deep;
        DisplayForest(tree->left);
        --deep;

        //打印右子树
        //因为是深度优先遍历，所以在进入新一层时++deep，在退出一层时要--deep
        //右孩子是兄弟，不需要增加deep
        DisplayForest(tree->right);
    }//else
    return;
};
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
    int root_data;
    scanf("%d",&root_data);
    tree = InitTree();
    CreatTree(tree,root_data);
     */
    tree = oj_CreatTree();
    DisplayForest(tree);
  //  StructDisplayTree(tree);
    return 0;
}
#include <stdio.h>
#include "Tree.h"
#include "Stack.h"

//通过栈来非递归的遍历树

void StackFrontVisitTree(Tree tree){
    //打印时用的标记
    int flag=0;
    //建立用来遍历树的栈
    Stack FrontVisitStack;
    InitStack(&FrontVisitStack);
    Tree PopTree;
    //树的根节点先入栈
    if( tree != NULL)
        Push(tree,&FrontVisitStack);

    //遍历
    while(!IsEmptyStack(&FrontVisitStack)){
        //弹出一个结点
        PopTree = Pop(&FrontVisitStack);
        //弹出的结点入栈（只把非空结点入栈）
        if( PopTree->right ) Push( PopTree->right , &FrontVisitStack);
        if( PopTree->left )  Push( PopTree->left  , &FrontVisitStack);

        //打印刚才弹出的节点
        printf("%s%d", (flag == 0)?"":" ",PopTree->data);
        if(flag==0) flag=1; //更新flag标记
    }//while

    printf("\n");
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
//    printf("Hello, World!\n");
    Tree tree;
    /*
    tree = InitTree();
    int root_data;
    printf("input root data:");scanf("%d",&root_data);
    CreatTree(tree,root_data);

    StructDisplayTree(tree);

    printf("stack visit:    ");     StackFrontVisitTree(tree);
    printf("recursion visit:"); FrontDisplayTree(tree);
    */
    tree = oj_CreatTree();
    StackFrontVisitTree(tree);
    return 0;
}
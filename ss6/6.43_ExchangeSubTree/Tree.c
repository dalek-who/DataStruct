//
// Created by Administrator on 2017/5/11.
//
#include "Tree.h"

//初始化树（给树赋予根节点）
Tree InitTree(){
    Tree tree;
    tree = (Tree)malloc(sizeof(TreeNode));
    if(!tree)  exit(ERROR);
    tree->left  = NULL;
    tree->right = NULL;
    return tree;
}
////////////////////////////////////////////////////////////////////////////////////
//递归创建一棵树，并为其赋值。Tree本身就是指针类型
// 输入 0 代表没有这个叶子
int CreatTree(Tree tree,Tree_Elemtype data){
    //给该节点的数据域赋值
    if(data == 0)
        return EMPTY;
    tree->data = data;

    //输入左右子树数据
    Tree_Elemtype ldata,rdata;
    scanf("%d %d",&ldata,&rdata);

    //创建子树
    //左子树
    if( ldata!=0 ){
        tree->left = InitTree(); //分配新结点
        CreatTree(tree->left,ldata); //递归创建
    }

    //右子树
    if( rdata!=0 ){
        tree->right = InitTree(); //分配新结点
        CreatTree(tree->right,rdata);
    }

    return UNEMPTY;
}



////////////////////////////////////////////////////////////////////////////////
//先序遍历树
/*
int FrontVisit(Tree tree, int (*visit) (Tree) ){

 //  if(tree == NULL)
    //   return EMPTY;

   //else{
       (*visit)(tree);
        FrontVisit(tree->left, visit(tree->left));

  // }
}
*/
// //////////////////////////////////////////////////////////////////////////////
//结构化地递归打印一棵树（打印出来可以看清楚树的分支结构）
void StructDisplayTree(Tree tree){
    static int deep = 0; //树的深度。定义根节点深度为1
    static char sign[]= "lllllllllllllll";
    //这个数组用来标示第deep层正在遍历的是左还是右子树。l标识正在遍历左子树
    //引入这个数组，是为了在打印树的树枝时确定要不要打印某条树枝。如果没有这个标志，可能会打印出多余的树枝来

    int i;
    /*
    if(tree == NULL){
        for(i=0;i<deep-1;++i) printf("|   ");
        printf("|---\n");
    }
    else{
        for(i=0;i<deep-1;++i) printf("|   ");
        printf("|---%d\n",tree->data);
        DisplayTree(tree->left);
        DisplayTree(tree->right);
    }
    */
    if(tree == NULL)
        printf("\n");
    else{
        printf("%d\n",tree->data);

        //打印左子树
        for(i=0;i<deep;++i) {
            if(sign[i] == 'l')
                printf("|   ");
            else
                printf("    ");
        }
        printf("|---");
        //因为是深度优先遍历，所以在进入新一层时++deep，在退出一层时要--deep
        ++deep;
        StructDisplayTree(tree->left);
        --deep;
        sign[deep] = 'r';

        //打印右子树
        for(i=0;i<deep;++i) {
            if(sign[i] == 'l')
                printf("|   ");
            else
                printf("    ");
            }//else
        printf("|---");
        //因为是深度优先遍历，所以在进入新一层时++deep，在退出一层时要--deep
        ++deep;
        StructDisplayTree(tree->right);
        --deep;
        sign[deep] = 'l';
    }

    return;
};

// //////////////////////////////////////////////////////////////////////////////
//按前序遍历打印出树
void FrontDisplayTree(Tree tree){
    static int flag = 0;
    if(tree == NULL)
 //       printf(" ");
        return;
  //  else if(tree->left == NULL && tree->right == NULL)
    //    return;
    else{
        if(flag == 0) {
            printf("%d", tree->data);
            flag = 1;
        }
        else printf(" %d",tree->data);
        FrontDisplayTree(tree->left);
        FrontDisplayTree(tree->right);
    }
    return;
};

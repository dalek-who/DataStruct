#include <stdio.h>
#include "Tree.h"

//降序输出二叉排序树中大于data的数据
//思路：中序遍历（右，中，左的中序）二叉排序树，结果就是降序排列的

//////////////////////////////////////////////////////////////////////////////////////////
//将结点插入二叉排序树
Tree BinarySortTree_Insert(Tree tree, Tree_Elemtype data){

    if(tree == NULL){
        /*
        Tree new_tree=NULL;
        new_tree = InsertNode(data);
        return new_tree;
         */
        tree = InsertNode(data);
    }
    else{
        if(data <= tree->data)
            tree->left = BinarySortTree_Insert(tree->left,data);
        else
            tree->right = BinarySortTree_Insert(tree->right,data);
    }

    return tree;
}

//////////////////////////////////////////////////////////////////////////////////////////

//由一个数组创建二叉排序树
Tree CreatBinarySortTree(int NodeNumber,Tree_Elemtype DataArray[]) {

    //生成二叉排序树
    Tree tree=NULL;
    for (int j = 0; j <NodeNumber ; ++j) {
        tree=BinarySortTree_Insert(tree,DataArray[j]);
    }

    return tree;

}
//////////////////////////////////////////////////////////////////////////////////////////
//降序输出二叉排序树中大于data的数据
//思路：中序遍历（右，中，左的中序）二叉排序树，结果就是降序排列的
void DisplayLarger(Tree tree,Tree_Elemtype data){
    static int flag = 0;
    if(tree == NULL)
        return;
    else{
        //右
        DisplayLarger(tree->right,data);
        //根
        if(tree->data >= data) {
            printf("%s%d", (flag == 0) ? "" : " ", tree->data);
            flag = 1;
        }
        //左
        DisplayLarger(tree->left,data);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////
int main() {

    //oj输入数据
    //节点数量
    int NodeNumber;
    scanf("%d", &NodeNumber);
    //节点数据
    Tree_Elemtype DataArray[NodeNumber];
    for (int i = 0; i < NodeNumber; ++i)
        scanf("%d", &DataArray[i]);
    //不大于number的数
    int number;scanf("%d",&number);

    //创建二叉排序树
    Tree tree=NULL;
    tree = CreatBinarySortTree(NodeNumber,DataArray);
    //StructDisplayTree(tree);
    DisplayLarger(tree,number);

    return 0;
}
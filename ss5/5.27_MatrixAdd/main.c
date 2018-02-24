#include <stdio.h>
#include "CrossLinkList.h"

//将两个十字链表表示的稀疏矩阵A,B相加，返回得到的新矩阵C
CrLinkList MatrixAdd(CrLinkList MA,CrLinkList MB){
    CrLinkList MC;//最终返回的矩阵
    MC=MA;
    Node *pc=NULL,*pb=NULL; //加法时在C，B两个矩阵中操作的指针
    Node *pc1=NULL;//删除结点时用的辅助结点
    int i;

    //将B加到C上
    for(i=1;i<=MA.mu;++i){
        for(pc=MC.Rhead[i].head->rignt,pb=MB.Rhead[i].head->rignt ; pb!=NULL ;){
            //1 需要插入新结点
            if( pc==NULL || pc->j > pb->j){
                InsertElem(&MC,pb->data,pb->i,pb->j);
                pb = pb->rignt;
            }//if 1

            //2 将pc 向右拨
            else if(pc->j < pb->j)
                pc = pc->rignt;

            //3 将节点上的数字相加
            else if(pc->j == pb->j && pc->data+pb->data!=0){
                pc->data += pb->data;
                pc=pc->rignt;
                pb=pb->rignt;
            }//if 3

            //4 删去为0的结点
            else if(pc->j == pb->j && pc->data+pb->data == 0){
                pc1=pc;
                pc = pc1->rignt;
                pb = pb->rignt;
                DeleteNode(&MC,pc1);
            }//if 4
        }//for 一行相加
    }//for i
    //返回
    return MC;
}

int main() {
//    printf("Hello, World!\n");

    //定义矩阵
    CrLinkList Matrix_A,Matrix_B,Matrix_C;

    //测试用的矩阵
    //十字链表的角标没有0，所以二维数组第0行，第0列空出
    int a[3+1][4+1]=
            {{0,0,0, 0,0},
             {0,1,0,-2,0},
             {0,3,0, 4,1},
             {0,0,0, 8,0}
    },
        b[3+1][4+1]=
            {{0, 0,0,0,0},
             {0,-1,0,1,0},
             {0, 0,7,0,5},
             {0, 1,1,0,0}
            };

    //输入矩阵A
    printf("creat Matrix_A\n");
//    CreatCrLinkList(&Matrix_A);
    ArrayToCrLinkList(&Matrix_A,3,4,a);
    DisplayCrossLinkList(Matrix_A);

    //输入矩阵B
    printf("creat Matrix_B\n");
//    CreatCrLinkList(&Matrix_B);
    ArrayToCrLinkList(&Matrix_B,3,4,b);
    DisplayCrossLinkList(Matrix_B);

    Matrix_C=MatrixAdd(Matrix_A,Matrix_B);
    printf("add:\n");
    DisplayCrossLinkList(Matrix_C);

    return 0;
}
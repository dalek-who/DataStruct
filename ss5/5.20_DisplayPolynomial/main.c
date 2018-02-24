#include <stdio.h>
#include "HignDimArray.h"
#include "LinkList.h"

//用高维数组存储多元多项式，并按降幂将多项式打印出来
//高维数组维度dim是多项式的元数（变量个数），坐标的每个分量表示该变量的次数。数组每个位置存的是一个项的系数

//降幂打印的算法：（将高维数组表示的多项式映射为用链表数组表示的多项式）
// 1.建立一个数组poly[多项式最大次数],该数组每个存储空间poly[i]存储一个链表的头结点。该链表里面存着次数为i的所有项
// 2.将高维数组从头到尾遍历一遍，依次记录下每一项的次数（坐标所有分量的和）和系数i（该坐标处存储的值），存储到poly[i]对应的链表下面
// 3.将这个链表数组倒序打印出来
///////////////////////////////////////////////////////////
//原理示意图：
//  poly[0]    [1]    [2]  [3]    [4]    [5]  （都是头节点）
//       v      v      v    v      v     v
//       0次项  1次项       3次项  4次项  5次项
//       v      v          v      v     v
//       0次项  1次项       3次项  4次项  5次项
//       v                 v      v     v
//       0次项              3次项  4次项  5次项
//       v                 v            v
//       0次项              3次项        5次项
////////////////////////////////////////////////////////////
//  注：dim一开始是不定的，而定义链表节点时节点内存大小需要确定
//     所以在链表节点中不存储一个项的坐标和值，而是用int型存储该项在存储高维数组的一维数组中的位置

//计算次数(计算数组元素的和)
int SumAll(int a[], int size){
    int sum,i;
    for(sum=0,i=0;i<size;++i)
        sum += a[i];
    return sum;
}

//降幂打印多项式
void LowerDisplayPolynomial(HDArray *Polynomial){

    //算出所有点坐标，存入二维数组coord
    int coord[Polynomial->len][Polynomial->dim_info.dim];
    CalAllCoord(Polynomial,coord);
    int i;

    //产生存储相同次数项的链表数组（数组的每个存储单元存储一个链表头结点）
    int max_power;//最大次数
    for(i=0,max_power=0 ; i<Polynomial->dim_info.dim ; ++i)
        //border[i]是第i维坐标分量最多可以取多少个值（0,1,2,....,border[i]-1），可取到的最大值是border[i]-1;
        max_power += Polynomial->dim_info.border[i]-1;
    LinkList poly[max_power+1];//注意+1,否则最大次数会低一次
    //初始化数组中的每一个链表
    for(i=0;i<=max_power;++i)
        InitLinkList(&poly[i]);

    int power;//次数
    //以一维数组的形式遍历多维数组，计算每一项次数i，挂到对应的链表poly[i]下面
    for(i=0;i<Polynomial->len;++i){
        //计算次数
        power = SumAll(coord[i],Polynomial->dim_info.dim);
        //将当前角标挂在对应的链表下面
        TailInsertNode(&poly[power],i);
    }//for

    //打印多项式
    //链表中存的是在高维数组的一维数组角标，所以要回去查对应的值
    int index;
    Node *p;
    for(i=max_power;i>=0;--i){
        //打印
        for(p=poly[i].head->next ; p!=NULL ; p=p->next){
            index = p->data;
            //查找系数并打印
            printf("%d",Polynomial->array[index]);
            //查找坐标并打印
            for (int j = 0; j < Polynomial->dim_info.dim ; ++j) {
                printf("x%dE%d",j,coord[index][j]);//j是第j个未知数，coord[index][j]是该未知数的次数
            }//for j
            printf(" + ");
        }//for p
    }//for i
    printf("\n");
}


int main() {
 //   printf("Hello, World!\n");

    HDArray Polynomial;//多项式
    //创建多项式
    CreatHDArray(&Polynomial);
    //多项式降幂排列打印
    LowerDisplayPolynomial(&Polynomial);

    return 0;
}
//#include <stdio.h>
//荷兰国旗问题，用O(n)的算法，将红，蓝，白的混合序列按顺序排成红、蓝、白三大块
//要求要稳定排序
#include "Queue.h"




//算法：设置一个数组，数组的元素为队列，队列的标号就是color。
// 将FlagArray从头读到尾遍历，每读一个色块，就将这个色块的AnotherColor入相应队列
// 遍历完成后，依次将每个色块队列的元素出队即可
void FlagSort(Flag FlagArray[], int size){
    //队列初始化
    Queue ColorQueue[4];
    for (int i = 0; i <4 ; ++i) {
        InitQueue(&ColorQueue[i]);
    }

    //遍历数组，元素入队
    for (int j = 0; j <size ; ++j) {
        EnQueue(&ColorQueue[ FlagArray[j].color ],FlagArray[j]);
    }

    //队列元素依次出队填入数组
    int m=0;
    for (int k = 1; k <=3 ; ++k) {
        while ( !IsEmptyQueue( &ColorQueue[k] ) ){
            FlagArray[m] = DeQueue(&ColorQueue[k]);
            ++m;
        }
    }
}

void DisplayFlag(Flag FlagArray[], int size){
    static int  flag=0;
    for (int i = 0; i < size; ++i) {
        printf("%s %d %d",(flag==0)?"":"\n",FlagArray[i].color,FlagArray[i].AnotherNumber);
        flag=1;
    }
    return;
}

int main() {
//    printf("Hello, World!\n");
    int size; scanf("%d",&size);
    Flag FlagArray[size];
    for (int i = 0; i <size ; ++i) {
        scanf("%d %d",&FlagArray[i].color,&FlagArray[i].AnotherNumber);
    }

    //排序
    FlagSort(FlagArray,size);

    //打印
    DisplayFlag(FlagArray,size);

    return 0;
}
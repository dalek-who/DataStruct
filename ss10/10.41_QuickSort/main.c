#include <stdio.h>
//#include "Stack.h"
//经过改进的快速排序
//1.长度低于3的子串直接用比较排序
//2.非递归
//3.如果子串已经排好序（没发生交换）这个字串就不继续排序了
//4.如果子串是乱序的，则把长度较短的子串先排序，把另一子串的角标上下界先入栈

typedef struct {
    int key;
    int another;
}SortData;

//交换
void swap(SortData array[],int i,int j){
    SortData temp = array[j];
    array[j] = array[i];
    array[i] = temp;
    return;
}

//比较排序
void CompareSort(SortData array[], int low, int high){
    switch (high - low){
        case 2: //三个元素
            if(array[low].key > array[low+1].key)
                swap(array,low,low+1);
            if(array[low+1].key > array[low+2].key )
                swap(array,low+1,low+2);
            if(array[low].key > array[low+1].key)
                swap(array,low,low+1);
            break;

        case 1:
            if(array[low].key > array[low+1].key)
                swap(array,low,low+1);
            break;

        case 0:
            break;

        default:
            break;
    }//switch
    return;
}

//插入排序的交换过程,通过指针返回的exchange是是否发生交换的标记，mid是最终high == low时的high,
void QuickSort(SortData array[], int low,int high){
    SortData standard = array[low]; //最低位被选为标准
    int low_start=low,high_start=high;
    while (low < high){
        while (low<high && standard.key<=array[high].key)
            --high;
        if(low<high) {
            array[low] = array[high];
        }// while (low<high && standard<=array[high])
        
        while (low<high && array[low].key <= standard.key)
            ++low;
        if(low<high) {
            array[high] = array[low];
        } // while (low<high && array[low] <= standard)

    }//while (low < high)
    
    array[low] = standard;

    int mid = low;
    if(mid-low_start <= 2)
        CompareSort(array,low_start,mid);
    else
        QuickSort(array,low_start,mid);

    if( high_start - (mid+1) <=2 )
        CompareSort(array,mid+1,high_start);
    else
        QuickSort(array,mid+1,high_start);

    return;
}


int main() {
  //  printf("Hello, World!\n");
    int size; scanf("%d",&size);
    SortData array[size];
    for (int i = 0; i <size ; ++i) {
        scanf("%d %d",&array[i].key,&array[i].another);
    }

    QuickSort(array,0,size-1);

    int flag=0;
    for (int j = 0; j <size ; ++j) {
        printf("%s%d %d",(flag==0)?"":"\n",array[j].key,array[j].another);
        flag = 1;
    }
    return 0;
}
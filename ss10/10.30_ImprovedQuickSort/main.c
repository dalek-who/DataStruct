#include <stdio.h>
#include "Stack.h"
//经过改进的快速排序
//1.长度低于3的子串直接用比较排序
//2.非递归
//3.如果子串已经排好序（没发生交换）这个字串就不继续排序了
//4.如果子串是乱序的，则把长度较短的子串先排序，把另一子串的角标上下界先入栈

//交换
void swap(int array[],int i,int j){
    int temp = array[j];
    array[j] = array[i];
    array[i] = temp;
    return;
}

//比较排序
void CompareSort(int array[], int low, int high){
    switch (high - low){
        case 2: //三个元素
            if(array[low] > array[low+1])
                swap(array,low,low+1);
            if(array[low+1] > array[low+2] )
                swap(array,low+1,low+2);
            if(array[low] > array[low+1])
                swap(array,low,low+1);
            break;

        case 1:
            if(array[low] > array[low+1])
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
void QuickSort_exchage(int array[], int low,int high, int* Exchange, int* mid ){
    int standard = array[low]; //最低位被选为标准
    *Exchange = 0;
    
    while (low < high){
        while (low<high && standard<=array[high])
            --high;
        if(low<high) {
            array[low] = array[high];
            *Exchange = 1; //发生交换
        }// while (low<high && standard<=array[high])
        
        while (low<high && array[low] <= standard)
            ++low;
        if(low<high) {
            array[high] = array[low];
            *Exchange = 1; //发生交换
        } // while (low<high && array[low] <= standard)

    }//while (low < high)
    
    array[low] = standard;
    *mid = low;
    return;
}

//改进的快速排序
void Improved_QuickSort(int array[], int size){
    Stack stack; InitStack(&stack);
    ElemType board1,board2,board;
    //先把最外层边界入栈
    board.low=0,board.high=size-1;
    Push(board,&stack);

    int Exchagne;
    int mid;
    while (!IsEmptyStack(&stack)){
        board = Pop(&stack);
        if(board.high - board.low <=2 ){
            CompareSort(array,board.low,board.high);
        } else{
            QuickSort_exchage(array,board.low,board.high,&Exchagne,&mid);
            board1.low = board.low,  board1.high = mid;
            board2.low = mid+1,      board2.high=board.high;

            if(board1.high-board1.low <= board2.high-board2.low){
                Push(board1,&stack);
                Push(board2,&stack);
            } else{
                Push(board2,&stack);
                Push(board1,&stack);
            }//else
        }//else
    }//while
}

int main() {
  //  printf("Hello, World!\n");
    int size; scanf("%d",&size);
    int array[size];
    for (int i = 0; i <size ; ++i) {
        scanf("%d",&array[i]);
    }

    Improved_QuickSort(array,size);

    int flag=0;
    for (int j = 0; j <size ; ++j) {
        printf("%s%d",(flag==0)?"":"\n",array[j]);
        flag = 1;
    }
    return 0;
}
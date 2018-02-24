#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void DisplayArray(int array[],int size){
    int i;
    for(i=1;i<=size;++i)
            printf("%2d, ",i);
    printf("\n");

    for(i=1;i<=size;++i)
            printf("%2d, ",array[i]);
    printf("\n");
}

//大顶堆
int HeapAdjust(int array[],int head,int size){
    int i=head,j=2*i; //i 是双亲，j是孩子中较大的
    int temp=array[head];
    while(j<=size){
    //    DisplayArray(array,size);
        if(j<=size && j+1<=size && array[j+1]>array[j] )
            ++j;

        if(temp<array[j]){
            array[i] = array[j];
            i=j; j=2*i;
        }
        else
            break;
    }
    array[i] = temp;
 //   DisplayArray(array,size);
    return 1;
}

void swap(int array[],int i,int j){
    int temp=array[i];
    array[i]=array[j];
    array[j]=temp;
}

void HeapSort(int array[],int size){
    //数组堆化
    int i;
    for(i=size/2;i>0;--i)
        HeapAdjust(array,i,size);

    //排序
    int now_size;
    for(now_size=size;now_size>1; ){
        swap(array,1,now_size);
        HeapAdjust(array,1,--now_size);
    }


}

int main()
{
   // printf("Hello world!\n");
    srand((unsigned int)time(NULL));
    int size; scanf("%d",&size);
    int array[size+1];
    int i;

    for( i=1;i<=size;++i)
        array[i] = rand()%100;

    for(i=1;i<=size;++i)
        printf("%d, ",array[i]);
    printf("\n");

    HeapSort(array,size);
    DisplayArray(array,size);

    return 0;
}

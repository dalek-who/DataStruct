#include <stdio.h>

void swap(int *a,int *b);

int main() {

    int a[3];
    int i;
    printf("please in put x  ");
    scanf("%d",&a[0]);
    printf("please in put y  ");
    scanf("%d",&a[1]);
    printf("please in put z  ");
    scanf("%d",&a[2]);

    if(a[0]<a[1])
        swap(&a[0],&a[1]);
    if(a[0]<a[2])
        swap(&a[0],&a[2]);
    if(a[1]<a[2])
        swap(&a[1],&a[2]);

    for(i=0;i<3;++i)
        printf("%d  ",a[i]);
    printf("\n");

    return 0;
}

void swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
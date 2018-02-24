#include <stdio.h>
#define MAXINT 0b111111111111111    //最大整数
#define OVERARRAY -1    //数组越界
#define OVERINT -2  //超过最大整数MAXINT
#define ARRSIZE 20  //数组长度

int main() {
    int number,i,n;
    int a[ARRSIZE];
    printf("please input n  ");
    scanf("%d",&n);

    if(n>ARRSIZE) {
        printf("n>arrsize\n");
        return OVERARRAY;//数组越界报错
    }

    a[0]=number=1;
    for(i=1;i<=n-1;++i) {
        number = number * i * 2;
        if(number>MAXINT) {
            printf("when i= %d, i!*2^i>MAXINT\n",i);
            return OVERINT;//超过最大整数范围报错
        }
        a[i]=number;
    }

    for(i=0;i<n;++i)
        printf("a[%d]=%d!*2^%d= %d,",i,i,i,a[i]);
    printf("\n");

    return 0;
}
#include <stdio.h>
#define MAXN 1000
#define ERROR -1

int main() {
   // printf("Hello, World!\n");
    int n,x,result;
    int a[MAXN+1];
    if(CreatPolynomial(a,&n,&x)==ERROR){
        printf("error n is too large");
        return ERROR;
    } else{
        result=CaculatePolynomial(a,n,x);
        printf("result = %d",result);
    }
    return 0;
}

//创建多项式
int CreatPolynomial(int a[],int *n,int *x){
    int i;
    printf("please input x  ");scanf("%d",x);
    printf("please input n  ");scanf("%d",n);

    if(*n>MAXN)//次数超过上限，报错
        return ERROR;
    else{
        for(i=0;i<=*n;++i){
            printf("input a%d = ",i);scanf("%d",&a[i]);
        }//for
    }
    return 0;

}

//计算多项式的值
int CaculatePolynomial(int a[],int n,int x){
    int i, result=0;
    for(i=n;i>=0;--i){
        result=x*result+a[i];
    }
    return result;



}
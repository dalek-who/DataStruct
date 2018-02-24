#include <stdio.h>

//求一个递归函数
int Function(int n){
    int f,fn;
    if(n==0)
        return 1;
    else{
        f=Function(n/2);
        fn=n*f;
        printf("n=%d,\tf(n/2)=%d,\t\tfn=%d\n",n,f,fn);
        return n*f;
    }
}

int main() {
    //printf("Hello, World!\n");
    int n,fn;
    scanf("%d",&n);
    fn=Function(n);
    printf("\nfn=%d\n",fn);
    return 0;
}
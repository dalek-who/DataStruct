//
// Created by wang on 17-3-17.
//
#include "Stack.h"

//非递归版，通过栈来实现，将中间过程产生的n/2入栈，之后再依次出栈乘回来
int NotRecursionFunction(int n){
    int middle_n,middle_fn;
    Stack stack;
    middle_n=n;
    InitStack(&stack);
    //将中间的n/2入栈
    for(; middle_n!=0; middle_n/=2)
        Push(middle_n,&stack);

    middle_fn=1;

    //依次出栈乘回来
    while (!IsEmptyStack(&stack)){
        middle_n=Pop(&stack);
        middle_fn*=middle_n;
   //     printf("n=%d,f(n)=%d\n",middle_n,middle_fn);
    }
    return middle_fn;
}

//递归版
int RecursionFunction(int n){
    if(n==0)
        return 1;
    else {
        return n * RecursionFunction(n / 2);
    }
}

int main(){
    int n,nr_fn,r_fn;
    scanf("%d",&n);

    nr_fn=NotRecursionFunction(n);
    r_fn=RecursionFunction(n);

    printf("not recursion f(n)= %d\n", nr_fn);
    printf("    recursion f(n)= %d\n", r_fn);
    printf("%s\n", (nr_fn == r_fn) ? "equal" : "unequal");

    return 0;
}
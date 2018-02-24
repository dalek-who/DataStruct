//
// Created by wang on 17-3-9.
//
#include "Stack.h"
#include "Tree.h"

//栈的数据结构定义
/*
 typedef struct stack{
    ElemType * base;//栈底（栈的数组基地址）
    ElemType * top;//栈顶指针
    int size;//尺寸
    int used;//已用空间
} Stack;
 */

/////////////////////////////////////////////////////////////////
//初始化栈
int InitStack(Stack * stack){
    stack->base=(ElemType*)malloc(STACK_INIT* sizeof(ElemType));
    if(!stack->base)
        exit(ERROR);
 //   stack->top=stack->base;
    stack->size=STACK_INIT;
    stack->used=0;
    return OK;
}
/////////////////////////////////////////////////////////////////
//扩容
int EnlargeStack(Stack * stack){
    ElemType *newbase;
    newbase=(ElemType *)realloc(stack->base,(stack->size+INCREASE)*sizeof(ElemType));
    if(!newbase)
        exit(ERROR);
    stack->base=newbase;
    stack->size+=INCREASE;
    return OK;
}
/////////////////////////////////////////////////////////////////
//打印
/*
void DisplayStack(Stack * stack){
    int i;
    if(IsEmptyStack(stack)) {
        printf("empty stack\n");
        return;
    } else {
        for (i = 0; i < stack->used; ++i) {
            printf("%d..", i);
            printf("%c  ", stack->base[i]);
        }
        printf("\n");
    }
}
 */
/////////////////////////////////////////////////////////////////
//入栈
void Push(ElemType c,Stack *stack){
    //容量不足则先扩容
    if (stack->used + 1 > stack->size)
        EnlargeStack(stack);
    //插入
    stack->base[stack->used] = c;
    ++stack->used;
 //   ++stack->top;
}

/////////////////////////////////////////////////////////////////
//出栈
ElemType Pop(Stack* stack){
    //如果是空栈
    ElemType c;
    if(IsEmptyStack(stack)) {
        printf("ERROR:empty stack can`t be Poped\n");
        return '\0';
    }//if
    //弹出栈顶元素，刷新栈的信息
    else{
        /*
        --stack->top;
        c=*stack->top;
        --stack->used;
        *stack->top='\0';
         */
  //      --stack->top;
        c=stack->base[stack->used-1];
        --stack->used;
        return c;
    }
}
/////////////////////////////////////////////////////////////////
//访问栈顶元素(并返回)但不出栈
ElemType VisitTop(Stack* stack){
    //空栈
    if(IsEmptyStack(stack))
        return '\0';
        //非空
    else
        return stack->base[stack->used-1];
}
/////////////////////////////////////////////////////////////////
//判断是否为空栈
int IsEmptyStack(Stack* stack) {
    if (stack->used==0)
        return EMPTY;
    else
        return UNEMPTY;
}
/////////////////////////////////////////////////////////////////
//将整个栈拷贝给一个数组
void CopyStack(Stack* stack, ElemType s[]){
    int i;
    for(i=0;i<stack->used;++i)
        s[i]=stack->base[i];
}
/////////////////////////////////////////////////////////////////
//
// Created by wang on 17-3-9.
//
////////////////////////////
//char类型的栈
//通过动态数组实现
////////////////////////////
#ifndef INC_2_11_INSERT_STACK_INT_H
#define INC_2_11_INSERT_STACK_INT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_INIT 10   //初始最大容量
#define INCREASE 5 //每次扩充容量
#define ERROR 0 //错误
#define OK 1    //正确
#define EMPTY 1//空栈
#define UNEMPTY 0//非空栈
#define UNFIND  -1 //查找未找到

//元素类型
typedef int ElemType;


//顺序表
//结构的定义
typedef struct stack{
    ElemType * base;//栈底（栈的数组基地址）
 //   ElemType * top;//栈顶指针
 /*BUG： 在用realloc扩容时，base的地址变了。如果top地址没有随之变化，会出现很奇怪的bug
  *而Pop和Push用base[used-1]就可以实现了，没必要再用top指针（也没有任何一个函数用到top）
  *于是，top就暂时禁用了
  */
    int size;//尺寸
    int used;//已用空间
} Stack;



//各种操作
int InitStack(Stack * list) ;//顺序表初始化
int EnlargeStack(Stack * list);//扩容
void DisplayStack(Stack * list);//display顺序表
void Push(ElemType c,Stack *stack);//入栈
ElemType Pop(Stack* stack);//出栈
ElemType VisitTop(Stack* stack);//访问栈顶元素(并返回)但不出栈
int IsEmptyStack(Stack* stack);//判断是否为空栈
void CopyStack(Stack* stack, ElemType s[]);//将整个栈拷贝给一个数组


#endif //INC_2_11_INSERT_Stack_INT_H

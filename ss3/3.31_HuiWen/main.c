//判断一个字符串是否是“回文”，即正读和反读都一样的字符串，
//该字符串以@结尾
//例子：abbbcbbba@是回文，abbbcbba不是回文
#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

#define ISHUIWEN 1
#define NOTHUIWEN 0
#define MAXSTRING 100

//判断回文的方法：
//创建一个队列和一个栈，将字符从头到尾入队和入栈，之后出队出栈，看每次弹出的元素是否相同

int IsHuiWen(char s[]){
    Stack stack;
    Queue queue;
    int i;
    char cs,cq;
    //初始化
    InitStack(&stack);
    InitQueue(&queue);

    for(i=0;s[i]!='@';++i){
        //将字符串每个字符依次入队入栈
        Push(s[i],&stack);
        EnQueue(&queue,s[i]);
 //       printf("Stack:");DisplayStack(&stack);
 //       printf("Queue:");DisplayQueue(&queue);
    }
    while(!IsEmptyStack(&stack)){
        cs=Pop(&stack);    //栈从尾往回读
        cq=DeQueue(&queue); //队列从头往尾读
 //       printf("Stack:");DisplayStack(&stack);
   //     printf("Queue:");DisplayQueue(&queue);
        if (cs!=cq)
            return NOTHUIWEN;
        else
            continue;
    }
    return ISHUIWEN;
}


int main() {
    //printf("Hello, World!\n");
    char s[MAXSTRING];
    int result;
    scanf("%s",s);
    result=IsHuiWen(s);
    printf("%s HuiWen\n",(result==OK)?"is":"is not");
    return 0;
}

/*
int main(){
    char s[MAXSTRING];
    int i;
    char c;
    Stack stack;
    InitStack(&stack);
    scanf("%s",s);
    for(i=0;s[i]!='#';++i)
        Push(s[i],&stack);
    DisplayStack(&stack);
    while (!IsEmptyStack(&stack)){
        c=Pop(&stack);
        printf("%c  ",c);
    }
    return 0;
}
 */
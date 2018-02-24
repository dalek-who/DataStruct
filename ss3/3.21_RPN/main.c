//将普通表达式转化为逆波兰表达式（RPN）
#include <stdio.h>
#include "Stack.h"
#define LARGER 1    //大于
#define SMALLER -1  //小于
#define EQUAL 0     //等于
#define MAXARRAY 100

//有误
//注：同级的运算符（如+，-）也是有优先级的，先读到的比后读到的优先级高。
// 例如：1+2-3中，要先算加法才能做减法，所以这里+优先级高（若是1-2+3，则是-优先级高，即：同级的 先读的比后读的优先级高）
//按照优先级，给各种运算符编码。数字越大，优先级越高
int CodingOperate(char operator){
    switch(operator) {
        case '#':
            return 0;
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 3;
        case ')':
            return 4;
        default: {
            printf("error input\n");
            exit(-1);
        }//default
    }//switch
}

//按照对各符号的编码，对优先级进行比较
int CompareOperate(char a,char b){
    int code_a,code_b;
    //按照优先级编码
    code_a=CodingOperate(a);
    code_b=CodingOperate(b);
    //比较优先级
    if(code_a>code_b)
        return LARGER;
    else if(code_a<code_b)
        return SMALLER;
    else
        return EQUAL;
}

//转换为逆波兰表达式RPN
void RPN_translate(char from[], char result[]){
    Stack NumberStack,OperatorStack;//变量栈，表达式栈
    char c;
    int i;
    //栈的初始化
    InitStack(&NumberStack);
    InitStack(&OperatorStack);
    //转换
    for(i=0;from[i]!='#';++i){
        printf("N_Stack:");DisplayStack(&NumberStack);printf("O_Stack:");DisplayStack(&OperatorStack);

        printf("\n");
        switch (from[i]){

            case '(': {
                //入栈
                Push(from[i], &OperatorStack);
                break;
            }

            case ')':{
                //将运算符出栈，并依次入表达式栈，直到遇见（。（弹出但不入表达式栈
                for(c=Pop(&OperatorStack); c!='('; c=Pop(&OperatorStack))
                    Push(c,&NumberStack);
                break;
            }//case')'
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
                    {
                        //空栈：入栈
                if(IsEmptyStack(&OperatorStack))
                    Push(from[i],&OperatorStack);
                    //优先级大于栈顶元素：入栈
                else if( CompareOperate( from[i],VisitTop(&OperatorStack))>0 )
                    Push(from[i],&OperatorStack);
                    //优先级小于等于栈顶元素：将栈顶元素依次出栈，压入表达式栈，直到form[i]优先级大于等于运算符栈顶(或者栈空)
                else{
                    //表达式栈出栈
                    while (CompareOperate( from[i],VisitTop(&OperatorStack) ) <= 0 || !IsEmptyStack(&OperatorStack)){
                        c=Pop(&OperatorStack);
                        Push(c,&NumberStack);
                    }//while
                    //form[i]入栈
                    Push(from[i],&OperatorStack);
                }//else
                         break;

            }//case运算符
            default: //变量
                //入表达式栈
                Push(from[i],&NumberStack);
        }//switch
    }//for

 //   printf("after #\n");
    //将运算符中剩下的元素依次弹出并压入表达式栈
    while ( !IsEmptyStack(&OperatorStack) ){
        printf("N_Stack:");DisplayStack(&NumberStack);printf("O_Stack:");DisplayStack(&OperatorStack);

        printf("\n");
        c=Pop(&OperatorStack);
        Push(c,&NumberStack);
    }//while

    //将表达式栈拷贝给result[]
    CopyStack(&NumberStack,result);
}

int main() {
   // printf("Hello, World!\n");
    char input[MAXARRAY],result[MAXARRAY];
    scanf("%s",input);
    RPN_translate(input,result);
    printf("%s",result);
    return 0;
}























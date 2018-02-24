//p判断一个“字符串1&字符串2@”是否对称。
// 例：123ab&ba321@对称，123ab&ab321@不对称
// &是分隔符，@是结束符
#include <stdio.h>
#include "Stack.h"
#define SYMMETRY 1
#define UNSYMMETRY 0
#define MAXSTRING 100

//要求s必须为标准格式：字符串1&字符串2@
//如果输入格式不标准可能会判断出错
int IsSymmetry(char s[]){
    Stack stack;
    int i;
    char c;
    InitStack(&stack);
    //读到&前先入栈
    for(i=0;s[i]!='&';++i) {
        Push(s[i], &stack);
//        DisplayStack(&stack);
    }

    if(s[i]!='&') {
        printf("ERROR,wrong input\n");
        exit(ERROR);
    } else
        ++i;

    for(;s[i]!='@';++i){
        //空栈表明后面的段更长，不对称
        if(IsEmptyStack(&stack))
            return UNSYMMETRY;
        else {
            c = Pop(&stack);
//            DisplayStack(&stack);
            //符号不同导致的不对称
            if (c != s[i])
                return UNSYMMETRY;
            else
                continue;
        }//else
    }//for

    if(s[i]=='@') {
        //读完了还没空，说明前面的串长，不对称
        if( !IsEmptyStack(&stack) )
            return UNSYMMETRY;
        //全都读完后栈空了，对称
        else
            return SYMMETRY;
    }
    else{
        printf("ERROR: wrong input\n");
        exit(ERROR);
    }
}

int main() {
//    printf("Hello, World!\n");
    int result;
    char s[MAXSTRING];
    scanf("%s",s);
    printf("%s\n",s);
    if( IsSymmetry(s) )
        printf("字符串对称\n");
    else
        printf("字符串不对称\n");
    return 0;
}
















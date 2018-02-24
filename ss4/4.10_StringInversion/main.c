#include <stdio.h>
#define MAXSTRING 100   //串的最大长度

//对将一个串求逆，赋给另一个串

void Inversion(char inversion_s[],char s[]){
    int i,len;
  //  inversion_s[0]=s[0];
    //找到s的尾端
    for(len=0;s[len]!='\0';++len)
        ;
    for(i=0;i<len;++i)
        inversion_s[i]=s[len-1-i];
    inversion_s[i]='\0';
}

int main() {
    //printf("Hello, World!\n");
    char s[MAXSTRING] ;//= "12345";
    printf("s:        ");scanf("%s",s);
    char inversion_s[MAXSTRING];
    Inversion(inversion_s,s);
    printf("inversion:");puts(inversion_s);

    return 0;
}
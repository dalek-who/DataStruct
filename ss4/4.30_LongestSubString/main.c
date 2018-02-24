#include <stdio.h>
#include "SqList.h"
#define MAXSTRING 100
//找出一个串中最长的重复子串
//算法：利用KMP算法，依次以字符串s[SIZE]的每一个元素作为开头，可得到SIZE个子串
//分别计算这些子串的KMP_next值，找出最大的KMP_next值
//KMP_next[j]表示string[0]~string[j-1]中最长的相同前后缀的长度
//以s[]的每个元素起头算出的KMP_next，找出最长的相同前后缀，就是最长的重复子串
// （注:原始的KMP_next没有到最后一个元素string[len-1]的最大相同前后缀。
// 于是，我们在字符串结尾再加一个字符，再求next，就可以把到string[len-1]的最大重复前后缀求出来了)
// *****  时间复杂度：O( strlen(s)^2 ) *****  (求KMP_next复杂度O( strlen(s) ),一共操作strlen(s)次)

//字符串
typedef struct StringType{
    char string[MAXSTRING];//字符串
    int len;    //字符串长度（不包括\0）
}String;

//Next结构体
typedef struct  NextArrayType{
    int next[MAXSTRING];
    int len;
}NextArray;

//最大点的数据和角标
typedef struct Max{
    int data;   //数据
    int index;  //角标
}Max;


NextArray GetNext(char pattern[], int size){
    int j=0,k=-1;
    NextArray nextArray;

    nextArray.next[0]=-1;
    while(j<size){
        if((k == -1) || pattern[j] == pattern[k] ){
            ++j;++k;
           nextArray.next[j]=k;
        } //if
        else
            k = nextArray.next[k];
    }//while
    nextArray.len=size;
    return nextArray;
}//GetNext


//找出一个整型数组中的最大数据及其角标
Max FindMax(int a[], int size){
    Max the_max;
    int i;
    for(i=0, the_max.data=a[0], the_max.index=0;
            i<size;
            ++i){
        //如果有更大的数据，则更新the_max
        if(a[i]>the_max.data){
            the_max.data=a[i];
            the_max.index=i;
        }//if
        else
            continue;
    }//for
    return the_max;
}

void LongestSubString(String s,String *sub_string){
    int i,j;
    int longest_sub[s.len];
    NextArray nextArray;
    Max     max_next,//每一个next中的最大值
            max_sub;//最长的重复子串起始位置以及长度
    SqList list;
//    NextArray nextArray;

    //把串是变成顺序表，并再插入一个元素
    CreatMyList(&list,s.string,s.len);
    TailInsert('a',&list);

    //求每个s[i]起始的next[]，并找到每个next[]中的最大值存入longest_sub[]
    for(i=0;i<s.len;++i){
        //求每个s[i]起始的next[]
        nextArray=GetNext(list.list+i,list.used);
        //找到每个next[]中的最大值
        max_next=FindMax(nextArray.next,nextArray.len);
        //最大值存入longest_sub[]
        longest_sub[i]=max_next.data;
    }//for

    //max_sub.index是最长重复子串的起始角标s[index],max_sub.data是最长重复子串的长度
    max_sub=FindMax(longest_sub,s.len);

    //给找到的sub_string赋值
    for(j=0;j<max_sub.data;++j)
        sub_string->string[j]=s.string[max_sub.index+j];
    sub_string->string[j]='\0';
    sub_string->len=max_sub.data;
}

int main() {
  //  printf("Hello, World!\n");

    String s,longest_substring;
    //输入
    scanf("%s",s.string);
    s.len= (int) strlen(s.string);
    //生成最大重复子串
    LongestSubString(s,&longest_substring);
    printf("%s\n",longest_substring.string);
    return 0;
}
//
// Created by Administrator on 2017/4/10.
//
//广义表(链式表示)
#ifndef INC_5_37_DELETEATOMX_GLIST_H
#define INC_5_37_DELETEATOMX_GLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Stack.h"

#define ERROR 0
#define OK 1
#define EMPTY 1
#define UNEMPTY 0

//////////////////////////////////////////////////////////////////////////////////////////
//结构体定义

//原子节点的数据类型
typedef char GL_AtomType;

//节点的类型标签（原子or表），采用枚举类型来定义
//ATM是ATOM的简写。因为在被自动引用的库函数winbase.h中也有一个被定义为ATOM的宏，如果此处命名为ATOM会有冲突
typedef enum {ATM,LIST} ElemTag;//ATM==0,原子;LIST==1，子表

//广义表数据结构
typedef struct GList{
    ElemTag tag;//结点标签：原子or子表
    //数据域：原子类型的数据，或者子表。如果是子表
    union {
        //原子数据
        GL_AtomType atom;
        //子表。把一个表结点分为两部分：head是里面的第一个元素组成的子表，tail是之后所有元素组成的子表
        struct {struct GList *head,*tail;}ptr;
    };
}GList;

//////////////////////////////////////////////////////////////////////////////////////////
//基本操作
int InitGList(GList *gList);//初始化(初始化为空表结点）
void severe(char **head, char **tail, char s[]);//剥离字符串形式的广义表，将其剥离为表头、表尾两个字符串
GList* StringToGList(char s[]);//由字符串形式的广义表生成真正的广义表结构
void DisplayGList(GList *list);//以带括号的字符串的方式打印广义表
void FreeNode(GList* list);//释放结点

#endif //INC_5_37_DELETEATOMX_GLIST_H

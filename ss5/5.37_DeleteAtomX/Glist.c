//
// Created by Administrator on 2017/4/10.
//

//广义表
#include "Glist.h"

//空表，用于比较用
char empty_list[]="()";

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//初始化(初始化为空表结点）
int InitGList(GList *gList){
    gList = (GList*)malloc(sizeof(GList));
    if(!gList)
        exit(ERROR);
//    gList->tag = LIST; gList->ptr.head=NULL; gList->ptr.tail=NULL;
    return OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//剥离字符串形式的广义表，将其剥离为表头、表尾两个字符串
//默认输入的s格式是正确的。如果不正确有可能会出发报错结束程序
//剥离出来的几种情况的字符串：1.原子：a  2.非空表：（a,b,c,(d,e,(f,g,()),h)).注：实际没有括号 3.空表：（）
//要用到栈结构
void severe(char **head, char **tail, char s[]){
    //用来存储head字符串的栈、用来存储括号的栈
    Stack head_st,bracket_st;
    InitStack(&head_st);
    InitStack(&bracket_st);
    int i;

    //几种错误情况（可能不全)
    if(s[0]!='(' || s[strlen(s)-1]!=')' ){
        printf("error input s\n");
        exit(ERROR);
    }

    //剥离出头表的子串
    //每个表都是以s[0]=='('打头，所以要从s[1]开始
    i=1;
    do{
        //将元素压入头表的字符串
        Push(s[i],&head_st);
        //通过匹配左右括号来判断一个子表是否已读完
        //会剥离出三种情形：
        //1.s[1]不是括号，则表头是个原子节点。此时没有符号被压入括号栈，do结束时是空栈，于是剥离完成
        //2.s[1]是左括号：如果下一个是右括号，则下一次do执行完栈就空了，得到一个空表()
        //3.s[1]是左括号：如果下一个不是是右括号，最后括号站清空时得到的就是非空子表(......)
        switch (s[i]){
            case '(':
                Push(s[i],&bracket_st);
                break;
            case ')':
                Pop(&bracket_st);
                break;
            default:
                break;
        }
        ++i;
    }while (!IsEmptyStack(&bracket_st));
    //将头表栈中的字符串拷贝出来复制给头表
    char phead[head_st.used+1];
    CopyStack(&head_st,phead);
    //复制出来的temp后面是没有'\0'的，要补上
    phead[head_st.used]='\0';

    //**********bug***************
    //todo
    *head = phead;
    //至此头表剥离完成


    //剥离出尾表的子串
    //先给tail赋值个(
    char ptail[strlen(s)-strlen(phead)+1];
    strcpy(ptail,"(");
    //把s剥离出head后剩下的部分连接到tail的（后面
    strcat(ptail,&s[strlen(phead)+1]);
    *tail = ptail;
    //至此尾表剥离完成
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//由字符串形式的广义表生成真正的广义表结构
GList* StringToGList(char string[]){
    char s[strlen(string)+1];
    strcpy(s,string);
    //创建新的表结点并先初始化为空表
    GList *list;
    list=(GList*)malloc(sizeof(GList));
    list->tag=LIST;
    list->ptr.head=NULL;
    list->ptr.tail=NULL;

    //空节点：
    if( strcmp(s,empty_list)==0 ) {
        return NULL;
    }

    //原子节点
    else if( strlen(s)==1 ){
        list->tag=ATM;
        list->atom=s[0];
        return list;
    }

    //非空表
    else {
        //从s分离出来的表示头、尾表的数组
        char *head_s = NULL,*tail_s=NULL;
        //剥离出头尾字符串
        severe(&head_s, &tail_s, s);
        //severe剥离出来的东西是在head_s,tail_s两个指针里的，需要把它们拷贝到真正的数组里
        //虽然很麻烦，但如果不这样做，运行时会出现很奇怪的错误。并不知道原因，只知道复制一下就不会出错了
        char head[strlen(head_s)+1],tail[strlen(tail_s)+1];
        strcpy(head,head_s);strcpy(tail,tail_s);

        list->tag = LIST;
        //递归处理头尾表
        list->ptr.head = StringToGList(head);
        list->ptr.tail = StringToGList(tail);
        return list;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//以带括号的字符串的方式打印广义表
//打印出的可能和输入的是两种不同的形式
//原因：因为广义表本身就有两种构造
// 例如：输入的(bcd(e()))是有同层次结点的一种构造，而打印出(b(c(d((e())))))是只分头尾结点的构造
void DisplayGList(GList *list){
        //空表
    if(list==NULL) {
        printf("()");
        return;
    }

        //原子
    else if(list->tag==ATM){
        printf("%c",list->atom);
        return;
    }

        //非空
    else{
        //递归打印子表
        printf("(");
        DisplayGList(list->ptr.head);
        DisplayGList(list->ptr.tail);
        printf(")");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//释放结点
void FreeNode(GList* list){
    free(list);
    list=NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

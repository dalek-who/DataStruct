#include <stdio.h>
#include "LinkList.h"

#define LARGER 1
#define SMALLER -1
#define EQUAL 0

//将串from(数组形式）赋值给串to（链表形式）
void StrAssign(LinkList *to,char s[]){
        int i;
        InitLinkList(to);
        for(i=0;s[i]!='\0';++i)
            TailInsertNode(to,s[i]);
}

//将串from复制给串to
//将原有的to销毁掉，生成一个新的复制得到的串给to
void StrCopy(LinkList *to,LinkList *from){
    Node *p;//删去剩余
    LinkList newlist;
    DestroyList(to);
    //创建新的链表
    InitLinkList(&newlist);
    //from是空串，直接返回
    if(IsEmptyList(from)) {
        *to = newlist;
        return;
    }
    else{
        //from从头往尾读，newlist从尾部插入新节点
        for(p=from->head->next;p!=NULL;p=p->next)
            TailInsertNode(&newlist,p->data);
        *to = newlist;
        return;
    }
}

//比较两字符串大小
int StrCompare(LinkList listA,LinkList listB){
    Node *pa,*pb;
    for(pa=listA.head->next,pb=listB.head->next ; pa!=NULL && pb!=NULL ; pa=pa->next,pb=pb->next){
        if(pa->data > pb->data)
            return LARGER;
        else if(pa->data < pb->data)
            return SMALLER;

        else
            continue;
    }
    if(pa!=NULL && NULL == pb)
        return SMALLER;
    else if(NULL == pa && pb != NULL)
        return LARGER;
    else
        return EQUAL;
}

//返回字符串的长度
int StrLength(LinkList *listA){
    return listA->len;//链表的结构体定义中本身就有链表长度
}

//将字符串拼接，返回得到的字符串
LinkList Concat(LinkList listA,LinkList listB){
    LinkList newlist;
    Node *p;
    InitLinkList(&newlist);
    //尾部插入所有A元素
    for(p=listA.head->next ; p!=NULL ; p=p->next)
        TailInsertNode(&newlist,p->data);
    //尾部插入所有B元素
    for(p=listB.head->next ; p!=NULL ; p=p->next)
        TailInsertNode(&newlist,p->data);
    return newlist;
}

//返回字符串从第start个元素开始的长度为len的子串
LinkList SubString(LinkList listA, int start, int len){
    LinkList sublist;
    Node *p;
    int newstart,newlen;
    if(start<=0 || start>listA.len || len<0 || len>(listA.len-start+1) ) {
        printf("start or len out of size\n");
        exit(ERROR);
    }
    else{
        InitLinkList(&sublist);
        //跳过前面的元素
        for(p=listA.head->next ,newstart=1 ; p!=NULL && newstart < start ; p=p->next,++newstart)
            ;
        //从尾部插入子串
        for(newlen=0;newlen<len;++newlen,p=p->next)
            TailInsertNode(&sublist,p->data);
        return sublist;

    }

}

int main() {
    //printf("Hello, World!\n");
    char a[]="abcdefg",
         b[]="abe123456789";
    LinkList listA,listB;
    LinkList sublist,concatlist,copylist;
    char c;
    int result;
    //初始化创建并赋值两个链表

   // CreatMyList(&listA, a, (int) strlen(a));
   // CreatMyList(&listB, b, (int) strlen(b));
   // CreatMyList(&copylist, a, (int) strlen(a));
    //test

    //StrAssign
    StrAssign(&listA,a);
    StrAssign(&listB,b);
    StrAssign(&copylist,a);
    printf("(1):  StrAssign(&listA,a);\n");
    printf("a:    ");puts(a);
    printf("listA:");DisplayLinkList(&listA);
    printf("b:    ");puts(b);
    printf("listB:");DisplayLinkList(&listB);
    //StrCopy
    printf("\n");
    printf("(2):  StrCopy(&copylist,&listB);\n");
    printf("before copy : copylist:");DisplayLinkList(&copylist);
    StrCopy(&copylist,&listB);
    printf("after  copy : copylist:");DisplayLinkList(&copylist);
    printf("\n");

    //StrCompare
    printf("(3):  StrCompare(listA,listB)\n");
    result=StrCompare(listA,listB);
    if(result>0)
        c='>';
    else if (result==0)
        c='=';
    else
        c='<';
    printf("A %c B\n",c);
    printf("\n");

    //Strlen
    printf("(4):  StrLen\n");
    printf("StrLength(&listA): %d\n",StrLength(&listA));
    printf("StrLength(&listB): %d\n",StrLength(&listB));
    printf("\n");

    //Concat
    printf("(5):  Concat(listA,listB);\n");
    concatlist=Concat(listA,listB);
    DisplayLinkList(&concatlist);
    printf("\n");

    //SubString
    printf("(6):  SubString(listB,5,4);\n");
    sublist=SubString(listB,5,4);
    DisplayLinkList(&sublist);
    printf("\n");
    return 0;
}











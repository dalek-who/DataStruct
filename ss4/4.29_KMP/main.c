//用链表实现模式匹配的KMP算法

#include <stdio.h>
#include "DoubleLinkList.h"
#define UNFIND -1 //未找到
#define MAXSTRING 100
/*
typedef struct KMP_Node{
    Node node;  //一个链表节点，包括node(数据data，后继指针next，前驱指针succ
    Node *next;  //KMP算法失陪时的next
}KMP_Node;
*/

//打印KMP求next后得到的链表
void KMP_DisplayLinkList(LinkList *list){

    Node* p;
    int count;

    //先获取每个节点的index
    GetIndex(list);

    //如果list本身是空表
    if(list->tail==list->head){
        printf("0..Head***Tail  {Empty LinkList}\n");
        return;
    }
    //如果不是空表
    //打印数据
    printf("0..Head");
    for(p=list->head->next,count=1;
        p!=NULL;
        p=p->next,++count){
        printf(" -> %d..%c",count,p->data);
    }//for
    printf("***Tail\n");

    //打印KMP_next的值
    printf("0..Head");
    for(p=list->head->next,count=1;
        p!=NULL;
        p=p->next,++count){
        printf(" -> %d..%d",count,p->KMP_next->index);
    }//for
    printf("***Tail\n");
}


//获取模式串pattern每个元素KMP算法中的next值。
// 在定义链表的节点时，节点的数据中就有KMP_next域。在主串s中也有KMP_next域，但一开始生成的所有链表节点的KMP_next域都置NULL
void GetNext(LinkList *pattern){
    Node *pk,*pj;
    if(IsEmptyList(pattern))
        return;
    //链表非空：
    pj=pattern->head->next;
    pk=pattern->head;
    pj->KMP_next=pattern->head;
    while (pj!=pattern->tail ) {
        if (pk == pattern->head || pj->data == pk->data) {
            pj = pj->next;
            pk = pk->next;
            pj->KMP_next = pk;
        }//if
        else
            pk=pk->KMP_next;
    }//while

    //打印得到的KMP_next
    //KMP_DisplayLinkList(pattern);
}//GetNext

//KMP算法
int KMP(LinkList main_string,LinkList *pattern, int pos){
    Node *ps,*pt;
    int find;

    if(pos>main_string.len || IsEmptyList(&main_string) || IsEmptyList(pattern) )
        return UNFIND;

    //算出pattern每个节点的KMP_next
    GetNext(pattern);

    GetIndex(&main_string);

    //先将ps移动到第pos个节点
    for(find=0,ps=main_string.head;find<pos;++find,ps=ps->next)
        ;
    pt=pattern->head->next;

    //KMP主体
    while(ps!=main_string.tail && pt!=pattern->tail){
        //一个字符匹配上了，或者向右移动pattern移动到了头
        if( pt==pattern->head || ps->data==pt->data){
            ps=ps->next;
            ++find;
            pt=pt->next;
        }
            //没匹配上：向右移动pattern，使已匹配的部分的前缀对上与前缀相同的后缀
        else
            pt=pt->KMP_next;
    }
    //匹配成功
    if(pt==pattern->tail)
        return find-pattern->len+1;
    //匹配不成功
    else
        return UNFIND;
}


//KMP算法
int main() {
    //printf("Hello, World!\n");
 //   char s[]="abcdddabcabcdddabdabc",
  //      pattern[]="abcdddabdabc";
    char s[MAXSTRING],pattern[MAXSTRING];
    LinkList list_s,list_pattern;
    int find;

    printf("input main    string :  ");scanf("%s",s);
    printf("input pattern string :  ");scanf("%s",pattern);
    CreatMyList(&list_s, s, (int) strlen(s));
    CreatMyList(&list_pattern, pattern, (int) strlen(pattern));

 //   DisplayLinkList(&list_s);
//    DisplayLinkList(&list_pattern);

    find=KMP(list_s,&list_pattern,0);
    printf("%d\n",find);

    return 0;
}























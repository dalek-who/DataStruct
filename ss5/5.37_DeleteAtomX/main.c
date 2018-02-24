#include <stdio.h>
#include "Glist.h"
#include "Stack.h"

//删去广义表中所有值为x的原子节点
void DeleteAtomX(GList **plist,GL_AtomType x) {
    //处理头结点：
    GList *list, *head=NULL, *tail=NULL;
    list = (*plist);
    if (list != NULL) {
        head = list->ptr.head;
        tail = list->ptr.tail;
    }


    if(list==NULL){
        return;
    }
    else if(head->tag==ATM && head->atom==x){
        free(head);
        head=NULL;
        *plist=tail;
        free(list);
        list=NULL;

        DeleteAtomX(plist,x);
    }
    else if(head->tag==ATM && head->atom!=x){
        DeleteAtomX(&(*plist)->ptr.tail,x);
    }
    else{
        DeleteAtomX(&(*plist)->ptr.head,x);
        DeleteAtomX(&(*plist)->ptr.tail,x);
    }

    return;
    //head=list->ptr.head;
    /*
        if( head->tag== ATM && head->atom == x)){
        list=list->ptr.tail;
    }
     */
}


int main() {
    printf("Hello, World!\n");

    char s[]="(abc(abc(d(aaaaa)ba)(dba))a)";
  //  char s[]="(a(a(a))a)";
    GList *list;
    list=StringToGList(s);
    DisplayGList(list);
    printf("\n");

    char x;
    scanf("%c",&x);
    DeleteAtomX(&list,x);
    DisplayGList(list);
    printf("\n");

    return 0;
}

/*
int main(){
    printf("hello\n");
};
 */
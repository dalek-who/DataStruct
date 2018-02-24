//#include <stdio.h>
#include "LinkList.h"

//将一个节点插入链表，并保证插入之后链表中元素还是升序排列的
Node* OrderInsertLinklist(LinkList *list,Node *pnode){
    //空链表直接插入
    if(IsEmptyList(list)){
        pnode = TailInsertNode_ptr(list,pnode); //插入完p会被置空
    }
        //比最小元素小：直接插在头部
        else if( pnode->data.key < list->head->data.key ){ //比
        HeadInsertNode(list,pnode->data);
        pnode = FreeNode(pnode);
    }   else{

        Node* q=NULL;
        q=list->head;
        int IsInsert=0; //标记是否成功插入
        while (!IsInsert){
            //插入：
            if(      q->data.key<= pnode->data.key
                 &&  (    (q->next != NULL && q->next->data.key > pnode->data.key) ||  (q->next == NULL)   )
               ){
                AddNode(q,pnode,list);
                pnode = NULL;
                IsInsert = 1;
            }//if

            //不插入，指针继续后移：
            else if(q->data.key<= pnode->data.key &&  q->next != NULL && q->next->data.key <= pnode->data.key){
                q = q->next;
            } //else

            //潜在的未考虑的情况
            else{
                printf("unconsider case\n");
                pnode = FreeNode(pnode);
            }//else
        }//while
    }//else
    return NULL;
}

//插入排序
void LinkListInsertSort(ElemType array[], int size){
    LinkList non_order_list,order_list; //有序、无序的链表
    InitLinkList(&non_order_list);
    InitLinkList(&order_list);
    ArrayToList(&non_order_list,array,size);

    //排序
    Node *pnode=NULL;
    while (!IsEmptyList(&non_order_list)){
        pnode = RemoveHead(&non_order_list);
        pnode = OrderInsertLinklist(&order_list,pnode);
    }

    for (int i = 0; i <size ; ++i) {
        pnode = RemoveHead(&order_list);
        array[i]=pnode->data;
        pnode = FreeNode(pnode);
    }

    return;
}

int main(){
  //  printf("Hello, World!\n");
    int size; scanf("%d",&size);
    ElemType data[size];
    for (int i = 0; i <size ; ++i) {
        scanf("%d %d",&data[i].key,&data[i].another);
    }

    LinkListInsertSort(data,size);

    int flag=0;
    for (int j = 0; j < size; ++j) {
        printf("%s %d %d",(flag==0)?"":"\n",data[j].key,data[j].another);
        flag=1;
    }
    return 0;
}
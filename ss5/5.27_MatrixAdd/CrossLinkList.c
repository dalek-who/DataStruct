//
// Created by Administrator on 2017/4/6.
//


//十字链表（带横向、纵向的头尾结点）
//可以用来表示稀疏矩阵，结点是非零元素

#include "CrossLinkList.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
//一维链表初始化（用来初始化十字链表的所有行、列一维链表）
int InitLinkList(LinkList * list){
    Node* p=NULL;
    //申请内存
    p=(Node*)malloc(sizeof(Node));if(!p) exit(ERROR);
    //结构初始化
    list->head=p;
    list->head->rignt=NULL;
    list->head->down=NULL;
    list->len=0;
    return OK;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//十字链表初始化
//输入十字矩阵行、列数(把这个函数单提出来，是为了能复用初始化函数，以方便用除了输入之外的其他方式来产生十字链表）
void Input_mn(CrLinkList *cross){
    //输入行数列数
    printf("input mu:");scanf("%d",&cross->mu);
    printf("input nu:");scanf("%d",&cross->nu);
}
int InitCrLinkList(CrLinkList* Cross){
    int i;
    //初始元素个数为0
    Cross->tu=0;
    //分配内存
    //横向头结点数组（mu+1是因为0号不存东西）
    if(!(Cross->Rhead = (LinkList*)malloc( (Cross->mu+1) *sizeof(LinkList) ) ) )
        exit(ERROR);
    //纵向
    if(!(Cross->Dhead = (LinkList*)malloc( (Cross->nu+1) *sizeof(LinkList) ) ) )
        exit(ERROR);

    //将头结点数组中的链表初始
    for(i=0 ; i<=Cross->mu ; ++i)
        InitLinkList(&Cross->Rhead[i]);
    for(i=0 ; i<=Cross->nu ; ++i)
        InitLinkList(&Cross->Dhead[i]);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
//判断一维链表是否为空
int IsEmptyList(LinkList linkList){
    if(linkList.len == 0 )
        return EMPTY;
    else
        return UNEMPTY;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//创建节点(包括结点的数据、坐标）
Node* CreatNode(CrLinkList_ElemType data, int i, int j){
    Node* newnode;
    newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->i = i;
    newnode->j = j;
    newnode->rignt= NULL;
    newnode->down = NULL;
    return newnode;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
//将结点按照坐标插入十字链表的正确位置
void InsertNode(Node* node,CrLinkList* cross){
    Node *q;
    //横向
    if( node->i > cross->mu || node->i == 0 )
        exit(ERROR);
    //跳过前面的节点
    for(q = cross->Rhead[node->i].head ; ( q->rignt!=NULL ) && ( q->rignt->j < node->j ) ; q=q->rignt)
        ;
    if( q->rignt!=NULL && q->rignt->j == node->j  )
        exit(ERROR);
    //插入
    node->rignt = q->rignt;
    q->rignt = node;
    ++cross->Rhead[node->i].len;


    //纵向
    if(  node->j > cross->nu || node->j == 0)
        exit(ERROR);
    //跳过前面的节点
    for(q = cross->Dhead[node->j].head ; ( q->down!=NULL ) && ( q->down->i < node->i ) ; q=q->down)
        ;
    if( q->down!=NULL && q->down->i == node->i )
        exit(ERROR);
    //插入
    node->down = q->down;
    q->down = node;
    ++cross->Dhead[node->j].len;

    //++非零元素个数
    ++cross->tu;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//在十字链表的坐标(i,j)处插入元素elem
void InsertElem(CrLinkList* cross,CrLinkList_ElemType elem, int i, int j){
    Node* newnode;
    //创建结点
    newnode = CreatNode(elem,i,j);
    //插入结点（默认结点格式正确，不越界，坐标不为0，坐标处没有已经存在的节点）。如果格式错误，会在插入时exit
    InsertNode(newnode,cross);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
//创建并赋值十字链表(包含初始化操作)
//用来存储稀疏矩阵。结点是非零元素
void CreatCrLinkList(CrLinkList* cross){
    Node* node;
    int i,j,data;
    //初始化
    InitCrLinkList(cross);
    //十字链表赋值
    for( printf("input data:"),scanf("%d",&data) ; data!=0 ; printf("input data:"),scanf("%d",&data) ){
        //赋值并申请结点
        printf("input i:");scanf("%d",&i);
        printf("input j:");scanf("%d",&j);
        node = CreatNode(data,i,j);
        //把结点插入十字链表
        //i、j超界，  i、j为0，  已经有i，j结点 三种错误情况，已在InsertNode函数中处理了
        InsertNode(node,cross);

        //打印十字链表。为了debug方便。实际使用时要注释掉
        DisplayCrossLinkList(*cross);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
//释放节点内存并把指针置空
void FreeNode(Node *node){
    free(node);
    node=NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//删除十字链表中的一个节点并释放其内存
void DeleteNode(CrLinkList* cross,Node* node){
    Node *left,*up;//node左边、上边的钱去结点

    //找到p的位置
    //横向
    for(left = cross->Rhead[node->i].head;left->rignt!=node;left=left->rignt)
        ;
    //纵向
    for(up = cross->Dhead[node->j].head;up->down!=node;up=up->down)
        ;

    //删除
    left->rignt = node->rignt;
    up->down = node->down;
    --cross->Rhead[node->i].len;
    --cross->Dhead[node->j].len;
    --cross->tu;
    FreeNode(node);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//以稀疏矩阵的形式打印十字链表
void DisplayCrossLinkList(CrLinkList cross){
    int i=1,j=1;
    Node *p;
    for(i=1 ; i<=cross.mu ;++i) {
        printf("%2d:", i);
        for (p = cross.Rhead[i].head->rignt,j=1 ; p != NULL ; ){
            if (p->j == j){
                printf("%2d,",p->data);
                ++j;
                p=p->rignt;
            }//if
            else {
                printf("  ,");
                ++j;
            }//else
        }//for p,j
        printf("\n");
    }//for i
    printf("   ");
    for(j=1 ; j<=cross.nu ; ++j)
        printf("%2d ",j);
    printf("\n");
}//DisplayCrossLinkList

////////////////////////////////////////////////////////////////////////////////////////////////////
//将二维数组转化为十字链表
void ArrayToCrLinkList(CrLinkList *Cross,int m, int n, CrLinkList_ElemType array[m+1][n+1]){
    int i,j;

    //初始化
    Cross->mu=m;
    Cross->nu=n;
    InitCrLinkList(Cross);

    //数组转换为链表
    for(i=1;i<=m ;++i){
        for(j=1;j<=n;++j){
            if(array[i][j]!=0)
                InsertElem(Cross,array[i][j],i,j);
        }//for j
    }//for i
}

////////////////////////////////////////////////////////////////////////////////////////////////////


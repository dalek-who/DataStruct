//
// Created by wang on 17-3-11.
//
////////////////////////////////
//   没有头结点的链表
//
//改进单向链表的头文件
//改进链表有一个链表，头指针，尾指针，链表中的元素长度。没有头结点，头指针head所指向的节点存有第一个数据元素
//元素是int型
///////////////////////////////



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ERROR 0
#define OK 1
#define EMPTY 1
#define UNEMPTY 0

//元素类型

typedef struct {
    int key[5];
}Data;

typedef Data ElemType;

//定义结构
//结点的结构
typedef struct node{
    ElemType data;           //存储的数据
    struct node* next;  //指向下一节点的指针
} Node;

//链表的结构
typedef struct linklist{
    Node *head,*tail;
    int len;//链表长度
}LinkList;

//相关的操作
int InitLinkList(LinkList* list);//链表初始化
void DisplayLinkList(LinkList *list);//打印链表
Node* CreatNode(ElemType data);//生成具有data==xxxx的节点
void AddNode(Node *to,Node *from,LinkList *list);//将节点nd加入到链表中，p节点的next位置
void HeadInsertNode(LinkList *list, ElemType data);//头部插入数据data的节点
void TailInsertNode(LinkList *list, ElemType data);//尾部插入数据data的节点
Node* FreeNode(Node* p);//释放节点内存
void DeleteNextNode(LinkList* list,Node* NowNode);//删除一个节点的next节点。如果删去了尾节点，则把新的最后一个节点变成尾节点
void DestroyList(LinkList* list);//销毁一个链表
int IsEmptyList(LinkList *list);//判断链表是否为空
void CreatMyList(LinkList* listA,ElemType s[], int size);//创建一个链表，链表的数据为s[]1

/*
//生成一些特殊的测试用链表
void RandomLinkList(LinkList * list);//随机data与len的链表，data非递减排列
void CreatTestLinkList(LinkList * list);//生成等差数列的链表
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





/*
 * //定义结构
//结点的结构
typedef struct node{
    ElemType data;           //存储的数据
    struct node* next;  //指向下一节点的指针
} Node;

//链表的结构
typedef struct linklist{
    Node *head,*tail;//头结点，尾节点，当前指针
    int len;//链表长度
}LinkList;
 */


///////////////////////////////////////////////////////////////////////////
//初始化
int InitLinkList(LinkList * list){
    /*
    Node* p=NULL;
    //申请内存
    p=(Node*)malloc(sizeof(Node));if(!p) exit(ERROR);
    //结构初始化
    list->head=list->tail=p;
    list->tail->next=NULL;
     */
    list->head = list->tail =NULL;
    list->len=0;
    return OK;
}
///////////////////////////////////////////////////////////////////////////
//打印链表
void DisplayLinkList(LinkList *list){

    Node* p;
    int count;
    //如果list本身是空表
    if(list->tail==list->head && list->head == NULL){
        printf("Head***Tail  {Empty LinkList}\n");
        return;
    }
    //如果不是空表
    printf("Head -> ");
    for(p=list->head,count=1;
            p->next!=NULL;
            p=p->next,++count){
        printf("%d..%c -> ",count,p->data);
    }//for
    printf("%d..%c***Tail\n",count,p->data);
}
//////////////////////////////////////////////////////////////////////////
//生成具有data==xxxx的节点
Node* CreatNode(ElemType data){
    Node* nd;
    nd=(Node*)malloc(sizeof(Node));
    if(!nd) exit(ERROR);
    nd->data=data;
    nd->next=NULL;
    return nd;
}
/////////////////////////////////////////////////////////////////////////
//将节点nd加入到链表中，p节点的next位置
void AddNode(Node *to,Node *from,LinkList *list){
    from->next=to->next;
    to->next=from;
    ++list->len;//链表容量++
}
/////////////////////////////////////////////////////////////////////////
//头部插入数据data的节点
void HeadInsertNode(LinkList *list, ElemType data){
    Node* q=NULL;
    q=CreatNode(data);

    //分三种情况
    //1.一开始是空链表：没有头结点的链表，在初始时head，tail都是null
    //加入后，链表只有一个结点
    if(list->head == NULL && list->tail == NULL) {
        list->head = list->tail = q;
        ++list->len;
    }
    else {
        q->next = list->head;
        list->head = q;
        ++list->len;
    }
        /*
     //2.如果加入新节点之前只有一个结点，那时head，tail是相同的，加入新节点后要把tail向后移动
    else if(list->tail==list->head && list->head!=NULL ) {
     //   AddNode(list->head, q, list);
        list->tail=list->head->next;
    }

    //3.如果链表不是空的，就直接在head后面插入即可
    else
        AddNode(list->head, q, list);
         */
}
/////////////////////////////////////////////////////////////////////////
//尾部插入数据data的节点
void TailInsertNode(LinkList *list, ElemType data){
/*
    //1.如果一开始是空链表
    //这种情况直接调用头部插入就可以了
    if(list->tail == NULL && list->head == NULL )
        HeadInsertNode(list,data);

    //2.一开始不是空链表
    else {
        Node *q = NULL;
        q = CreatNode(data);
        AddNode(list->tail, q, list);
        list->tail = list->tail->next;//尾部插入后，要把尾指针向后移动一下
    }
    */
    Node* q=NULL;
    q=CreatNode(data);

    //分三种情况
    //1.一开始是空链表：没有头结点的链表，在初始时head，tail都是null
    //加入后，链表只有一个结点
    if(list->head == NULL && list->tail == NULL) {
        list->head = list->tail = q;
        ++list->len;
    }
    else {
        list->tail->next = q;
        list->tail = q;
        ++list->len;
    }
}
/////////////////////////////////////////////////////////////////////////
//释放节点内存
Node* FreeNode(Node* p){
    if(p!=NULL) {
        free(p);
        p = NULL;
    }
	return p;
}
/////////////////////////////////////////////////////////////////////////
//删除一个节点的下一个节点
void DeleteNextNode(LinkList* list,Node* NowNode){

    if(NowNode == NULL)
        return;

    else {
        Node *p = NowNode->next;
        if (p != NULL) {
            NowNode->next = p->next;
            --list->len;
            //     p = FreeNode(p);
        }
        //如果删去下一节点后导致NowNode变成尾节点
        /*
        if(NowNode->next==NULL)
            list->tail=NowNode;
            */
        if (p == list->tail)
            list->tail = NowNode;

        //安全释放删去的节点内存。释放完后会把p置NULL
        //FreeNode()可以处理p==NULL的情况
        p = FreeNode(p);
    }
}
//////////////////////////////////////////////////////////////////////////
int IsEmptyList(LinkList* list){
    if(list->len==0)
        return EMPTY;
    else
        return UNEMPTY;
}
//////////////////////////////////////////////////////////////////////////
//销毁一个链表
void DestroyList(LinkList* list){
    list->len=0;
    while (list->head->next!=NULL)
        //不断删去头结点的下一个节点
        DeleteNextNode(list,list->head);

    //释放头结点
    FreeNode(list->head);
    list->head=list->tail=NULL;
}
/////////////////////////////////////////////////////////////////////////
//创建一个测试用链表，数据为一个数组的数据
void CreatMyList(LinkList* listA,ElemType s[], int size){
    int i;
    InitLinkList(listA);
    for(i=0;i<size;++i)
        TailInsertNode(listA,s[i]);
}
/////////////////////////////////////////////////////////////////////////
/*
//生成用来做测试的各种链表
//随机data与len的链表，data非递减排列
void RandomLinkList(LinkList* list){
    ElemType data;
    int len;
    Node *p,*add=NULL;
    srand((unsigned)time(NULL));
    len=rand()%20;
    //初始化
    InitLinkList(list);

    //插入数据
    TailInsertNode(list,rand()%100);
    for(list->len=1;list->len<len;++list->len){
        while((data=rand()%100)< list->tail->data)
            ;
        TailInsertNode(list,data);
    }//for

}
/////////////////////////////////////////////////////////////////////////////
//生成等差数列的链表
void CreatTestLinkList(LinkList* list){
    int len=5,
        tolerance=5,//公差
        data=5;
    Node *p,*add=NULL;
    //初始化
    InitLinkList(list);

    //插入数据
    for(list->len=0;list->len<len;data+=tolerance){
        TailInsertNode(list,data);//插入时自带了++list->len
    }//for
}
*/
/////////////////////////////////////////////////////////////////////////////////














































/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#define MAXNUMBER 100

//数组相关操作
//数组初始化，随机填关键字
void CreateArray(Data data[], int DataNumber, int KeyNumber){
    srand((unsigned)time(NULL));
    for (int i = 0; i <DataNumber ; ++i) {
        for (int j = 0; j <KeyNumber ; ++j) {
            data[i].key[j] = rand()%(MAXNUMBER+1);
        }//for j
    }//for i
}
/////////////////////////////////////////////////////////////////////////////////////

//数组拷贝
void CopyArray(Data to[],Data from[], int DataNumber, int KeyNumber){
    for (int i = 0; i <DataNumber ; ++i) {
        for (int j = 0; j <KeyNumber ; ++j) {
            to[i].key[j] = from[i].key[j];
        }//for j
    }//for i
}
/////////////////////////////////////////////////////////////////////////////////////

//数组打印
void DisplayArray(Data data[],int DataNumber, int KeyNumber){
    printf("\n");
    for (int i = 0; i <DataNumber ; ++i) {
        for (int j = KeyNumber-1; j >=0 ; --j) {
            printf("%3d ",data[i].key[j]);
        }//for j
        printf("\n");
    }//for i
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
//用于判断结果是否正确
//1.比较两个data的大小。注：key[0]的权值最小
int Compare(Data data1,Data data2, int KeyNumber){
    int result = 0;
    for(int i=KeyNumber-1;i>=0;--i){
        if(data1.key[i] > data2.key[i]){
            result = 1;
            break;
        } //if

        else if (data1.key[i] < data2.key[i] ){
            result = -1;
            break;
        }//else

        else
            continue;
    }//for

    return result;
}
/////////////////////////////////////////////////////////////////////////////////////
//判断排序结果是否正确
int SortSuccess(Data data[], int DataNumber, int KeyNumber){
    for(int i=1; i<DataNumber ; ++i){
        if(  Compare(data[i],data[i-1],KeyNumber) >=0 )
            continue;
        else{
            printf("%d ",i);
            printf("sort fail,[*******  *******  *******  error  *******  *******  ******* ]\n");
            return 0;
        }//排序失败，return
    }//for
    printf(" successful !!!\n");
    return 1;
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////


//多关键字排序：
/////////////////////////////////////////////////////////////////////////////////////

////////////////////////
//1：LDS,通过稳定的内部排序方法，从低权重到高权重的关键字依次进行排序
//稳定的内部排序方法采用 归并排序
////////////////////////

//1.1 单关键词归并排序
//1.1.1 两个已经排好序的部分的归并
//注：传进来的是整个数组，待归并的部分是从data[low]到data[high]
//其中有两个已经归并好的部分：data[low]到data[mid]，data[mid+1]到data[high]
void Merge(Data data1[], int key, int low, int high){
    if(low == high) // 只有一个元素
        return;
    else{
        int mid = (low + high) /2, //中间
            length = high-low+1,    //长度
            i,j,k;
        Data temp[length];
        //归并
        for(i=low,j=mid+1,k=0; i<=mid && j <=high ; ){
            if(data1[i].key[key] <= data1[j].key[key]){
                temp[k] = data1[i];
                ++i,++k;
            }//data[i] <= data[j]

            else{
                temp[k] = data1[j];
                ++j,++k;
            }//data[i] > data[j]
        }
        //填充剩下的元素
        while (i <= mid)
            temp[k++] = data1[i++];
        while (j <= high)
            temp[k++] = data1[j++];

        //temp拷贝进data[]
        for(k=0,i=low;k<length;++k,++i)
            data1[i] = temp[k];

        return;
    }
}

/////////////////////////////////////////////////////////////////////////////////////
//1.1.2 归并排序
void MergeSort(Data data[], int key, int low, int high){
    int mid=(low + high) /2;
    if(low != high) {
        MergeSort(data, key, low, mid);
        MergeSort(data, key, mid + 1, high);
    }
    Merge(data,key,low,high);
    return;
}
/////////////////////////////////////////////////////////////////////////////////////
//1.2 多关键词归并排序
//key的权重按0,1,2,3.。。。递增
//先排低权重的，后排高权重的
void MultiKeyMergeSort(Data data[], int DataNumber, int KeyNumber){
    int i;
    for(i=0; i<KeyNumber ; ++i){
        MergeSort(data,i,0,DataNumber-1);
    }
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

////////////////////////
//2.LSD,通过类似于基数排序的方法，按权由低到高，通过链表进行排序
//注：key[0]的权最低
////////////////////////

//2.1 链表相关的操作
//2.1.1 将一个链表数组串成一个大链表，串完之后将链表数组的每个链表置空
LinkList GatherLinkList(LinkList ListArray[], int size){
    LinkList BigList;
    InitLinkList(&BigList);
    int i;

    //跳过空链表
    for(i=0; IsEmptyList(&ListArray[i]) && i< size ;++i )
        ;

    //连接第一个链表
    if( !IsEmptyList(&ListArray[i]) && i< size ){
        //串连
        BigList.head = ListArray[i].head;
        BigList.tail = ListArray[i].tail;
        BigList.len += ListArray[i].len;

        //子链表ListArray[i]清空
        ListArray[i].head = ListArray[i].tail = NULL;
        ListArray[i].len = 0;

        ++i;
    }

    //串连剩下的子链表
    for( ; i<size ;++i){
        if( !IsEmptyList(&ListArray[i]) ){
            //串连
            BigList.tail->next = ListArray[i].head;
            BigList.tail = ListArray[i].tail;
            BigList.len += ListArray[i].len;

            //子链表ListArray[i]清空
            ListArray[i].head = ListArray[i].tail = NULL;
            ListArray[i].len = 0;
        }
    }

    return BigList;
}

/////////////////////////////////////////////////////////////////////////////////////
//2.1.2 将一个链表的第一个节点摘除下来，并返回指向这个结点的指针
Node* RemoveHead(LinkList *list){
    Node *pnode = NULL;
    //空链表
    if( IsEmptyList(list) )
        return pnode;
    //只有一个结点的链表
    else if(list->len == 1){
        pnode = list->head;
        list->head = list->tail = NULL;
        --list->len;
        //摘除出来的是一个单个节点，要把next置空
        pnode->next=NULL;
    }
    //多个节点的链表
    else{
        pnode = list->head;
        list->head = list->head->next;
        --list->len;
        //摘除出来的是一个单个节点，要把next置空
        pnode->next = NULL;
    }

    return pnode;
}
/////////////////////////////////////////////////////////////////////////////////////
//2.1.3 将一个指针指向的节点从尾部插入链表
Node* TailInsertNode_ptr(LinkList *list,Node *pnode){
    //空链表：
    if( IsEmptyList(list) ){
        list->head = list->tail = pnode;
        ++list->len;
    }
    //非空链表：
    else{
        list->tail->next = pnode;
        list->tail = pnode;
        ++list->len;
    }

    //为了安全，返回一颗空指针
    pnode = NULL;
    return pnode;
}
/////////////////////////////////////////////////////////////////////////////////////
//2.1.4 把数组转化为链表
void ArrayToList(LinkList* listA,ElemType s[], int size){
    int i;
    InitLinkList(listA);
    for(i=0;i<size;++i)
        TailInsertNode(listA,s[i]);
}

/////////////////////////////////////////////////////////////////////////////////////
//2.2 基数排序(桶排序)
void MultiKeyBucketSort(Data data[], int DataNumber, int KeyNumber){
    LinkList MainList; //由data转化成的总链表
    LinkList ListArray[MAXNUMBER+1]; //代表0,1 ...100的“桶”

    //初始化
    ArrayToList(&MainList,data,DataNumber);
    for (int i = 0; i <MAXNUMBER+1 ; ++i) {
        InitLinkList(&ListArray[i]);
    }

    Node* pnode=NULL;
    //桶排序
    int k;
    for (k = 0; k <KeyNumber ; ++k) {

        while (!IsEmptyList(&MainList)){
            //从主链上摘除头结点
            pnode = RemoveHead(&MainList);
            //头结点入桶
            pnode = TailInsertNode_ptr(&ListArray[ pnode->data.key[k] ] , pnode);
        }

        //把每个桶里的子链重新按顺序串成一个主链
        MainList = GatherLinkList(ListArray,MAXNUMBER+1);
    }//for

    //主链重新转化为数组
    int j;
    for(pnode = MainList.head, j=0; pnode!= NULL ; pnode=pnode->next,++j){
        data[j] = pnode->data;
    }

    DestroyList(&MainList);
    return;
}
/////////////////////////////////////////////////////////////////////////////////////
//3.MSD 按权重由大到小排序，先把权重大的分桶，再在每个桶里给下一个关键字再分桶(链表版本）
LinkList MSD_MultiKeyBucketSort_LinkList(LinkList list,int KeyNumber, int key) {
    if(key<0)
        return list;
    else {
        LinkList ListArray[MAXNUMBER + 1]; //代表0,1 ...100的“桶”
        //初始化桶
        int i;
        for (i = 0; i < MAXNUMBER + 1; ++i) {
            InitLinkList(&ListArray[i]);
        }

        Node *pnode = NULL;
        //从主串上依次摘除头结点并分桶
        while (!IsEmptyList(&list)) {
            //从主链上摘除头结点
            pnode = RemoveHead(&list);
            //头结点入桶
            pnode = TailInsertNode_ptr(&ListArray[pnode->data.key[key]], pnode);
        }//while

        //递归给每个字串再分桶
        for(i = 0; i < MAXNUMBER + 1; ++i){
            if(ListArray[i].len>=2) {
                ListArray[i] = MSD_MultiKeyBucketSort_LinkList(ListArray[i], KeyNumber, key - 1);
            }
        }

        //整合所有子串
        list = GatherLinkList(ListArray,MAXNUMBER+1);
    }
    return list;
}
/////////////////////////////////////////////////////////////////////////////////////
void MSD_MultiKeyBucketSort(Data data[], int DataNumber, int KeyNumber){
    LinkList MainList;
    ArrayToList(&MainList,data,DataNumber);

    //排序
    MainList = MSD_MultiKeyBucketSort_LinkList(MainList,KeyNumber,KeyNumber-1);

    //主链重新转化为数组
    int j;
    Node *pnode;
    for(pnode = MainList.head, j=0; pnode!= NULL ; pnode=pnode->next,++j){
        data[j] = pnode->data;
    }

    DestroyList(&MainList);
    return;
}
/////////////////////////////////////////////////////////////////////////////////////

//多关键字排序
//记录不超过10 000，至多5个关键字，各个关键字范围均为[0~100]
int main() {
    //printf("Hello, World!\n");
    int DataNumber; printf("please input DataNumber: "); scanf("%d",&DataNumber);
    int KeyNumber;  printf("please input KeyNumber:  "); scanf("%d",&KeyNumber);



    //产生数组
    Data data1[DataNumber],data2[DataNumber],data3[DataNumber];
    CreateArray(data1,DataNumber,KeyNumber);
    CopyArray(data2,data1,DataNumber,KeyNumber);
    CopyArray(data3,data1,DataNumber,KeyNumber);

    //1.LDS,通过稳定的内部排序方法（这里选用归并排序），从低权重到高权重的关键字依次进行排序
    DisplayArray(data1,DataNumber,KeyNumber);  //打印原始数组
    SortSuccess(data1,DataNumber,KeyNumber);   //判断是否排序成功
    int result1;
    clock_t start1,finish1;                     //计时
    double time1;
    start1 = clock();      //开始时间
    MultiKeyMergeSort(data1,DataNumber,KeyNumber);  //排序
    finish1 = clock();  //结束时间
    time1 = difftime(finish1,start1) / CLOCKS_PER_SEC; //排序总共耗时
    DisplayArray(data1,DataNumber,KeyNumber); //打印排序好的数组
    result1 = SortSuccess(data1,DataNumber,KeyNumber); //判断是否排序成功
    printf("%f seconds\n\n\n",time1); //打印排序所用时间


    //2.LSD,通过类似于基数排序的方法，按权由低到高，通过链表进行排序
 //   DisplayArray(data2,DataNumber,KeyNumber);  //打印原始数组
  //  SortSuccess(data2,DataNumber,KeyNumber);   //判断是否排序成功
    int result2;
    clock_t start2,finish2;                     //计时
    double time2;
    start2 = clock();      //开始时间
    //MultiKeyMergeSort(data2,DataNumber,KeyNumber);  //排序
    MultiKeyBucketSort(data2,DataNumber,KeyNumber);  //排序
    finish2 = clock();  //结束时间
    time2 = difftime(finish2,start2) / CLOCKS_PER_SEC; //排序总共耗时
    DisplayArray(data2,DataNumber,KeyNumber); //打印排序好的数组
    result2 = SortSuccess(data2,DataNumber,KeyNumber); //判断是否排序成功
    printf("%f seconds\n\n\n",time2); //打印排序所用时间

  //     DisplayArray(data3,DataNumber,KeyNumber);  //打印原始数组
    //  SortSuccess(data3,DataNumber,KeyNumber);   //判断是否排序成功
    int result3;
    clock_t start3,finish3;                     //计时
    double time3;
    start3 = clock();      //开始时间
    //MultiKeyMergeSort(data3,DataNumber,KeyNumber);  //排序
    MSD_MultiKeyBucketSort(data3,DataNumber,KeyNumber);  //排序
    finish3 = clock();  //结束时间
    time3 = difftime(finish3,start3) / CLOCKS_PER_SEC; //排序总共耗时
    DisplayArray(data3,DataNumber,KeyNumber); //打印排序好的数组
    result3 = SortSuccess(data3,DataNumber,KeyNumber); //判断是否排序成功
    printf("%f seconds\n\n\n",time3); //打印排序所用时间

    printf("LSD Multi Key Merge  Sort:%s  %f seconds\n",(result1 == 1)?"success":"fail   ",time1);
    printf("LSD Multi Key Bucket Sort:%s  %f seconds\n",(result2 == 1)?"success":"fail   ",time2);
    printf("MSD Multi Key Bucket Sort:%s  %f seconds\n",(result3 == 1)?"success":"fail   ",time3);
    return 0;
}

















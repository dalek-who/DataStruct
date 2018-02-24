//#include <stdio.h>
#include "LinkList.h"
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

void F_DisplayArray(Data data[],int DataNumber, int KeyNumber,FILE* pf_out){
    if(pf_out==NULL)
        exit(ERROR);
    else {
        fprintf(pf_out,"\n");
        for (int i = 0; i < DataNumber; ++i) {
            for (int j = KeyNumber - 1; j >= 0; --j) {
                fprintf(pf_out,"%3d ", data[i].key[j]);
            }//for j
            fprintf(pf_out,"\n");
        }//for i
    }
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
            if(ListArray[i].len>=2){
                        if(ListArray[i].len>=2) {
                ListArray[i] = MSD_MultiKeyBucketSort_LinkList(ListArray[i], KeyNumber, key - 1);
                       }
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

//4（一个不好的MSD，时间特别长）
LinkList MSD_MultiKeyBucketSort_LinkList_Bad(LinkList list,int KeyNumber, int key) {
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
            //        if(ListArray[i].len>=2) {
            ListArray[i] = MSD_MultiKeyBucketSort_LinkList(ListArray[i], KeyNumber, key - 1);
            //       }
        }

        //整合所有子串
        list = GatherLinkList(ListArray,MAXNUMBER+1);
    }
    return list;
}
/////////////////////////////////////////////////////////////////////////////////////
void MSD_MultiKeyBucketSort_Bad(Data data[], int DataNumber, int KeyNumber){
    LinkList MainList;
    ArrayToList(&MainList,data,DataNumber);

    //排序
    MainList = MSD_MultiKeyBucketSort_LinkList_Bad(MainList,KeyNumber,KeyNumber-1);

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
    Data data1[DataNumber],data2[DataNumber],data3[DataNumber],data4[DataNumber];
    CreateArray(data1,DataNumber,KeyNumber);
    CopyArray(data2,data1,DataNumber,KeyNumber);
    CopyArray(data3,data1,DataNumber,KeyNumber);
    CopyArray(data4,data1,DataNumber,KeyNumber);

    //输出数据的文件
    //由于加入了clock函数，每次打开时由于时间不同，都会自动生成一个新的名字不同的文件，以防覆盖之前的文件
    FILE *pf_out;
    char* FileNameFront = "E:/DataStruct/FinalHomework/6.7_MultiKeySort/data/data";
    char* txt=".txt";
    char time_array[20];
    char FileName[80];
    time_t time=clock();
    itoa(time, time_array, 10);
    strcpy(FileName,FileNameFront);
    strcat(FileName,time_array);
    strcat(FileName,txt);
    pf_out = fopen(FileName,"w");

    fprintf(pf_out,"/////////////////////////////////////////////////////////////////////////\n");
    fprintf(pf_out,"DataNumber: %d\n",DataNumber);
    fprintf(pf_out,"KeyNumber: %d\n\n",KeyNumber);
    fprintf(pf_out,"/////////////////////////////////////////////////////////////////////////\n");

    //1.LDS,通过稳定的内部排序方法（这里选用归并排序），从低权重到高权重的关键字依次进行排序
    DisplayArray(data1,DataNumber,KeyNumber);  //打印原始数组
    F_DisplayArray(data1,DataNumber,KeyNumber,pf_out);  //打印原始数组
    SortSuccess(data1,DataNumber,KeyNumber);   //判断是否排序成功
    int result1;
    clock_t start1,finish1;                     //计时
    double time1;
    start1 = clock();      //开始时间
    MultiKeyMergeSort(data1,DataNumber,KeyNumber);  //排序
    finish1 = clock();  //结束时间
    time1 = difftime(finish1,start1) / CLOCKS_PER_SEC; //排序总共耗时
    DisplayArray(data1,DataNumber,KeyNumber); //打印排序好的数组
    F_DisplayArray(data1,DataNumber,KeyNumber,pf_out);
    result1 = SortSuccess(data1,DataNumber,KeyNumber); //判断是否排序成功
    printf("%f seconds\n\n\n",time1); //打印排序所用时间
    fprintf(pf_out,"%f seconds\n\n\n",time1);


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
    F_DisplayArray(data2,DataNumber,KeyNumber,pf_out);
    result2 = SortSuccess(data2,DataNumber,KeyNumber); //判断是否排序成功
    printf("%f seconds\n\n\n",time2); //打印排序所用时间
    fprintf(pf_out,"%f seconds\n\n\n",time2);

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
    F_DisplayArray(data3,DataNumber,KeyNumber,pf_out);
    result3 = SortSuccess(data3,DataNumber,KeyNumber); //判断是否排序成功
    printf("%f seconds\n\n\n",time3); //打印排序所用时间
    fprintf(pf_out,"%f seconds\n\n\n",time3);

    int result4;
    clock_t start4,finish4;                     //计时
    double time4;
    start4 = clock();      //开始时间
    //MultiKeyMergeSort(data4,DataNumber,KeyNumber);  //排序
    MSD_MultiKeyBucketSort_Bad(data4,DataNumber,KeyNumber);  //排序
    finish4 = clock();  //结束时间
    time4 = difftime(finish4,start4) / CLOCKS_PER_SEC; //排序总共耗时
    DisplayArray(data4,DataNumber,KeyNumber); //打印排序好的数组
    F_DisplayArray(data4,DataNumber,KeyNumber,pf_out);
    result4 = SortSuccess(data4,DataNumber,KeyNumber); //判断是否排序成功
    printf("%f seconds\n\n\n",time4); //打印排序所用时间
    fprintf(pf_out,"%f seconds\n\n\n",time4);

    printf("LSD Multi Key Merge  Sort:              %s  %f seconds\n",(result1 == 1)?"success":"fail   ",time1);
    printf("LSD Multi Key Bucket Sort:              %s  %f seconds\n",(result2 == 1)?"success":"fail   ",time2);
    printf("MSD Multi Key Bucket Sort(improved):    %s  %f seconds\n",(result3 == 1)?"success":"fail   ",time3);
    printf("MSD Multi Key Bucket Sort(not improved):%s  %f seconds\n",(result4 == 1)?"success":"fail   ",time4);

    fprintf(pf_out,"/////////////////////////////////////////////////////////////////////////\n");
    fprintf(pf_out,"LSD Multi Key Merge  Sort:              %s  %f seconds\n",(result1 == 1)?"success":"fail   ",time1);
    fprintf(pf_out,"LSD Multi Key Bucket Sort:              %s  %f seconds\n",(result2 == 1)?"success":"fail   ",time2);
    fprintf(pf_out,"MSD Multi Key Bucket Sort(improved):    %s  %f seconds\n",(result3 == 1)?"success":"fail   ",time3);
    fprintf(pf_out,"MSD Multi Key Bucket Sort(not improved):%s  %f seconds\n",(result4 == 1)?"success":"fail   ",time4);
    fprintf(pf_out,"/////////////////////////////////////////////////////////////////////////\n");

    fclose(pf_out);


    return 0;
}
#include <stdio.h>

#include "LinkList.h"

#define MAXSTRING 11 //单词的最大长度
//#define MAXDEEP h-1 //分支的最大深度，从0开始数，0,1,2层是分支.如果单词长度>=2则叶子在第3层

//Trie树数据结构
typedef enum{LEAF,BRANCH} TreeNodeType; // trie树的结点类型(叶子，分支)
//typedef char TreeElemType; //trie树节点所存的数据元素类型
typedef struct TrieTreeNode{
    TreeNodeType NodeType; //tire树的结点类型（叶子，分支）
    union {
        LinkList Leaf; //叶子（用链表存储同义词）
        struct {
            struct TrieTreeNode* ptr[27]; //指向下一节点的指针数组.此tri树存储的是单词，27=26个英文字母+结束符$
            int num;//分支数量
        }Branch; //分支
    };
}TrieTreeNode,*TrieTree;

//初始化Tire树
TrieTree InitTireTree(TreeNodeType nodeType){
    TrieTree tree=NULL;
    tree = (TrieTree)malloc(sizeof(TrieTreeNode));
    if(!tree) exit(ERROR);

    //叶子节点和分支结点的初始化不同
    switch (nodeType){
        case LEAF: {
            tree->NodeType = LEAF;
            InitLinkList(&tree->Leaf);
            break;
        }

        case BRANCH: {
            tree->NodeType = BRANCH;
            tree->Branch.num = 0;
            for (int i = 0; i < 27; ++i)
                tree->Branch.ptr[i] = NULL;
            break;
        }

        default: exit(ERROR);
    }

    return tree;
}

//在链表中查找元素（这里的元素是单词）
//如果找到，返回一颗指向链表中相应结点的指针，否则返回Null
Node* FindString(LinkList list, char string[]){
  //  int find=0;
    Node *p;
    for(p=list.head;p!=NULL;p=p->next){
        //如果找到了就退出循环
        if( strcmp(p->data,string) == 0 ){
    //        find = 1;
            break;
        } //if
        else
            continue;
    }//for
//    return find;
    return p;
}

//tire树插入元素（递归）
TrieTree TrieTree_InsertElem(TrieTree tree,char string[], int index,int strlen, int max_deep){

    //叶子条件：
    if(index > strlen || index == max_deep ){

        //如果叶子一开始是空指针，则先申请叶子节点
        if(tree == NULL)
            tree = InitTireTree(LEAF);
        else
            ;

        //如果叶子中未找到单词，则从链表头部插入
        if(!FindString(tree->Leaf,string)) {
            char *new_string;
            new_string = (char*)malloc(11* sizeof(char));
            strcpy(new_string,string);
            //链表的data是指针，指针存储的是内存空间地址。
            //如果直接把string的地址存入链表，如果string在函数外部发生内容变化，则链表中存储的单词也会改变
            //为了防止单词被改变，把string的单词拷贝给一个新申请的数组new_string并把new_string的地址插入链表里
            HeadInsertNode(&tree->Leaf, new_string);
        }
        //如果查到了就不再重复插入了
        else
            ;
    } //if 满足叶子条件

    //分枝条件
    else{

        //如果进入了空指针则再申请一个节点
        if(tree == NULL)
            tree = InitTireTree(BRANCH);
        else
            ;

        //找到下一个指针的位置，递归进入下一层
        //找到下一个指针的位置
        int next_ptr_number;
        next_ptr_number = (string[index]=='\0')? 0 : string[index]-'A'+1;
        // 每进入下一层，如果下一层一开始是NULL,则一定会增加这层的分支数量
        if(tree->Branch.ptr[next_ptr_number] == NULL)
            ++tree->Branch.num;
        //递归进入下一层
        tree->Branch.ptr[next_ptr_number] = TrieTree_InsertElem(tree->Branch.ptr[next_ptr_number],
                                                                string, index+1, strlen, max_deep);
    }//if 满足分枝条件

    return tree;
}

void DeleteNode(LinkList *list,Node *pnode) {
    //只有链表一个结点：
    if (list->len == 1 && pnode == list->head) {
        free(pnode->data); // Trie树叶子链表的元素是char指针，指针指向的内存存有单词。
        // 所以在删除链表结点之前，要先把单词的内存free
        free(pnode);
        list->head = list->tail = pnode = NULL;
        --list->len;
    }

        //有多个结点且删除的不是头结点：
    else if (list->len > 1 && pnode!=list->head) {
        Node *pnode_before;
        for (pnode_before = list->head; pnode_before != NULL; pnode_before = pnode_before->next) {
            if (pnode_before->next == pnode) {
                free(pnode->data);
                DeleteNextNode(list, pnode_before);
                break;
            }//if
        }//for
    }//else 多个节点

    else if(list->len>1 && pnode==list->head){
        list->head = list->head->next;
        --list->len;
        free(pnode->data);
        free(pnode);
    }
    else
        ;
}

//删除树中的单词
TrieTree TrieTree_DeleteElem(TrieTree tree,char string[], int index){
    static int deep=-1;
    ++deep;
    //叶子节点：
    if(tree->NodeType == LEAF){
        Node *find = FindString(tree->Leaf,string);
        //如果找到了就删除结点
        if( find )
            DeleteNode(&tree->Leaf,find);

        //如果删除后变成了空链表，就删除叶子节点
        if( IsEmptyList(&tree->Leaf) ){
            free(tree);
            tree = NULL;
        }//if 删除后变成了空链表
    }//if 叶子节点

    //分支结点
    else{
        //向下查找
        int next_ptr_number;
        next_ptr_number = (string[index]=='\0')? 0 : string[index]-'A'+1;
        //如果查到下一分支，就继续进入下一分支
        if( tree->Branch.ptr[next_ptr_number] != NULL ){
            tree->Branch.ptr[next_ptr_number] = TrieTree_DeleteElem(tree->Branch.ptr[next_ptr_number],string,index+1);
            //原本不是NULL的结点变为NULL，说明分支减少了
            if(tree->Branch.ptr[next_ptr_number] == NULL )
                --tree->Branch.num;
        }//if 下一分支不是NULL

        //如果分支数减为0，就把这个分支结点删掉
        if(tree->Branch.num == 0 && deep!=0 ){
            free(tree);
            tree = NULL;
        }//if
    }//else 分支结点

    --deep;
    return tree;
}

//打印trie树
//中、右、左先序遍历，后插入的词先打印
void DisplayTrieTree(TrieTree tree){

    static int flag=0;
    static int deep=0;
    int reset_flag = (deep==0) ? 1 : 0; // 用来重置flag的信号
    
    if(tree == NULL)
        return;
    else { //指针非空
        printf("%s", (flag == 0) ? "" : "\n");
        flag = 1;

        //打印分支
        if (tree->NodeType == BRANCH) {
            printf("branch %d", tree->Branch.num);
            for (int i = 0; i <27; ++i) {
                ++deep;
                DisplayTrieTree(tree->Branch.ptr[i]);
                --deep;
            }
        }//if branch

        //打印叶子
        else{
            printf("leaf %d ",tree->Leaf.len);
            Node *p;
            char ch[11];
            for(p=tree->Leaf.head;p!=NULL;p=p->next) {
                strcpy(ch,p->data);
                printf("%s ", ch);
            }
        }//else

        //递归打印一棵树完成，将打印回车的信号复位
      //  flag = (reset_flag == 1)?  0:flag;
        deep = (reset_flag == 1)?  0:deep;

        return;
    }
}

void F_DisplayTrieTree(TrieTree tree,FILE* pf_out){

    static int flag=0;
    static int deep=0;
    int reset_flag = (deep==0) ? 1 : 0; // 用来重置flag的信号
    
    if(pf_out==NULL)
        exit(ERROR);
    
    if(tree == NULL)
        return;
    else { //指针非空
        fprintf(pf_out,"%s", (flag == 0) ? "" : "\n");
        flag = 1;

        //打印分支
        if (tree->NodeType == BRANCH) {
            fprintf(pf_out,"branch %d", tree->Branch.num);
            for (int i = 0; i <27; ++i) {
                ++deep;
                F_DisplayTrieTree(tree->Branch.ptr[i],pf_out);
                --deep;
            }
        }//if branch

            //打印叶子
        else{
            fprintf(pf_out,"leaf %d ",tree->Leaf.len);
            Node *p;
            char ch[11];
            for(p=tree->Leaf.head;p!=NULL;p=p->next) {
                strcpy(ch,p->data);
                fprintf(pf_out,"%s ", ch);
            }
        }//else

        //递归打印一棵树完成，将打印回车的信号复位
        //  flag = (reset_flag == 1)?  0:flag;
        deep = (reset_flag == 1)?  0:deep;

        return;
    }
}

//#include <string.h>
//typedef char Test[4];
int main(){
    /*
    printf("Hello, World!\n");
    Test t ;
    char a[]= "wawawa";
    strcpy(t,a);
    puts(t);

    t[0] = 'a';
    t[1] = 'b';
    t[2] = 'x';
    t[3] = '\0';

    puts(t);
     */
    /*
    LinkList list;
    InitLinkList(&list);
    char c1[]="abcde",c2[]="bde",c3[]="cdef",c4[]="fghi";
    HeadInsertNode(&list,c1);
    HeadInsertNode(&list,c2);
    TailInsertNode(&list,c3);
    TailInsertNode(&list,c4);
    Node* p;
    for(p=list.head;p!=NULL;p=p->next)
        puts(p->data);
    printf("%d",list.len);
    puts(list.head->data);
    puts(list.tail->data);
     */
    /*
    char t1[5]="aba",t2[10]="abc";
    puts(t1);puts(t2);
    printf("%d",strcmp(t1,t2));
     */

    FILE *pf_in,*pf_out;
    char    FileName_in[]= "E:/DataStruct/ss9/9.42&9.43_TrieTree/data/0.in", 
            FileName_out[]="E:/DataStruct/ss9/9.42&9.43_TrieTree/data/0_my.out"; //42
    int file_number;
    for (int j = 0; j <6 ; ++j) {
        //自动改变用例文件
        FileName_in[42] = (char) ('0' + j);
        FileName_out[42] = (char) ('0' + j);

        pf_in = fopen(FileName_in, "r");
        pf_out = fopen(FileName_out, "w");
        if (!pf_in) exit(ERROR);
        int max_deep;
        fscanf(pf_in, "%d", &max_deep);

        int OperateNumber;
        fscanf(pf_in, "%d", &OperateNumber);
        int operate;
        char string[11];
        TrieTree tree = NULL;
        /*
        for (int i = 0; i <OperateNumber ; ++i) {
            scanf("%d",&operate);
            switch (operate) {
                case 1: { // 插入元素
                    scanf("%s", string);
                    tree = TrieTree_InsertElem(tree, string, 0, strlen(string),max_deep-1);
                    break;
                }

                case 2: {
                    scanf("%s", string);
                    tree = TrieTree_DeleteElem(tree,string,0);
                    break;
                }

                case 3:{
                    DisplayTrieTree(tree);
                    break;
                }

                default:
                    break;
            }//switch
         //   DisplayTrieTree(tree);
        }
        */


        for (int i = 0; i < OperateNumber; ++i) {
            fscanf(pf_in, "%d", &operate);
            switch (operate) {
                case 1: { // 插入元素
                    fscanf(pf_in, "%s", string);
                    tree = TrieTree_InsertElem(tree, string, 0, strlen(string), max_deep - 1);
                    break;
                }

                case 2: {
                    fscanf(pf_in, "%s", string);
                    tree = TrieTree_DeleteElem(tree, string, 0);
                    break;
                }

                case 3: {
                    DisplayTrieTree(tree);
                    F_DisplayTrieTree(tree,pf_out);
                    break;
                }

                default:
                    break;
            }//switch
        }

        fclose(pf_in),pf_in=NULL;
        fclose(pf_out),pf_out=NULL;
    }
    return 0;
}
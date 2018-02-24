//将图象中一个区域的一个颜色全部换成另一种颜色
/*原理：
 *类似于把一滴墨水滴在水里，墨水会一圈圈扩散开，
 *每次把与墨水边缘相连的一圈清水染色
 *利用一个队列,通过广度优先来实现
 *1.把第一个节点染色，并入队。把队头出队，把队头的同色邻居节点染色并且入队。
 *2.每次把旧的已染色点从队头依次弹出，然后把他们未染色的同色邻居染色并入队。直到旧的点都已出队，新的点都入队。
 *3.这就是染色一圈。重复此操作，一圈圈染色，直至染色队列为空
*/
#include <stdio.h>
#include "Queue.h"

#define MAPSIZE 10
#define COLORKIND 3
#define INPICTURE 1 //一个点在“图片”里
#define OUTPICTURE 0//一个点不在图片里

//用二维数组模来拟图象
//typedef (int array[MAPSIZE][MAPSIZE]) Picture;
//用队列记录一轮染色操作中被染色的点，以及旧的点数量和新的点数量
typedef struct color_queue{
    Queue queue;
    int old;
    int new;
}ColorQueue;

/*//已在Queue.h定义
//图象中一个点的坐标
typedef struct point{
    int i;//行
    int j;//列
}Point;
*/

//给图片分配数据（int）,分配进去的是随机数
void InitPicture(int g[MAPSIZE][MAPSIZE]){
    int i,j;
    int base_number=11;
    srand((unsigned)time(NULL)+rand());
    for(i=0;i<MAPSIZE;++i)
        for(j=0;j<MAPSIZE;++j){
            g[i][j]=base_number+rand()%COLORKIND;
        }
}

//打印“图片”
void DisplayPicture(int g[MAPSIZE][MAPSIZE]) {
    int i, j;
    for (i = 0; i < MAPSIZE; ++i) {
        //打印行号
        printf("%d:\t", i);
        for (j = 0; j < MAPSIZE; ++j) {
            //打印二维数组
            printf("%d,\t", g[i][j]);
        }
        printf("\n");
    }
    //和前面的空行找齐
    printf("  \t");
    //打印列号
    for (j =0; j < MAPSIZE; ++j)
        printf(".\t");
    printf("\n");
    //和前面的空行找齐
    printf("  \t");
    //打印列号
    for (j =0; j < MAPSIZE; ++j)
        printf("%d,\t", j);
    printf("\n");
}

//将一个点重新染色
void ReColorPoint(int g[MAPSIZE][MAPSIZE],Point point, int newcolor){
    g[point.i][point.j]=newcolor;
}

//判断一点是否在图片中
int IsInPicture(Point point){
    if(point.i>=0 && point.i<MAPSIZE && point.j>=0 && point.j<MAPSIZE)
        return INPICTURE;
    else
        return OUTPICTURE;
}

//将一个点的邻居染色并入队
void RecolorAndEnQueueNeighbor(Point point, int g[MAPSIZE][MAPSIZE],ColorQueue *colorQueue ,int old_color,int new_color){
    Point   point_up    =   {point.i-1,point.j},
            point_down  =   {point.i+1,point.j},
            point_left  =   {point.i  ,point.j-1},
            point_right =   {point.i,point.j+1};

    //对上面的点染色并入队
    //如果上方的点在图中并且与当前点颜色相同
    //1
    if(IsInPicture(point_up) && g[point_up.i][point_up.j]==old_color){
        //从新染色
        ReColorPoint(g,point_up,new_color);
        //入队
        EnQueue(&colorQueue->queue,point_up);
        ++colorQueue->new;
    }//if

    //对其余几个点重复此操作
    //2
    if(IsInPicture(point_down) && g[point_down.i][point_down.j]==old_color){
        //从新染色
        ReColorPoint(g,point_down,new_color);
        //入队
        EnQueue(&colorQueue->queue,point_down);
        ++colorQueue->new;
    }//if

    //3
    if(IsInPicture(point_left) && g[point_left.i][point_left.j]==old_color){
        //从新染色
        ReColorPoint(g,point_left,new_color);
        //入队
        EnQueue(&colorQueue->queue,point_left);
        ++colorQueue->new;
    }//if

    //4
    if(IsInPicture(point_right) && g[point_right.i][point_right.j]==old_color){
        //从新染色
        ReColorPoint(g,point_right,new_color);
        //入队
        EnQueue(&colorQueue->queue,point_right);
        ++colorQueue->new;
    }//if
}


/*
 * **********************************************
//算法核心部分：给制定区域重新染色
*************************************************
*/

void ReColorPicture(int g[MAPSIZE][MAPSIZE],Point point, int new_color){
    ColorQueue colorQueue;
    Point head_point;
    int old_color=g[point.i][point.j];//用来记录point原本的颜色

    //染色队列初始化
    InitQueue(&colorQueue.queue);
    colorQueue.new=0;
    colorQueue.old=0;

    //染色并加入第一个点
    ReColorPoint(g,point,new_color);
    EnQueue(&colorQueue.queue,point);
    ++colorQueue.old;

    //对相邻的点一圈一圈的染色
    while (!IsEmptyQueue(&colorQueue.queue)){
        //将所有上一圈染完色的点的下一圈同色邻居染色
        while (colorQueue.old!=0){
            head_point=DeQueue(&colorQueue.queue);
            //将一个点的同色邻居染色并入队，并更新colorQueue.new
            RecolorAndEnQueueNeighbor(head_point,g,&colorQueue,old_color,new_color);
            --colorQueue.old;
        }//while
        //染完新的一圈后，更新new和old
        colorQueue.old=colorQueue.new;
        colorQueue.new=0;
    }//while
};


int main() {
 //   printf("Hello, World!\n");
    int g[MAPSIZE][MAPSIZE];
    int newcolor,i,j;
    Point point;

    //初始化图片
    InitPicture(g);
    DisplayPicture(g);

    //输入
    printf("input point.i: ");scanf("%d",&i);point.i=i;
    printf("input point.j: ");scanf("%d",&j);point.j=j;
    if(!IsInPicture(point)){
        printf("point out of picture\n");
        exit(ERROR);
    }
    printf("input newcolor: ");scanf("%d",&newcolor);

    //重新染色
    ReColorPicture(g,point,newcolor);
    DisplayPicture(g);

    return 0;
}

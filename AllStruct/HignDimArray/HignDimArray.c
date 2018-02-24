#include <stdio.h>
#include "HignDimArray.h"
//高维数组

///////////////////////////////////////////////////////////////////////
//输入维度。由于维度不一定是通过输入得到的，所以把维度的输入方式单提出来写一个函数
int GetDim(){
    int dim;
    printf("please input dim  ");scanf("%d",&dim);
    return dim;
}

///////////////////////////////////////////////////////////////////////
//初始化维度信息
int InitDim(Dim* dim_info){
    int i;
    //输入维度
    dim_info->dim=GetDim();
    //知道是几维后，为维度数组分配空间
    dim_info->border=(int *)malloc(dim_info->dim*sizeof(int));
    if(!dim_info->border)
        exit(ERROR);
    //输入每个维度的坐标分量可以有几个值（该方向分量可达到的最大值为border[i]-1）
    for(i=0;i<dim_info->dim;++i){
        printf("input size of dim %d ",i);scanf("%d",&dim_info->border[i]);
        //border[i]不可以是0，因为至少可以取一个值0
        if(dim_info->border[i]==0) {
            printf("border can't be 0\n");
            exit(ERROR);
        }//if
    }
    //获得用来计算坐标的数组
    dim_info->CoordCal=(int *)malloc(dim_info->dim*sizeof(int));
    if(!dim_info->CoordCal)
        exit(ERROR);
    for(i=dim_info->dim-1,dim_info->CoordCal[i]=1;i>0;--i)
        dim_info->CoordCal[i-1]=dim_info->CoordCal[i]*dim_info->border[i];
    return 1;
}

///////////////////////////////////////////////////////////////////////
//初始化高维数组（为获取维度信息并分配空间）,不赋值。有专门的赋值操作
void InitHDArray(HDArray *array){
    int i;
    //初始化维度信息
    InitDim(&array->dim_info);
    //计算需要的总空间
    for(i=0,array->len=1;i<array->dim_info.dim;++i)
        array->len *= array->dim_info.border[i];
    //为数组分配空间
    array->array=(HDA_ElemType*)malloc(array->len*sizeof(HDA_ElemType));
    if(!array->array)
        exit(ERROR);
}
///////////////////////////////////////////////////////////////////////
//计算高维数组中Array[index]的index对应的高维数组坐标
//返回坐标
int *CalCoord(int index,HDArray *array){

}

///////////////////////////////////////////////////////////////////////
//计算一个高维数组中所有点的坐标
void CalAllCoord(HDArray *array, int coord[array->len][array->dim_info.dim]){
    //每个点的坐标存在coord[array->len][array->dim_info.dim]中
    //其中coord[i][j]，i表示是HDArray的第i个元素，j表示该元素第j维坐标
    //数组coord[i]就是HDArray第i个元素的坐标
    int i,j,index;
    //求坐标的原理：类似于进制转化，不断除权求余
    for(i=0;i<array->len;++i) {
        for(index=i,j=array->dim_info.dim-1;j>=0;--j){
            coord[i][j] = index % array->dim_info.border[j];
            index /= array->dim_info.border[j];
        }//for j
    }//for i

        /*       index=i;
        j=array->dim_info.dim-1;
        coord[i][j] = index % array->dim_info.border[j];
        for (j = array->dim_info.dim-2; j>=0 ;--j) {
//            index -= coord[i][j+1];   //coord[i][j]一定小于border[j]（即第j维坐标一定小于第j维上限），因此这步可以不要
            index /= array->dim_info.border[j+1];
            coord[i][j] = index % array->dim_info.border[j];
        }//for j
    */
}//CalAllCoord
///////////////////////////////////////////////////////////////////////
//给高维数组赋值
void AssignHDArray(HDArray *array){
    //每个点的坐标存在coord[array->len][array->dim_info.dim]中
    //其中coord[i][j]，i表示是HDArray的第i个元素，j表示该元素第j维坐标
    //数组coord[i]就是HDArray第i个元素的坐标
    int coord[array->len][array->dim_info.dim];
    //计算出所有点的坐标存入coord
    CalAllCoord(array,coord);
    for (int i = 0; i < array->len; ++i) {
        //打印当前位置在高维数组中的坐标
        for(int j=0; j< array->dim_info.dim ; ++j)
            printf("x%dE%d ",j,coord[i][j]);
        //为高维数组中的该位置赋值
        printf("  c= ");scanf("%d",&array->array[i]);
    }//for i
}
///////////////////////////////////////////////////////////////////////
//创建高维数组（初始化+赋值）
void CreatHDArray(HDArray *array){
    //初始化
    InitHDArray(array);
    //元素赋值
    AssignHDArray(array);
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
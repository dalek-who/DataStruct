//
// Created by wang on 17-4-5.
//

#ifndef INC_5_20_DISPLAYPOLYNOMIAL_HIGNDIMARRAY_H
#define INC_5_20_DISPLAYPOLYNOMIAL_HIGNDIMARRAY_H

/////////////////////////////////
//高维数组
/////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0

//元素类型
typedef int HDA_ElemType;
//维度信息：
typedef struct DIM{
    int dim;//数组的维数
    int *border;//每一个维度的数据个数
    int *CoordCal;//用来辅助计算坐标的数组
}Dim;

//高维数组
typedef struct HignDimArray{
    Dim dim_info;//维度信息
    HDA_ElemType *array;//存储数据的数组
    int len;//数组总共占用的长度
}HDArray;

/////////////////////////////////////////////////////////////////////
//操作
int InitDim(Dim* dim_info);//初始化维度信息
void InitHDArray(HDArray *array);//初始化高维数组（为获取维度信息并分配空间）
void CalAllCoord(HDArray *array, int coord[array->len][array->dim_info.dim]);//计算一个高维数组中所有点的坐标
void AssignHDArray(HDArray *array);//给高维数组赋值
void CreatHDArray(HDArray *array);//创建高维数组（初始化+赋值）
int GetDim();//输入维度。由于维度不一定是通过输入得到的，所以把维度的输入方式单提出来写一个函数


#endif //INC_5_20_DISPLAYPOLYNOMIAL_HIGNDIMARRAY_H

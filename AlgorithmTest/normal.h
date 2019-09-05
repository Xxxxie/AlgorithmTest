#pragma once
#include <iostream>
using namespace std;

//double 数据的整数次方
double Power(double base, int exponent);

void PowerTest();

//打印从1到最大n位数
void Print1toMaxofN(int n);

//使用全排列的方法求上述问题
void Print1toMaxofN2(int n);

void Print1toMaxifNTest();


//正则表达式匹配 
bool match(const char * str,const char * pattern);

void matchTest();

//表示数值的字符串
bool isNumber(const char* str);

void isNumberTest();

//调整数组顺序使奇数位于偶数前面
void Reorder(int * data, int num, bool(*func)(int));

void ReorderTest();

//顺时针打印矩阵
void PointMatrixClockwisely(int **number, int columsts, int rows);

void PointMCTest();

//栈的压入、弹出序列
bool IsPopOrder(const int*pPush, const int* pPop, int nLength);

void IsPopOrderTest();
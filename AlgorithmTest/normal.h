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
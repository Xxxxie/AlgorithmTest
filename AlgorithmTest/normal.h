#pragma once
#include <iostream>
using namespace std;

//double ���ݵ������η�
double Power(double base, int exponent);

void PowerTest();

//��ӡ��1�����nλ��
void Print1toMaxofN(int n);

//ʹ��ȫ���еķ�������������
void Print1toMaxofN2(int n);

void Print1toMaxifNTest();


//������ʽƥ�� 
bool match(const char * str,const char * pattern);

void matchTest();

//��ʾ��ֵ���ַ���
bool isNumber(const char* str);

void isNumberTest();

//��������˳��ʹ����λ��ż��ǰ��
void Reorder(int * data, int num, bool(*func)(int));

void ReorderTest();

//˳ʱ���ӡ����
void PointMatrixClockwisely(int **number, int columsts, int rows);

void PointMCTest();

//ջ��ѹ�롢��������
bool IsPopOrder(const int*pPush, const int* pPop, int nLength);

void IsPopOrderTest();
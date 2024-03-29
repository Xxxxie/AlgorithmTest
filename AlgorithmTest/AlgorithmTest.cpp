// AlgorithmTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//做一些算法练习

#include "pch.h"
#include <iostream>
#include "Astart.h"
#include "BinaryTree.h"
#include "TemplateClass.h"
#include "Backtracking.h"
#include "normal.h"

using namespace std;


//寻找全排列的下一个数
//基础知识为 逆序会使数变大，顺序会使数变小
void findNearestNumber(int* array, int num)
{
	int i, j;
	for (i = num-1; i > 0 ; i--)
	{
		if (array[i] > array[i - 1])
		{
			int temp = array[i - 1];
			int pos = i - 1;
			j = i;
			for (j = i; j < num; j++)
			{
				if (array[j] > temp)
				{
					array[i - 1] = array[j];
					pos = j;
				}
			}
			array[pos] = temp;
			
			break;
		}
	}

	for (j = num - 1; i < j; i++, j--)
	{
		int n = array[i];
		array[i] = array[j];
		array[j] = n;
	}


}


void printArray(int *array, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main()
{
	int array[5] = {1, 2, 3, 4, 5};

	/*
	for (int i = 0; i < 10; i++)
	{
		findNearestNumber(array, 5);

		printArray(array, 5);
	}
	*/
	//A*算法
	//aStartTest();
	//BinaryTest();
	//CQueueTest();
	//CStackTest();
	//matrixTest();
	//PowerTest();
	//Print1toMaxifNTest();
	//matchTest();
	//isNumberTest();
	//ReorderTest();
	//PointMCTest();
	//IsPopOrderTest();
	VerityOfBSTTest();









    //std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

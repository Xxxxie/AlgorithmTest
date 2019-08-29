#pragma once
#include <iostream>


//利用回溯法求矩阵中的路径


bool hasPath(char* matrix, int rows, int cols, char *str);

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col,const char* str, int & pathLength, bool* visited);

void matrixTest();
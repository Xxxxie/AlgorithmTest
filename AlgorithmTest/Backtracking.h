#pragma once
#include <iostream>


//���û��ݷ�������е�·��


bool hasPath(char* matrix, int rows, int cols, char *str);

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col,const char* str, int & pathLength, bool* visited);

void matrixTest();
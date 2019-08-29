
#include <iostream>
#include "Backtracking.h"

using namespace std;

bool hasPath(char* matrix, int rows, int cols, char *str)
{
	if (matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
	{
		return false;
	}

	bool *visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);

	int pathLength = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) 
		{
			if (hasPathCore(matrix, rows, cols, i, j, str, pathLength, visited) == true)
				return true;
		}
	}

	delete []visited;

	return false;

}

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int & pathLength, bool* visited)
{
	if (str[pathLength] == '\0')
	{
		return true;
	}

	bool hasPath = false;
	if ( row>=0 && row < rows && col >= 0 && col <cols && matrix[row*cols + col] == str[pathLength] && visited[row*cols+col] == false )
	{
		pathLength++;
		visited[row*cols + col] = true;
		cout << row << " " << col <<" " << matrix[row*cols + col] <<endl;

		hasPath = hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited) ||
			hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited) ||
			hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited) ||
			hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited);

		if (hasPath == false)
		{
			pathLength--;
			visited[row*cols + col] = false;
		}
	}

	


	return hasPath;
	
}


void matrixTest()
{
	char* martix = new char[12]{ 'a','b','t','g','c','f','c','s','j','d','e','h'};


	char* str = new char[5]{ "bace" };

	bool result = hasPath(martix, 3, 4, str);

	cout << result << endl;
}
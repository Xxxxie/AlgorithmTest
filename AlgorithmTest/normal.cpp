#include <iostream>
#include "normal.h"

using namespace std;

bool equal(double a, double b)
{
	if ((a - b > -0.000001) && (a - b) < 0.000001)
		return true;
	else
		return false;
}



double PowerWithUnsigned(double base, int exponent)
{
	double result = 1.0;
	for (int i = 1; i <= exponent; i++)
	{
		result *= base;
	}
	return result;
}

double PowerWithUnsigned2(double base, int exponent)
{

	if (exponent == 0)
	{
		return 1;
	}
	if (exponent == 1)
	{
		return base;
	}


	double result = PowerWithUnsigned2(base, exponent >> 1);

	result *= result;
	if (exponent & 0x1 == 1)
	{
		result *= base;
	}

	return result;

}



bool g_InvalidInput = false;

double Power(double base, int exponent)
{
	double result = 1.0;

	g_InvalidInput = false;

	//比较double数值类型时，不能直接采用等号
	if (equal(base, 0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
	{
		absExponent = (unsigned int)(-exponent);
	}

	//result = base;
	result = PowerWithUnsigned2(base, absExponent);

	if (exponent < 0)
	{
		result = 1.0 / result;
	}

	return result;
}



void PowerTest()
{
	double result = Power(3, 3);
	cout << result << endl;
}




bool Increment(char *number,int n)
{
	bool isOver = false;
	int nTakeOver = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == n - 1)
		{
			nSum++;
		}

		if (nSum >= 10)
		{
			if (i == 0)
			{
				isOver = true;
				
			}
			else
			{
				nTakeOver = 1;
				nSum -= 10;
				number[i] = '0' + nSum;
			}
			
			
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
		
	}


	return isOver;

}

void PrintNumber(char *number,int length)
{

	bool flag = false;


	for (int i = 0; i < length; i++)
	{
		if (!flag  && number[i] != '0')
		{
			flag = true;
		}
		if (flag)
		{
			cout << number[i];
		}
	}
	if (flag == true)
	{
		cout << endl;
	}
	
	
}



void Print1toMaxofN(int n)
{
	char * number = new char[n + 1];

	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number,n))
	{
		PrintNumber(number,n);
	}

	delete[]number;

}




void Point1toMaxofN2Recursively(char * number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number,length);
		return;
	}


	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';
		Point1toMaxofN2Recursively(number, length, index + 1);
	}

}
void Print1toMaxofN2(int n)
{
	if (n < 0)
	{
		return;
	}

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	for (int i = 0; i < 10; i++)
	{
		number[0] = i + '0';
		Point1toMaxofN2Recursively(number, n, 0);
	}

	delete[]number;
}

void Print1toMaxifNTest()
{
	Print1toMaxofN2(2);
}


bool matchCore(const char *str, const char *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return true;

	if (*str != '\0' && *pattern == '\0')
		return false;

	if (*(pattern + 1) == '*')
	{
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
		{
			return matchCore(str + 1, pattern) || matchCore(str + 1, pattern + 2) || matchCore(str, pattern + 2);
		}
		else
		{
			return matchCore(str, pattern + 2);
		}

	}

	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
	{
		return matchCore(str + 1, pattern + 1);
	}

	return false;

}


bool match(const char * str,const char * pattern)
{
	if (str == nullptr || pattern == nullptr)
		return false;

	return matchCore(str, pattern);

}

void matchTest()
{
	string  str = "aaa";
	string  pattern = "a.a";
	cout<< match(str.c_str(),pattern.c_str())<<endl;
	
}

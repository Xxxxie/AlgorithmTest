#include "TemplateClass.h"
#include <iostream>
using namespace std;
template<typename T>
void CQueue<T>::appendTail(const T & node)
{
	stack1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead()
{
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			T tmp = stack1.top();
			stack2.push(tmp);
			stack1.pop();
		}
	}


	T head = stack2.top();
	stack2.pop();

	return head;

}

template<typename T>
void CStack<T>::appendTail(const T & node)
{
	if (queue2.empty())
	{
		queue1.push(node);
	}
	else
	{
		queue2.push(node);
	}
}

template<typename T>
T CStack<T>::deleteHead()
{
	T result;
	if (queue2.empty())
	{
		result = queue1.front();
		queue1.pop();
		while (!queue1.empty())
		{
			queue2.push(result);
			result = queue1.front();
			queue1.pop();
		}
		//return result;
	}
	else
	{
		result = queue2.front();
		queue2.pop();
		while (!queue2.empty())
		{
			queue1.push(result);
			result = queue2.front();
			queue2.pop();
		}
	}

	return result;
}

void CQueueTest()
{
	CQueue<int> c;

	c.appendTail(0);
	c.appendTail(1);
	c.appendTail(2);
	cout << c.deleteHead() << endl;
	cout << c.deleteHead() << endl;
	c.appendTail(3);
	c.appendTail(4);
	cout << c.deleteHead() << endl;
	cout << c.deleteHead() << endl;

}

void CStackTest()
{
	CStack<int>c;

	c.appendTail(0);
	c.appendTail(1);
	c.appendTail(2);
	cout << c.deleteHead() << endl;
	cout << c.deleteHead() << endl;
	c.appendTail(3);
	c.appendTail(4);
	cout << c.deleteHead() << endl;
	cout << c.deleteHead() << endl;

}
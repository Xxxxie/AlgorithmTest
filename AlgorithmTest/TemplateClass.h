#pragma once

#include <stack>
#include <queue>

using namespace std;

//使用2个栈实现的队列
template <typename T>
 class CQueue
{
public:

	CQueue(void) {};
	~CQueue(void) {};

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;

};

//使用2个队列实现的栈
template <typename T> class CStack
{
public:

	CStack(void) {};
	~CStack(void) {};

	void appendTail(const T& node);
	T deleteHead();

private:
	queue<T> queue1;
	queue<T> queue2;

};

void CQueueTest();
void CStackTest();
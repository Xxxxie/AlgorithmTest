#pragma once
#include <vector>
#include <list>

#define LINE 5
#define ROW 7

using namespace std;


//A* 算法没求解迷宫问题的简单算法

//迷宫


class node
{
public:
	int x;		//横坐标
	int y;		//纵坐标
	int f;		//总步数 f=g+h
	int g;		//从起点到达当前点所需要的步数
	int h;		//从当前点到达目的地所需要的步数
	node *parent;  //指向父节点

	node() {
		parent = NULL;
	};

	node(int x, int y)
	{
		parent = NULL;
		this->x = x;
		this->y = y;
		this->g = 0;
		
	}

	
	node(const node &obj)
	{

		// 赋值stack内存的值
		this->x = obj.x;
		this->y = obj.y;
		this->f = obj.f;
		this->g = obj.g;
		this->h = obj.h;
		// 赋值heap内存的值
		this->parent = new node();
		this->parent = obj.parent;

	}
	
	/*
	~node()
	{
		if (parent != NULL)
		{
			delete parent;
		}
		//cout << "对象被释放" << endl;
	}

	*/
	void initNode(node p, node end)
	{
		node t = p;
		this->parent = &t;
		if (this->parent != NULL)
		{
			this->g = p.g +1;
		
		}
		else
		{
			this->g = 1;
		}

		this->h = abs(this->x - end.x) + abs(this->y - end.y);

		this->f = this->h + this->g;
	}



};

void aStartTest();


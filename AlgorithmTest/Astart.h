#pragma once
#include <vector>
#include <list>

#define LINE 5
#define ROW 7

using namespace std;


//A* �㷨û����Թ�����ļ��㷨

//�Թ�


class node
{
public:
	int x;		//������
	int y;		//������
	int f;		//�ܲ��� f=g+h
	int g;		//����㵽�ﵱǰ������Ҫ�Ĳ���
	int h;		//�ӵ�ǰ�㵽��Ŀ�ĵ�����Ҫ�Ĳ���
	node *parent;  //ָ�򸸽ڵ�

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

		// ��ֵstack�ڴ��ֵ
		this->x = obj.x;
		this->y = obj.y;
		this->f = obj.f;
		this->g = obj.g;
		this->h = obj.h;
		// ��ֵheap�ڴ��ֵ
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
		//cout << "�����ͷ�" << endl;
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


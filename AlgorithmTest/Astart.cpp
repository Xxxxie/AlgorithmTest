#include "Astart.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;


int MAZE[LINE][ROW] = {
	{0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,0,0,0,0}
};


bool containNode(node Node,list<node> List)
{

	int x = Node.x;
	int y = Node.y;

	for (list<node>::iterator iter = List.begin(); iter != List.end(); iter++)
	{
		if (iter->x == x && iter->y == y)
		{
			return true;
		}
	}

	return false;
}

bool isViledNode(node n, list<node> openlist, list<node> closeList)
{
	int x = n.x;
	int y = n.y;

	if (x<0 || x>LINE || y<0 || y>ROW)
	{
		return false;
	}

	if (MAZE[x][y] == 1)
	{
		return false;
	}

	if (containNode(n,openlist))
	{
		return false;
	}

	if (containNode(n, closeList))
	{
		return false;
	}

	return true;



}


//寻找当前openList中f最小的点 并删除
node findMinNode(list<node> openlist)
{
	node temp = *openlist.begin();
	node t;
	list<node>::iterator min =openlist.begin();
	int los = 0;
	int i = 0;
	for (list<node>::iterator iter = openlist.begin(); iter != openlist.end(); iter++ )
	{

		if (iter->f < temp.f)
		{
			temp.x = iter->x;
			temp.y = iter->y;
			temp.parent = iter->parent;
			temp.f = iter->f;
			temp.g = iter->g;
			temp.h = iter->h;
			
		}
	}
	t = temp;
	return t;
}



list<node> findNeighbors(node Node, list<node> openlist, list<node> closelist)
{
	list<node> neighbors;


	node temp1(Node.x, Node.y - 1);
	node temp2(Node.x, Node.y + 1);
	node temp3(Node.x - 1, Node.y);
	node temp4(Node.x + 1, Node.y);
	if (isViledNode(temp1, openlist, closelist))
	{
		neighbors.push_back(node(Node.x, Node.y - 1));
	}

	if (isViledNode(temp2, openlist, closelist))
	{
		neighbors.push_back(node(Node.x, Node.y + 1));
	}

	if (isViledNode(temp3, openlist, closelist))
	{
		neighbors.push_back(node(Node.x - 1, Node.y));
	}

	if (isViledNode(temp4, openlist, closelist))
	{
		neighbors.push_back(node(Node.x + 1, Node.y));
	}


	return neighbors;
}

bool isContains(node Node, list<node> openlist)
{
	int x = Node.x;
	int y = Node.y;
	for (list<node>::iterator iter = openlist.begin(); iter != openlist.end(); iter++)
	{
		if (iter->x == x && iter->y == y)
		{
			return true;
		}
	}

	return false;

}



list<node> deleteNode(node Node, list<node> openlist)
{
	int x = Node.x;
	int y = Node.y;
	for (list<node>::iterator iter = openlist.begin(); iter != openlist.end(); iter++)
	{
		if (iter->x == x && iter->y == y)
		{
			openlist.erase(iter);
			break;
		}
	}

	return openlist;
}

node initNode(node c, node currentnode, node end)
{
	node* t = new node(currentnode);
	c.parent = t;
	if (c.parent != NULL)
	{
		c.g = t->g + 1;

	}
	else
	{
		c.g = 1;
	}

	c.h = abs(c.x - end.x) + abs(c.y - end.y);

	c.f = c.h + c.g;

	return c;
}

//node temp;

node aStartSearch(node start, node end)
{
	list<node> openList;
	list<node> closeList;
	list<node>::iterator iter;
	node temp;
	openList.push_back(start);
	
	while (openList.size() > 0)
	{
		node currentnode ;

		currentnode = findMinNode(openList);
		openList = deleteNode(currentnode, openList);

		closeList.push_back(currentnode);

		list<node> neighbor = findNeighbors(currentnode, openList, closeList);

		for (iter = neighbor.begin(); iter != neighbor.end(); iter++)
		{
			node temp ;
			if ( !isContains(*iter,openList))
			{
				temp.x = iter->x;
				temp.y = iter->y;
				//temp.initNode(currentnode, end);
				temp =initNode(temp, currentnode,end);
				openList.push_back(temp);
			}
		}

		
		for (iter = openList.begin(); iter != openList.end(); iter++)
		{
			if (iter->x == end.x && iter->y == end.y)
			{
				temp = *iter;
				return temp;
			}
		}


	}

	return temp;
}



void aStartTest()
{
	node start(2, 1);
	node end(2, 5);

	node resultNode = aStartSearch(start, end);

	/*
	while (resultNode->parent !=NULL)
	{
		node * t = resultNode->parent;
		cout << t->x << " " << t->y << endl;
		resultNode = t;

	}
	*/
	int x, y;
	while (resultNode.parent != NULL)
	{
		//cout << resultNode->x << " " << resultNode->y << endl;
		
		x = resultNode.x;
		y = resultNode.y;


		//printf("%d", x);

		//使用cout 和cerr会出现错误，我也不知道为啥
		cout << x ;
		//cout << y;

	
		resultNode = *resultNode.parent;
	}

}
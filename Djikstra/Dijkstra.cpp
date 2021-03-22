#include "Dijkstra.h"



Graph_DG::Graph_DG(int vexnum,int edge)
{
	//初始化
	this->vexnum = vexnum;
	this->edge = edge;
	arc = new int* [this->vexnum];
	dis = new Dis[this->edge];
	for (int i = 0; i < this->vexnum; i++)
	{
		arc[i] = new int[this->vexnum];
		for (int k = 0; k < this->vexnum; k++)
		{
			arc[i][k] = INT_MAX;
		}
	}

}

Graph_DG::~Graph_DG()
{
	delete[] dis;
	for (int i = 0; i < this->vexnum; i++)
	{
		delete this->arc[i];
	}
	delete arc;
}


void Graph_DG::createGraph()
{
	int start, end, weight;
	cout <<("请输入起点和终点以及权重")<<endl;
	for (int i = 0; i < this->edge; i++)
	{
		cin >> start >> end >> weight;
		arc[start - 1][end - 1] = weight;
	}
}

void Graph_DG::print()
{
	for (int i = 0; i < this->vexnum; i++)
	{
		for (int j = 0; j < this->vexnum; j++)
		{
			if (arc[i][j] == INT_MAX)
			{
				cout << "∞" << " ";
			}
			else {
				cout << arc[i][j] << " ";
			}
		}
		cout << endl;
	}
}

void Graph_DG::Dijstra(int begin)
{
	//首先从begin开始找到一个最小的节点
	int temp = 0;
	int count = 0;
	//首先初始化节点
	for (int i = 0; i < this->vexnum; i++)
	{
		dis[i].path = "V" + to_string(begin) + "--->V" + to_string(i+1);
		dis[i].value = arc[begin - 1][i];
	}
	dis[begin - 1].value = 0;
	dis[begin - 1].visit = true;
	
	while (count != this->vexnum)
	{
		int min = INT_MAX;
		for (int i = 0; i < this->vexnum; i++)
		{
			if (!dis[i].visit && dis[i].value < min)
			{
				min = dis[i].value;
				temp = i;
			}
		}
		//这里就相当于把已经寻找到的节点，放入close表中，停止下一遍的查找
		dis[temp].visit = true;
		for (int i = 0; i < this->vexnum; i++)
		{
			if (!dis[i].visit && arc[temp][i] != INT_MAX && dis[temp].value + arc[temp][i] < dis[i].value)
			{
				dis[i].value = dis[temp].value + arc[temp][i];
				dis[i].path = dis[temp].path + "--->V" + to_string(i + 1);
			}
		}
		count++;
	}
}

void Graph_DG::print_path()
{
	cout << "以输入点为起点的最短路径是：" << endl;
	for (int i = 0; i < this->vexnum; i++)
	{
		if (dis[i].value != INT_MAX)
		{
			cout << dis[i].path << " = "<<dis[i].value << endl;
		}
		else
		{
			cout << "无局部最优解" << endl;
		}
	}
}
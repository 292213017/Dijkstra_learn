#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Dis {
	string path;
	int value;
	bool visit;
	Dis() {
		visit = false;
		value = 0;
		path = "";
	}
};

class Graph_DG
{
private:
	int vexnum;
	int edge;
	//这个是存储指针的一个数组
	int** arc;
	Dis* dis;

public:
	Graph_DG(int vexnum,int edge);
	~Graph_DG();
	void createGraph();
	void print();
	void Dijstra(int begin);
	void print_path();
};
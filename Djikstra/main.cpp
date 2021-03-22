#include "Dijkstra.h"

using namespace std;

int main()
{
	int vexnum;
	int edge;

	cout << "输入图的顶点和边的条数" << endl;
	cin >> vexnum >> edge;

	////这里是定义数组的第一层
	//int ** arc = new int* [10];
	//cout << arc << endl;

	////定义数组的第二层
	//arc[1] = new int[10];
	//cout << sizeof(arc) << endl;
	//cout << sizeof(arc[1]) << endl;

	Graph_DG graph(vexnum,edge);
	graph.createGraph();
	graph.print();
	graph.Dijstra(1);
	graph.print_path();
	 
}
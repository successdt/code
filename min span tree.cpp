#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "time.h"
#define N 2000
#define MAXINT 1000
using namespace std;
int graph[N][N] , mst[N][N] , label[N];
void add_edge(int graph[N][N], int i, int j, int arc){
	graph[i][j] = graph[j][i] = arc;
}
void init_label(int label[N]){
	for(int i = 0 ; i < N ; ++i){
		label[i] = i;
	}
}
int get_label(int i, int label[N]){
	return label[i];
}
int is_different_tree(int i, int j, int label[N]){
	return (get_label(i, label) == get_label(j, label) ? 0 : 1);
}
//merge edge to mst
void merge (int i , int j, int mst[N][N]){
	mst[i][j] = mst[j][i] = 1;

}
// chage the vertex's label
void update (int i, int j, int label[N]){
	for (int k = 0; k < N; ++k)
	{
		if (label[k] == j)
		{
			label[k] = i;
			
		}
	}
}
void find_min_edge(int graph[N][N], int mst[N][N], int label[N]){
	int n = 0;
	int tmp;
	int min, node1, node2;
	mst[0][0] = 0;
	for (int i = 0; i < N; ++i)
	{
		min = MAXINT;
		for (int j = 0; j < N; ++j)
		{
			//xet cac vertex thuoc cung 1 label - tuc la cung 1 cay
			if (get_label(i, label) == get_label(j, label))
			{
				for (int k = 0; k < N; ++k){
					// tim edge co chieu dai nho nhat va thuoc 2 cay khac nhau
					if ((min > graph[j][k]) && (graph[j][k]) &&(get_label(j,label) != get_label(k, label)))
					{
						min	= graph[j][k];
						node1 = j;
						node2 = k;
					}
				}
			}
		}
		merge(node1, node2, mst); //them 2 vertex i, j vao mst
		update(get_label(node1,label), get_label(node2, label), label); //thay doi label cua j
	}
	
}
//in ra cay
void print_tree(int graph[N][N]){
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << graph[i][j]<<" ";
		}
		cout <<"\n";
	}
}
int main(int argc, char * argv[])
{
	int edge ;
	int start, finish;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i+1; j < N; ++j)
		{
			edge = rand() % 100;
			add_edge(graph, i , j, edge );
		}
	}
	//print_tree(graph);
	init_label(label);
	start = clock();
	find_min_edge(graph, mst, label);
	finish = clock();
	//print_tree(mst);
	cout <<"\n"<<"Thoi gian thuc hien la: "<<(finish - start)/double(CLOCKS_PER_SEC)*1000<<"ms"<<endl;
	return 0;
}
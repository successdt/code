#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#define N 6
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
//tim canh nho nhat
void merge (int i , int j, int mst[N][N]){
	mst[i][j] = mst[j][i] = 1;

}
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
			if (get_label(i, label) == get_label(j, label))
			{
				for (int k = 0; k < N; ++k){
					if ((min > graph[j][k]) && (graph[j][k]) &&(get_label(j,label) != get_label(k, label)))
					{
						min	= graph[j][k];
						node1 = j;
						node2 = k;
					}
				}
			}
		}
		merge(node1, node2, mst);
		update(get_label(node1,label), get_label(node2, label), label);
	}
	
}

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
	for (int i = 0; i < N; ++i)
	{
		for (int j = i+1; j < N; ++j)
		{
			edge = rand() % 10;
			add_edge(graph, i , j, edge );
		}
	}
	print_tree(graph);
	init_label(label);
	find_min_edge(graph, mst, label);
	print_tree(mst);
	return 0;
}
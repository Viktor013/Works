#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#define N 5
using namespace std;
 
int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < N; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}
 

void printMST(int parent[], int graph[N][N])
{
	int count = 0;
    cout<<"Край \t Вес\n";
    for (int i = 1; i < N; i++) {
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
        count += graph[i][parent[i]];
    	}
    cout << "\n Общий минимальный вес: " << count;
        
}
 

void primMST(int graph[N][N])
{
    int parent[N];
     
    int key[N];
     
    bool mstSet[N];
 
    for (int i = 0; i < N; i++)
        key[i] = INT_MAX, mstSet[i] = false;
        
    key[0] = 0;
    parent[0] = -1; 
 

    for (int count = 0; count < N - 1; count++)
    {

        int u = minKey(key, mstSet);
 
        mstSet[u] = true;
 
        for (int v = 0; v < N; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}
 
int main()
{
    setlocale(LC_ALL, "rus");
    int graph[N][N]; 
	for(int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << "Введите граф [" << i << "][" << j << "] ";
                cin >> graph[i][j];
            }
        }
 
    primMST(graph);
 
    return 0;
}

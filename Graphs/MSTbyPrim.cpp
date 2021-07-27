#include <iostream>
#include <climits>
using namespace std;

//Given an undirected, connected and weighted graph G(V, E) with V number of vertices 
//(which are numbered from 0 to V-1) and E number of edges.
//Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
//input:
//4 4
//0 1 3
//0 3 5
//1 2 1
//2 3 8
//output:
//0 1 3
//1 2 1
//0 3 5

void prim(int** edges,int v)
{
    int* weights = new int[v];
    bool* visited = new bool[v];
    weights[0]=0;
    visited[0]=false;
    for(int i=1;i<v;i++)
    {
        weights[i]=INT_MAX;
        visited[i]=false;
    }
    int* parent = new int[v];
    parent[0]=-1;
    int minwin;
    for(int k=0;k<v;k++)
    {
    	int p;
        minwin=-1;
        for(p=0;p<v;p++)
    	{
    	    if((weights[p]<weights[minwin] || minwin==-1) && !visited[p])
    	    {
    	        minwin=p;
    	    }
    	}
        //cout << minwin << ": " << weights[minwin] << endl;
        visited[minwin]=true;
    	for(int i=0;i<v;i++)
    	{
    	    if(minwin==i)
    	        continue;
    	    if(edges[minwin][i]!=0 && !visited[i])
    	    {
    	        if(edges[minwin][i]<weights[i])
    	        {
    	            weights[i] = edges[minwin][i];
    	            parent[i] = minwin;
    	        }
    	    }
    	}
    }
    for(int i=1;i<v;i++)
    {
        int a = min(parent[i],i);
        int b = max(parent[i],i);
        cout << a << " " << b << " " << weights[i] << endl;
    }
}

int main() {
    // Write your code here
    int v,e;
    cin >> v >> e;
    int** edges = new int*[v];
    for(int i=0;i<v;i++)
    {
        edges[i] = new int[v];
        for(int j=0;j<v;j++)
			edges[i][j]=0;
    }
    for(int i=0;i<e;i++)
    {
        int f,s,w;
        cin >> f >> s >> w;
        edges[f][s]=w;
        edges[s][f]=w;
    }
    prim(edges,v);
    
}
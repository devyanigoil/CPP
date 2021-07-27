#include <iostream>
#include<climits>
using namespace std;

//Given an undirected, connected and weighted graph G(V, E) with V number of vertices 
//(which are numbered from 0 to V-1) and E number of edges.
//Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices 
//(including source vertex also) using Dijkstra's Algorithm.

//input:
//4 4
//0 1 3
//0 3 5
//1 2 1
//2 3 8
//output:
//0 0
//1 3
//2 4
//3 5

void Dijkstra(int** edges,int v)
{
    int* distance = new int[v];
    bool* visited = new bool[v];
    for(int i=0;i<v;i++)
    {
        distance[i] = INT_MAX;
     	visited[i]=false;   
    }
    distance[0]=0;
    int mindist;
    for(int i=0;i<v-1;i++)
    {
        mindist=-1;
        for(int j=0;j<v;j++)
        {
            if((mindist==-1 || distance[j]<distance[mindist]) && !visited[j])
                mindist=j;
        }
        //cout << mindist << endl;
        visited[mindist]=true;
        for(int k=0;k<v;k++)
        {
            if(k==mindist)
                continue;
            if(!visited[k] && edges[mindist][k]!=0)
            {
                int dist = distance[mindist] + edges[mindist][k];
                if(dist<distance[k])
                    distance[k] = dist;
            }
        }
    }
    for(int i=0;i<v;i++)
    {
        cout << i << " " << distance[i] << endl;
    }
    delete [] visited;
    delete [] distance;
}

int main() {
    // Write your code here
    int v,e;
    cin >> v >> e;
    int** edges = new int*[v];
    for(int i=0;i<v;i++)
    {
        edges[i]=new int[v];
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
    Dijkstra(edges,v);
}
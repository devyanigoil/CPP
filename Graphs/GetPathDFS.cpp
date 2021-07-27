#include <iostream>
#include <vector>
using namespace std;

//Get path using DFS technique
//eg: 4 4 // no. of vertices and edges
//0 1
//0 3
//1 2
//2 3
//1 3 // starting and ending vertex
//output: 3 0 1

vector<int>* getpath(int** edges,int v,int sv,int ev,int* visited)
{
    if(sv==ev)
    {
        vector<int>* path = new vector<int>();
        path->push_back(sv);
        return path;
    }
    visited[sv] = 1;
    for(int i=0;i<v;i++)
    {
        if(i==sv)
            continue;
        if(edges[sv][i]==1)
        {
            if(visited[i]==1)
                continue;
    		vector<int>* p = getpath(edges,v,i,ev,visited);
            if(p!=NULL)
            {
                p->push_back(sv);
                return p;
            }
        }
    }
    return NULL;
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
            edges[i][j] = 0;
    }
    
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin >> a >> b;
        edges[a][b]=1;
        edges[b][a] = 1;
    }
    int v1,v2;
    cin >> v1 >> v2;
    int* visited = new int[v];
    for(int i=0;i<v;i++)
        visited[i] = 0;
    vector<int>* path = getpath(edges,v,v1,v2,visited);
    if(path)
    {
        for(int i=0;i<path->size();i++)
        	cout << path->at(i) << " ";
    }
    delete [] visited;
    delete [] edges;
}
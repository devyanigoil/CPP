#include <iostream>
#include<queue>
using namespace std;

void print(int** edges,int v,int sv,bool* visited)
{
    if(v==0)
        return;
    queue<int> vertice;
    vertice.push(sv);
    while(vertice.size()!=0)
    {
        int ele = vertice.front();
        cout << ele << " ";
        visited[ele] = true;
        vertice.pop();	
        for(int i=0;i<v;i++)
        {	
            if(i==sv)	
                continue;	
            if(edges[ele][i]==1 && !visited[i])
            {	
                vertice.push(i);
                visited[i] = true;
            }	
        }	
    }	
}

void BFSdisconnect(int** edges,int v)
{
    bool* visited = new bool[v];
    for(int i=0;i<v;i++)
        visited[i] = false;
    for(int i=0;i<v;i++)
    {
        if(!visited[i]) //handles disconnected graphs too
    		print(edges,v,i,visited);
    }
    delete [] visited;
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
        int f,s;
        cin >> f >> s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    BFSdisconnect(edges,v);
    delete [] edges;
}
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

//Get the shortest path with BFS
//bfs always gives shortest path
//eg: 8 7 //np. of vertices and edges
//0 1
//0 2
//0 7
//1 4
//4 5
//5 6
//2 6
//0 6 // starting and ending vertices

void getpath(int** edges,int v,int sv,int ev,int* visited)
{
    if(sv<0 || ev<0 || sv>=v || ev>=v)
        return;
    unordered_map<int,int> ourmap;
    queue<int> pq;
    pq.push(sv);
    visited[sv] = 1;
    while(!pq.empty())
    {
        int ele = pq.front();
        pq.pop();
        for(int i=0;i<v;i++)
        {
            if(i==ele)
                continue;
            if(edges[ele][i]==1 && !visited[i]==1)
            {
                pq.push(i);
                visited[i]=1;
                ourmap[i]=ele;
                if(i==ev)
                	break;
            }
        }
        if(ourmap.count(ev)>1)
            break;
    }
    
    if(ourmap.count(ev)==0)
    	return;
    
    int i=ev;
    cout << i << " ";
    while(true)
    {
        if(i==sv)
            break;
        cout << ourmap[i] << " ";
        i=ourmap[i];
    }
    return;
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
	getpath(edges,v,v1,v2,visited);
    delete [] visited;
    delete [] edges;
}
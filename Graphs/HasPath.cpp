#include <iostream>
using namespace std;

//Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), 
//check if there exists any path between them or not. Print true if the path exists and false otherwise.
//input: 6 7 // no. of edges and vertices
//0 1
//1 2
//2 3
//1 3
//1 4
//3 4
//3 5
//1 5 //starting and ending vertex
//ouput: true

bool check(int** edges,int v,int sv,int ev,int* visited)
{
    
    if(edges[sv][ev]==1 || sv==ev)
        return true;
    visited[sv] = 1;
    for(int i=0;i<v;i++)
    {
        if(i==sv)
            continue;
        if(edges[sv][i]==1)
        {
            if(visited[i]==1)
                continue;
            bool ans = check(edges,v,i,ev,visited);
            if(ans)
                return true;
        }
    }
    return false;
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
    bool ans = check(edges,v,v1,v2,visited);
    if(ans)
        cout << "true" << endl;
	else
        cout << "false" << endl;
}
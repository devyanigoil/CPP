#include <iostream>
using namespace std;

//Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, 
//then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which 
//(P,Q), (Q,R) and (R,P) are connected by an edge.

//input:6 4
//0 1
//0 2
//1 2
//3 4
//output: 1

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
    int count=0;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(edges[i][j]==1)
            {
                for(int k=0;k<v;k++)
            	{
                	if(edges[j][k]==1)
                    {
                        if(edges[i][k]==1)
                            count++;
                    }
                }
            }
        }
    }
    int ans = count/6; // divide by 2 because same cycle will be formed clockwise and anticlockwise and divide by 3 
                       // because same cycle will be formed by the 3 points. Hence divide by 6.
    cout << ans << endl;
}
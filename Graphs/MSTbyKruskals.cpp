#include <iostream>
#include <algorithm>
using namespace std;

//Given an undirected, connected and weighted graph G(V, E) with V number of vertices 
//(which are numbered from 0 to V-1) and E number of edges.
//Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
//input: 
//4 4
//0 1 3
//0 3 5
//1 2 1
//2 3 8
//output:
//1 2 1
//0 1 3
//0 3 5

class edges
{
    public:
    int source;
    int destination;
    int weight;
    
    edges()
    {
        source=0;
        destination=0;
        weight=0;
    }
    
    void print()
    {
        cout << source << " " << destination << " " << weight << endl;
    }
};

bool sortbyweight(const edges &lhs,const edges &rhs)
{
    return (lhs.weight<rhs.weight);
}

int main() {
    // Write your code here
    int v,e;
    cin >> v >> e;
    edges input[e];
    for(int i=0;i<e;i++)
    {
        cin >> input[i].source >> input[i].destination >> input[i].weight;
    }
    edges output[v-1];
    int parent[v];
    for(int i=0;i<v;i++)
        parent[i]=i;
    
    sort(input,input+e,sortbyweight);
    int count=0;
    int ed=0;
    while(count<v-1)
    {
        int v1 = input[ed].source;
        int v2 = input[ed].destination;
        int p1 = parent[v1],p2 = parent[v2];
        int c1 = v1,c2=v2;
        while(p1!=c1)
        {
            c1=p1;
            p1=parent[p1];
        }
        while(p2!=c2)
        {
            c2=p2;
            p2=parent[p2];
        }
        if(p1==p2)
        {
            ed++;
            continue;
        }
        
        output[count].source=min(input[ed].source,input[ed].destination);
        output[count].destination=max(input[ed].source,input[ed].destination);
        output[count].weight = input[ed].weight;
        
        parent[p1] = p2;
        ed++;
        count++;
    }
    
    for(int i=0;i<v-1;i++)
        output[i].print();
}
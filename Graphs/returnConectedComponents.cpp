#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
//Print different components in new line. And each component should be printed in increasing order (separated by space). 
//input: 6 4
//0 1 
//0 2
//1 2
//3 4
//output: 0 1 2 
//3 4 
//5  

//Using DFS
void ConnectedCompo(int** edges,int v,int sv,bool* visited,vector<int>* vect)
{
    visited[sv]=1;
    vect->push_back(sv);
    for(int i=0;i<v;i++)
    {
        if(i==sv)
        	continue;
        if(edges[sv][i]==1 && !visited[i])
        {
            ConnectedCompo(edges,v,i,visited,vect);
        }
    }
    return; 
}

vector<vector<int>> DFSdisconnected(int** edges,int v)
{
    bool* visited = new bool[v];
	for (int i = 0; i < v; ++i)
	{
		visited[i] = false;
	}
    vector<int>* vect = new vector<int>();
    vector<vector<int>> ans;
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
        {
            ConnectedCompo(edges,v,i,visited,vect);
            vector<int> temp;
            for(int i=0;i<vect->size();i++)
                temp.push_back(vect->at(i));
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            while(!vect->empty())
                vect->pop_back();
        }
	}
    return ans;
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
	vector<vector<int>> res = DFSdisconnected(edges,v);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res.at(i).size();j++)
        	cout << res.at(i).at(j) << " ";
        cout << endl;
    }
}
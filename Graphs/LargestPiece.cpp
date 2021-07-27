#include <iostream>
#include <vector>
#include<climits>
using namespace std;

//It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . 
//But Gary wants the biggest piece of '1's and no '0's . 
//A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other 
//on the cake. Given the size of cake N and the cake, can you find the count of '1's in the 
//biggest piece of '1's for Gary ?

//input:
//3
//1 0 0
//0 1 0
//0 1 0
//output:
//2

//Trick: can only move in the four main directions

int getcount(vector<vector<int>> &cake,int** visited, int n,int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=n)
        return 0;
    if(visited[i][j]==1)
        return 0;
    if(cake[i][j]==0)
        return 0;
    visited[i][j]=1;
    int c1 = getcount(cake,visited,n,i,j-1);
    int c2 = getcount(cake,visited,n,i-1,j);
    int c3 = getcount(cake,visited,n,i,j+1);
    int c4 = getcount(cake,visited,n,i+1,j);
    int count = 1+c1+c2+c3+c4;
    return count;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    int res=INT_MIN;
    int** visited = new int*[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = new int[n];
        for(int j=0;j<n;j++)
            visited[i][j]=0;
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j]==0)
            {
                int ans = getcount(cake,visited,n,i,j);
                if(ans>res)
                    res = ans;
            }
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);

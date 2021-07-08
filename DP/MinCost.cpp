#include <bits/stdc++.h>
using namespace std;

//An integer matrix of size (M x N) has been given. 
//Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
//input: 3 3
// 1 2 3 4 5 6 7 8 9
// output: 15

//DP time complexity : O(m*n)
int minCostPathDP(int **input, int m, int n)
{
	int** output = new int*[m];
	for (int i = 0; i < m; ++i)
	{
		output[i] = new int[n];
	}

	output[m-1][n-1] = input[m-1][n-1];

	for (int j = n-2; j >= 0; j--)
	{
		output[m-1][j] = input[m-1][j+1] + input[m-1][j];
	}
	for (int i = m-2; i >=0; --i)
	{
		output[i][n-1] = output[i+1][n-1]+input[i][n-1];
	}

	for (int i = m-2; i >=0; --i)
	{
		for(int j=n-2;j>=0;j--)
		{
			output[i][j] = min(output[i][j+1],min(output[i+1][j],output[i+1][j+1])) + input[i][j];
		}
	}
	return output[0][0];
}

//Memoization time complexity: O(m*n)
int minCostPathMemhelper(int **input, int i, int m, int j, int n,int** output)
{
	if(i==m-1 && j==n-1)
        return input[i][j];
    if(i>=m || j>=n || i<=-1 || j<=-1)
        return INT_MAX;

    if(output[i][j]!=-1)
    	return output[i][j];

    int cost1 = minCostPathMemhelper(input,i+1,m,j,n,output);
    int cost2 = minCostPathMemhelper(input,i,m,j+1,n,output);
    int cost3 = minCostPathMemhelper(input,i+1,m,j+1,n,output);
    
    int a = min(cost1,min(cost2,cost3))+input[i][j];
    output[i][j]=a;
    return a;
}
int minCostPathMem(int **input, int m, int n)
{
	int** output = new int*[m];
	for (int i = 0; i < m; ++i)
	{
		output[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			output[i][j]=-1;
		}
	}
	
	return minCostPathMemhelper(input,0,m,0,n,output);
}

//BruteForce time complexity: O(3^n)
int helper(int **input, int i, int m, int j, int n)
{
    if(i==m-1 && j==n-1)
        return input[i][j];
    if(i>=m || j>=n || i<=-1 || j<=-1)
        return INT_MAX;

    int cost1 = helper(input,i+1,m,j,n);
    int cost2 = helper(input,i,m,j+1,n);
    int cost3 = helper(input,i+1,m,j+1,n);
    
    return min(cost1,min(cost2,cost3))+input[i][j];    
}
int minCostPath(int **input, int m, int n)
{
	//Write your code here
    return helper(input,0,m,0,n);
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPathDP(arr, n, m) << endl;
	cout << minCostPathMem(arr, n, m) << endl;

}
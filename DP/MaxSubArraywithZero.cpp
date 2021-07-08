#include <iostream>
using namespace std;

//Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix 
//with all 0s. You need to return the size of the square matrix with all 0s.
//input: 3 3
//1 1 1
//1 1 1
//1 1 0
//output: 1

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here
    if(n==0 || m==0)
        return 0;
    int** ans = new int*[n];
    for(int i=0;i<n;i++)
        ans[i] = new int[m];
    
    //Base Case: to fill first row and first coloumn
    for(int j=0;j<m;j++)
    {
        if(arr[0][j]==0)
            ans[0][j]=1;
        else
            ans[0][j]=0;
    }
    
    for(int i=1;i<n;i++)
    {
        if(arr[i][0]==0)
            ans[i][0]=1;
        else
            ans[i][0]=0;
    }
    
    //Fill the remaining matrix
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j]==0)
            	ans[i][j] = min(ans[i-1][j-1],min(ans[i-1][j],ans[i][j-1])) + 1;
            else
                ans[i][j]=0;
        }
    }
    
    //find max and return
    int max=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(ans[i][j]>max)
                max = ans[i][j];
        }
    }
    return max;
}

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}
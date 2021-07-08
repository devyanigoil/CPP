#include <iostream>
#include<climits>
using namespace std;
#include<climits>

//A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, 
//and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?
//input: 3
//4 5 1
//1 2 3
//4
//output: 3

//DP
int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    int** output = new int*[n+1];
    for(int i=0;i<n+1;i++)
        output[i] = new int[maxWeight+1];
    int w = maxWeight;
    for(int j=0;j<w+1;j++)
        output[n][j]=0;
    for(int i=n-1;i>=0;i--)
        output[i][0] = 0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j<w+1;j++)
        {
            int a = output[i+1][j];
            int b = INT_MIN;
            if(weight[i]<=j)
                b = output[i+1][j-weight[i]] + value[i];
            output[i][j] = max(a,b);
        }
    }
    return output[0][maxWeight];
}

//Brute Force
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
    if(n==0 || maxWeight==0)
        return 0;
    int a=INT_MIN;
    if(weights[0]<=maxWeight)
    	a = values[0] + knapsack(weights+1,values+1,n-1,maxWeight-weights[0]);
    
    int b = knapsack(weights+1,values+1,n-1,maxWeight);
    
    return max(a,b);
}

int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}
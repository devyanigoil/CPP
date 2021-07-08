#include <iostream>
using namespace std;

//A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. 
//Find the maximum amount of money he can loot.

//DP
int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    int *ans = new int[n+1];
	ans[0] = 0;
    ans[1] = arr[0];
    
    for(int i=2;i<=n;i++)
    {
        int op1 = ans[i-2] + arr[i-1];
        int op2 = ans[i-1];
        ans[i] = max(op1,op2);
    }
    
    return ans[n];
}

//Brute Force
int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    if(n<=0)
        return 0;
    if(n==1)
        return arr[0];
    
    int a = arr[1] + maxMoneyLooted(arr+3,n-3);
    int b = arr[0] + maxMoneyLooted(arr+2,n-2);
    
    return max(a,b);
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}
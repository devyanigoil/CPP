#include <iostream>
using namespace std;

//For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. 
//You need to figure out the total number of ways W, in which you can make the change for Value V 
//using coins of denominations D.
//input: 3
// 1 2 3
// 4
//output: 4
// (1,1,1,1), (2,2), (1,1,2), (1,3)


//DP
int countWaysToMakeChange(int d[],int num, int v)
{
    int** ans = new int*[num+1];
    for(int i=0;i<=num;i++)
        ans[i] = new int[v+1];
    
    for(int j=1;j<=v;j++)
        ans[0][j] = 0;
    for(int i=0;i<=num;i++)
        ans[i][0] = 1;
    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=v;j++)
        {
            int ans2 = ans[i][j-d[i-1]];
            if(j-d[i-1]<0)
                ans2 = 0;
            ans[i][j] = ans[i-1][j] + ans2;
        }
    }
    return ans[num][v];
}

//Brute Force
//Logic: to not choose the last denomination once and to choose the last denomination at least once 
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	//Write your code here
    if(value==0)
        return 1;
    if(value<0)
        return 0;
    if(numDenominations<=0 && value>0)
        return 0;
    
    return countWaysToMakeChange(denominations,numDenominations-1,value) + countWaysToMakeChange(denominations,numDenominations,value-denominations[numDenominations-1]);
}

int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}
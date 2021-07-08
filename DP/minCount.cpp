#include <bits/stdc++.h>
#include<cmath>
#include<climits>
using namespace std;

//Prompt: Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
//That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. 
//The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

//DP
int minCount(int n)
{
    int* ans = new int[n+1];
    ans[0]=0;
    ans[1]=1;
    ans[2]=2;
    ans[3]=3;

    for(int i=4;i<n+1;i++)
    {
        for(int j=1;j<=sqrt(n);j++)
        	ans[i] = 1+ans[i-(j*j)];
    }
    return ans[n];
}

//Brute Force
//int minCount(int n)
//{
//	//Write your code here
//    if(n<=1)
//        return n;
//    int steps,min=INT_MAX;
//    for(int i=1;i<=sqrt(n);i++)
//    {
//        steps = 1+minCount(n-(i*i));
//        if(steps<min)
//            min = steps;
//    }
//    return min;
//}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}
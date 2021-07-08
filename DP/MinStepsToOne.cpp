#include <bits/stdc++.h>
#include<climits>
using namespace std;

//Dynamic Programming
int countStepsToOne(int n)
{
    //Write your code here
    int* ans = new int[n+1];
    ans[0]=0;
    ans[1]=0;
    ans[2]=1;
    ans[3]=1;
    for(int i=4;i<=n;i++)
    {
        int temp1 = ans[i-1];
        int temp2=INT_MAX,temp3=INT_MAX;
        if(i%2==0)
            temp2 = ans[i/2];
        if(i%3==0)
            temp3 = ans[i/3];
        ans[i] = 1+min(temp1,min(temp2,temp3));
    }
    return ans[n];
}

//Memoization
int minSteps2helper(int n,int* ans)
{
    if(n<=1)
        return 0;

    if(ans[n]!=-1)
        return ans[n];
    int x = INT_MAX,y=INT_MAX,z=INT_MAX;
    x = minSteps2helper(n-1,ans);
    if(n%2==0)
        y = minSteps2helper(n/2,ans);
    if(n%3==0)
        z = minSteps2helper(n/3,ans);
    int output = min (x,min(y,z))+1;
    ans[n]=output;
    return output;
}

int minSteps2(int n)
{
    int *ans = new int[n+1];
    for (int i = 0; i < n+1; ++i)
    {
        ans[i] = -1;
    }
    return minSteps2helper(n,ans);
}

int countMinStepsToOne(int n)
{
	//Write your code here
    if(n<=1)
        return 0;
	int y=INT_MAX,z=INT_MAX,x=INT_MAX;
    x = countMinStepsToOne(n-1);
    if(n%2==0)
    	y = countMinStepsToOne(n/2);
    if(n%3==0)
    	z = countMinStepsToOne(n/3);
    int ans = min(x,min(y,z));
    return ans+1;
}

int main()
{
    int n;
    cin >> n;
    //cout << countMinStepsToOne(n);
    cout << minSteps2(n);
}
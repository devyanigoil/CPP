#include <iostream>
#include <string>
using namespace std;

//Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. 
//Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. 
//The person to make the last move wins the game. Can you find out who wins the game?
//input: 10 2 4
//output: Beerus

//DP
string findWinner(int n, int x, int y)
{
	// Write your code here .
    int* ans = new int[n+1];
    ans[0] = 1;
    ans[1] = 1;
    ans[x] = 1;
    ans[y] = 1;
    for(int i=2;i<=n;i++)
    {
        if(i==x || i==y)
            continue;
        int ans2=0,ans3=0;
        if(i-x>=1)
            ans2 = ans[i-x]^1;
        if(i-y>=1)
            ans3 = ans[i-y]^1;
        ans[i] = (ans[i-1]^1) ^ ans2 ^ ans3;
    }
    if(ans[n]==1)
        return "Beerus";
    else 
        return "Whis";
}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}
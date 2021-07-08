#include <iostream>
using namespace std;

long staircase(int n)
{
	//Write your code here
    if(n<=2)
        return n;
    long* ans = new long[n+1];
    
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;
    for(int j=4;j<=n;j++)
    {
        ans[j] = ans[j-1]+ans[j-2]+ans[j-3];
    }
    return ans[n];
}
int main()
{
    int n;
    cin >> n;
    cout << staircase(n);
}
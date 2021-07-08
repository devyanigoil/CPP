#include <iostream>
#include<cmath>
using namespace std;

//DP
int balancedBTs(int n) {
    // Write your code here
    int* ans = new int[n+1];
    
    ans[0] = 1;
    ans[1] = 1;
    int balfactor = (int)(pow(10,9))+7;
    for(int i=2;i<n+1;i++)
    {
        int temp1 = (int)(((long)(ans[i-1])*ans[i-1])%balfactor);
        int temp2 = (int)((2*(long)(ans[i-1])*ans[i-2])%balfactor);
        ans[i] = (temp1+temp2)%balfactor;
    }
    return ans[n];
}

//Brute Force
int balancedBTs(int n) {
    // Write your code here
    if(n<=1)
        return 1;
    
    int balfact = (int) (pow(10,9)) + 7;
    int op1 = balancedBTs(n-1);
    int op2 = balancedBTs(n-2);
    
    int temp1 = (int)(((long)(op1)*op1) % balfact);
    int temp2 = (int)((2*(long)(op1)*op2)%balfact);
    
    int ans = (temp1+temp2) % balfact;
    return ans;
}

//eg: input: 4
// output: 315
// for 3 ans would be 15
int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
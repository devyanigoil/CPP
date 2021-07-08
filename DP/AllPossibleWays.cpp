#include <iostream>
#include<cmath>
using namespace std;

//Given two integers a and b. You need to find and return the count of possible ways in which we can 
//represent the number a as the sum of unique integers raise to the power b.
//input: 100 2
// output: 3
//1. 100 = 10^2
//2. 100 = 8^2 + 6^2
//3. 100 = 7^2+5^2+4^2+3^2+1^2

//Recursion
int getAllWayshelper(int a, int b, int num)
{
    int val = a-pow(num,b);
    if(val==0)
        return 1;
    if(val<0)
        return 0;
    
    return getAllWayshelper(val,b,num+1) + getAllWayshelper(a,b,num+1);
}

int getAllWays(int a, int b) {
    // Write your code here
    return getAllWayshelper(a, b, 1);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}
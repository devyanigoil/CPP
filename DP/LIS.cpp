#include <iostream>
using namespace std;

//Given an array with N elements, you need to find the length of the longest subsequence 
//in the given array such that all elements of the subsequence are sorted in strictly increasing order.

//eg: input: 4
// 1 1 1 1
//output: 1
//input: 6 
//15 4 11 1 6 18
//output: 3

//DP
int longestIncreasingSubsequence(int* arr, int n) {
    // Write your code here
    int *ans = new int[n];
    ans[0]=1;
    
    for(int i=1;i<n;i++)
    {
        ans[i] = 1;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]>=arr[i])
                continue;
            int possAns = ans[j]+1;
            if(possAns>ans[i])
                ans[i] = possAns;
        }
    }
    int best=0;
    for(int i=0;i<n;i++)
    {
        if(best<ans[i])
            best = ans[i];
    }
    return best;
}


int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}
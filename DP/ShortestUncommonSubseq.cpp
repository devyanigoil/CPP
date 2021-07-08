#include <iostream>
#include <string>
#define MAX 2000
using namespace std;

//Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, 
//which is not a subsequence in V.
//input: babab
// babba
// output: 3
// explanation: aab is present in S but not in V

//DP
int solve(string s, string v) {
    // Write your code here
    int** ans = new int*[s.size()+1]; //2D array rows: length of s, col: length of v
    for(int i=0;i<=s.size();i++)
        ans[i] = new int[v.size()+1];
    
    for(int j=0;j<=v.size();j++)
        ans[0][j] = MAX; // when len of a is 0 ans should be max
    for(int i=1;i<=s.size();i++)
        ans[i][0] = 1;   // when len of v is 0 ans should be 1
    
    for(int i=1;i<=s.size();i++)
    {
        for(int j=1;j<=v.size();j++)
        {
            int k,ans2;
            for(k=j-1;k>=0;k--)
            {
                if(v[k]==s[i-1]) // find the rightmost occurence of the char
                    break;
            }
            if(k==-1)
                ans[i][j] = 1; // if the char is not present then answer would be 1
            else
                ans[i][j] = min(ans[i-1][j],1+ans[i-1][k]); // otherwise ans would be min of these two cases
            //first case: when char is not included
            //second case: when char is included
        }
    }
    
    return ans[s.size()][v.size()];

    //Recursive sol
    //if(s.size()==0)
    //    return MAX;
    //if(v.size()<=0)
    //    return 1;
    //
    //int i;
    //for(i=0;i<v.size();i++)
    //{
    //    if(v[i]==s[0])
    //        break;
    //}
    //if(i==v.size())
    //    return 1;
    //int a = solve(s.substr(1),v);
    //int b = 1 + solve(s.substr(1),v.substr(i+1));
    //return min(a,b);
}

int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}
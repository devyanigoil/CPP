#include <cstring>
#include <iostream>
using namespace std;

//Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
//1. Delete a character
//2. Replace a character with another one
//3. Insert a character

//input: abc
//dc
//output: 2

//DP time complexity: O(m*n)
int editDistancedp(string s1,string s2)
{
    int m = s1.size();
    int n = s2.size();
    int** output = new int*[m+1];
    for(int i=0;i<m+1;i++)
        output[i] = new int[n+1];
    
    for(int j=0;j<n+1;j++)
        output[0][j] = j;
    for (int i = 1; i < m+1; ++i)
        output[i][0] = i;

    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(s1[m-i]==s2[n-j])
                output[i][j] = output[i-1][j-1];
            else
            {
                int a = output[i][j-1];
                int b = output[i-1][j];
                int c = output[i-1][j-1];
                output[i][j] = min(a,min(b,c))+1;
            }
        }
    }
    return output[m][n];
}

//Memoization time complexity : O(m*n)
int editDistancemem(string s1,string s2,int** output)
{
    int m = s1.size();
    int n = s2.size();
    if(s1==s2)
        return 0;
    if(s1.empty())
        return s2.size();
    if(s2.empty())
        return s1.size();
    if(output[m][n]!=-1)
        return output[m][n];
    if(s1[0]==s2[0])
    {
        int x = editDistancemem(s1.substr(1),s2.substr(1),output);
        output[m][n]=x;
        return x;
    }
    else
    {
        int a = 1+editDistancemem(s1.substr(1),s2,output);
        int b = 1+editDistancemem(s1,s2.substr(1),output);
        int c = 1+editDistancemem(s1.substr(1),s2.substr(1),output);
        int ans = min(a,min(b,c));
        output[m][n]=ans;
        return ans;
    }    
}

int editDistancemem(string s1, string s2)
{
    //Write your code here
    int m = s1.size();
    int n = s2.size();
    int** output = new int*[m+1];
    for(int i=0;i<m+1;i++)
    {
        output[i] = new int[n+1];
        for(int j=0;j<n+1;j++)
            output[i][j] = -1;
    }
    return editDistancemem(s1,s2,output);
}

//Brute Force time complexity: O(3^n)
int editDistance(string s1, string s2) {
    // Write your code here
    if(s1==s2)
        return 0;
    if(s1.empty())
        return s2.size();
    if(s2.empty())
        return s1.size();
    if(s1[0]==s2[0])
    {
        int x = editDistance(s1.substr(1),s2.substr(1));
        return x;
    }
    else
    {
        int a = 1+editDistance(s1.substr(1),s2);
        int b = 1+editDistance(s1,s2.substr(1));
        int c = 1+editDistance(s1.substr(1),s2.substr(1));
        int ans = min(a,min(b,c));
        return ans;
    }
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistancemem(s1, s2)<<endl;
    cout << editDistance(s1, s2) << endl;
    cout << editDistancedp(s1,s2) << endl;
}
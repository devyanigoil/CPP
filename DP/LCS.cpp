#include<iostream>
#include<string>
using namespace std;

//Least Common Subsequence
//input: abcdef
//befadscv
//output: 3 
//(lcs: bef)

//dp
int lcsdp(string s,string t)
{
	int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];
	for (int i = 0; i < m+1; ++i)
	{
		output[i] = new int[n+1];
	}

	for (int j = 0; j < n+1; ++j)
	{
		output[0][j] = 0;
	}
	for (int i = 1; i < m+1; ++i)
	{
		output[i][0] = 0;
	}

	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(s[m-i]==t[n-j])
				output[i][j] = 1+ output[i-1][j-1];
			else
			{
				int a = output[i-1][j];
				int b = output[i][j-1];
				int c = output[i-1][j-1];
				output[i][j] = max(a,max(b,c));
			}
		}
	}
	return output[m][n];
}

//Memoization time complexity: O(mn)
int lcsmem(string s,string t, int** output)
{
	int m = s.size();
	int n = t.size();
	if(s.size()==0 || t.size()==0)
		return 0;

	if(output[m][n]!=-1)
		return output[m][n];
	int ans;
	if(s[0]==t[0])
	{
		ans = 1+lcsmem(s.substr(1),t.substr(1),output);
	}
	else
	{
		int a = lcsmem(s.substr(1),t,output);
		int b = lcsmem(s,t.substr(1),output);
		int c = lcsmem(s.substr(1),t.substr(1),output); //can omit this call
		ans = max(a,max(b,c));
	}
	output[m][n] = ans;
	return ans;
}

int lcsmem(string s,string t)
{
	int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];
	for (int i = 0; i < m+1; ++i)
	{
		output[i] = new int[n+1];
		for(int j=0;j<n+1;j++)
			output[i][j] = -1;
	}
	return lcsmem(s,t,output);
}

//Recursion time complexity: 3^n or 2^n
int lcs(string s,string t)
{
	if(s.size()==0 || t.size()==0)
		return 0;

	if(s[0]==t[0])
		return 1+lcs(s.substr(1),t.substr(1));
	else
	{
		int a = lcs(s.substr(1),t);
		int b = lcs(s,t.substr(1));
		int c = lcs(s.substr(1),t.substr(1)); //can omit this call

		return max(a,max(b,c));
	}
}

int main()
{
	string s,t;
	cin >> s;
	cin >> t;

	cout << lcs(s,t) << endl;
	cout << lcsmem(s,t) << endl;
	cout << lcsdp(s,t) << endl;

}
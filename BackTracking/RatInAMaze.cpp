#include<bits/stdc++.h>
using namespace std;

//input: 3
//       1 0 1
//       1 0 1
//       1 1 1
//output: 1 0 0 1 0 0 1 1 1
//Rat in a maze: aim : to start from left top corner and reach bottom right corner
//0 means dead end, 1 means can go through there 
int maze[18][18];
int** ans;

void solvemaze(int m[][18],int** a,int n,int x,int y)
{
    if(x==n-1 && y==n-1)
    {
        a[x][y]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            	cout << a[i][j] << " ";
        }
    	cout << endl;
        a[x][y]=0;
        return;
    }
    
    if(x<=-1 || y<=-1 || x>=n || y>=n || m[x][y]==0 || a[x][y]==1)
        return;
    a[x][y]=1;
    solvemaze(m,a,n,x-1,y);
    solvemaze(m,a,n,x+1,y);
    solvemaze(m,a,n,x,y-1);
    solvemaze(m,a,n,x,y+1);
    a[x][y]=0;
    return;
}
int main(){
    // write your code here
    int N;
    cin >> N;
    int** ans = new int*[N];
    for(int i=0;i<N;i++)
        ans[i] = new int[N];
    for(int i=0;i<N;i++)
        memset(ans[i],0,N*sizeof(int));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> maze[i][j];

    solvemaze(maze,ans,N,0,0);
    delete [] ans;
    return 0;
}
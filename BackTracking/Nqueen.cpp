#include<bits/stdc++.h>
using namespace std;
//Prompt: You are given N, and for a given N x N chessboard, find a way to place N queens such that 
//no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, 
//or same column, or the same diagonal of any of the other queens. You have to print all such configurations.

//input: 4
//output: 0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
//        0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
int mat[11][11]={0};
bool isPossible(int row,int col,int N)
{
    for(int i=row-1;i>=0;i--)
    {
        if(mat[i][col]==1)
            return false;
    }
    
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(mat[i][j]==1)
            return false;
    }
    
    for(int i=row-1,j=col+1;i>=0 && j<N;i--,j++)
    {
        if(mat[i][j]==1)
            return false;
    }
    return true;
}
void NQueen(int row,int N)
{
    if(row==N)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                cout << mat[i][j] << " ";
        }
        cout << endl;
        return;
    }
    
    for(int j=0;j<N;j++)
    {
        if(isPossible(row,j,N))
        {
            mat[row][j]=1;
            NQueen(row+1,N);
            mat[row][j]=0;
        }
    }
}
int main(){
    // write your code here
    int N;
    cin >> N;
    NQueen(0,N);
    return 0;
}
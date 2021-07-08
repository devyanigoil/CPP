#include<iostream>
using namespace std;

int findzero(int board[9][9],int &posi,int &posj)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]==0)
            {
                posi=i;
                posj=j;
                return 1;
            }
        }
    }
    return 0;
}

bool check(int board[9][9],int &posi,int &posj,int k)
{
	for(int j=0;j<9;j++)
    {
        if(board[posi][j]==k)
            return false;
    }
    for(int j=0;j<9;j++)
    {
        if(board[j][posj]==k)
            return false;
    }
    int rowfactor = posi-(posi%3);
    int colfactor = posj-(posj%3);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i+rowfactor][j+colfactor]==k)
                return false;
        }
    }
    return true;
}

bool sudokusolver(int board[9][9])
{
    int posi,posj;
    int emp = findzero(board,posi,posj);
    if(emp==0)
    {
        return true;
    }
    for(int k=1;k<=9;k++)
    {
        bool res = check(board,posi,posj,k);
        if(res)
        {
            board[posi][posj]=k;
            bool solve = sudokusolver(board);
            if(solve)
                return true;
            board[posi][posj]=0;
        }
    }
    return false;
}

int main(){
    // write your code here
    int board[9][9];
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            cin>>board[i][j];
    bool ans = sudokusolver(board);
    if(ans==0)
        cout << "false";
    else
        cout << "true";
    return 0;
}
/*
1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
true
*/

/*
1 2 3 4 5 6 0 8 9
0 3 4 5 6 7 8 9 1
3 4 5 6 7 8 9 1 2
4 5 6 0 8 9 1 2 3
5 6 7 8 9 1 2 3 0
6 7 8 0 1 2 3 4 5
0 8 9 1 2 3 4 5 6
8 9 1 2 3 4 5 6 7
9 1 2 3 4 5 6 0 8
false
*/
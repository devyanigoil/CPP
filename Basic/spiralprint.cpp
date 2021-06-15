#include <iostream>
using namespace std;

void spiralPrint(int **input, int nRows, int nCols)
{
    //Write your code here
    int num=0,i,j;
    int rs=0,cs=0,ce=nCols-1,re=nRows-1;
    while(num<nRows*nCols)
    {
        for(i=rs,j=cs;j<=ce;j++)
        {
            cout << input[i][j] << " ";
            num++;
        }
        rs++;
        for(j=ce,i=rs;i<=re;i++)
        {
            cout << input[i][j] << " ";
            num++;
        }
        ce--;
        for(i=re,j=ce;j>=cs;j--)
        {
            cout << input[i][j] << " ";
            num++;
        }
        re--;
        for(j=cs,i=re;i>=rs;i--)
        {
            cout << input[i][j] << " ";
            num++;
        }
        cs++;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int row, col;
        cin >> row >> col;
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}
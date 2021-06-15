#include <iostream>
using namespace std;

void rotate(int *input, int d, int n)
{
    //Write your code here
    for(int i=0;i<d;i++)
    {
        int temp = input[0];
        int j;
        for(j=0;j<n-1;j++)
        {
            input[j] = input[j+1];
        }
        input[j] = temp;
    }
    for(int j=0;j<n;j++)
        cout << input[j] << " ";
}

int main()
 {
    int t,a[50],count=0,m1;
    cin >> t;
    if(t==0)
    {
        exit(0);
    }
    else
    {
        while(count<t)
        {
            cin >> m1;
            for (int i = 0; i < m1; i++)
            {
                /* code */
                cin >> a[i];
            }
            rotate(a,2,m1);
            count++;
        }
    }
 }
#include <iostream>
using namespace std;

void pushZeroesEnd(int *input, int size)
{
    //Write your code here
    for(int i=0;i<size-1;i++)
    {
    	for(int j=0;j<size-i-1;j++)
        {
            if(input[j]==0 && input[j+1]!=0)
            {
                int temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }
        }
    }
    for(int j=0;j<size;j++)
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
            pushZeroesEnd(a,m1);
            count++;
        }
    }
 }
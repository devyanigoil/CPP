#include <iostream>
using namespace std;

int arrayRotateCheck(int *input, int size)
{
    //Write your code here
    int k=0;
    for(int i=0;i<size-1;i++)
    {
        if(input[i]<=input[i+1])
            k++;
        else 
            break;
    }
    if(k==0 || k==size-1)
        return 0;
    return ++k;
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
            int ans = arrayRotateCheck(a,m1);
            cout << ans << endl;
            count++;
        }
    }
 }
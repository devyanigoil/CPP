#include <iostream>
using namespace std;

void intersection(int *input1, int *input2, int size1, int size2)
{
    //Write your code here
    int c[50],k=0,count=0;
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
        {
            if(input1[i]==input2[j])
            {
                for(int p=j;p<size2-1;p++)
                {
                    input2[p] = input2[p+1];
                }
                size2--;
                c[k++]=input1[i];
                break;
            }
        }
    }
    for(int i=0;i<k;i++)
        cout << c[i] << " ";
}
 int main()
 {
    int t,n,a[50],b[50],count=0,m1,m2;
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
            cin >> m2;
            for (int i = 0; i < m2; i++)
            {
                /* code */
                cin >> b[i];
            }
            intersection(a,b,m1,m2);
            count++;
        }
    }
 }
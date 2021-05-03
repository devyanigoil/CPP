#include <iostream>
using namespace std;

void merge(int *arr1, int size1, int *arr2, int size2, int *ans)
{
    //Write your code here   
    int i=0,j=0,k=0;
    while(i<size1 && j<size2)
    {
        if(arr1[i]<=arr2[j])
        {
            ans[k++] = arr1[i];
            i++;
        }
        else if(arr1[i]>arr2[j])
        {
            ans[k++] = arr2[j];
            j++;
        }
    }
    while(i<size1)
    {
        ans[k++] = arr1[i];
        i++;
    }
    while(j<size2)
    {
        ans[k++] = arr2[j];
        j++;
    }
    for(int p=0;p<k;p++)
        cout << ans[p] << " ";
}
int main()
 {
    int t,n,a[50],b[50],c[50],count=0,m1,m2;
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
            merge(a,m1,b,m2,c);
            count++;
        }
    }
 }
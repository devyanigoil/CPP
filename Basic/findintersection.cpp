#include <iostream>
#include <algorithm>
using namespace std;
void mergesort(int *a,int st,int end)
{
    if(st>end || st==end)
        return;
    int mid = (st+end)/2;
    mergesort(a,st,mid);
    mergesort(a,mid+1,end);
    int arr[5000];
    int i=st,j=mid+1,k=0;
    while(j<=end && i<=mid)
    {
        if(a[i]<a[j])
        {
            arr[k++]=a[i];
            i++;
        }
        else if(a[i]>a[j])
        {
            arr[k++]=a[j];
            j++;
        }
        else
        {
            arr[k++]=a[i];
            arr[k++]=a[j];
            i++;
            j++;
        }
    }
    while(i<=mid)
    {
        arr[k++]=a[i];
        i++;
    }
    while(j<=end)
    {
        arr[k++]=a[j];
        j++;
    }
    int p;
    for(int i=st,p=0;p<k;i++,p++)
        *(a+i)=arr[p];
}
void intersection(int *arr1, int *arr2, int n, int m) 
{
    //Write your code here
    mergesort(arr1,0,n-1);
    mergesort(arr2,0,m-1);
    for (int i = 0; i < n; ++i)
    {
        cout << arr1[i] << " "; 
    }
    cout << endl;
    for (int i = 0; i < m; ++i)
    {
        cout << arr2[i] << " "; 
    }
    cout << endl;
    int i=0,j=0;
    while(j<m && i<n)
    {
        if(arr1[i]<arr2[j])
            i++;
        else if(arr1[i]>arr2[j])
            j++;
        else if(arr1[i]==arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int size1, size2;

        cin >> size1;
        int *input1 = new int[size1];

        for (int i = 0; i < size1; i++)
        {
            cin >> input1[i];
        }

        cin >> size2;
        int *input2 = new int[size2];

        for (int i = 0; i < size2; i++)
        {
            cin >> input2[i];
        }

        intersection(input1, input2, size1, size2);
        
        delete[] input1;
        delete[] input2;
        
        cout << endl;
    }

    return 0;
}
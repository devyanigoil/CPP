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
int countnumi(int arr[],int pos, int size)
{
    int num=1;
    for (int i = pos+1; i < size; ++i)
    {
        if (arr[i]==arr[pos])
        {
            num++;
        }
        else break;
    }
    return num;
}
int countnumj(int arr[],int pos)
{
    int num=1;
    for (int j = pos-1; j>=0; j--)
    {
        if (arr[j]==arr[pos])
        {
            num++;
        }
        else break;
    }
    return num;
}
int pairSum(int *arr, int n, int num)
{
	//Write your code here
    mergesort(arr,0,n-1);
    int i=0,j=n-1,count=0;
    int sum = arr[i]+arr[j];
    while(i<j)
    {
        if(sum==num)
        {
            int m = countnumi(arr,i,n);
            cout << "Value of m is: " << m << endl;
            int r = countnumj(arr,j);
            cout << "Value of r is: " << r << endl;
            if (m==1 && r==1)
            {
                count++;
                i++;
                j--;
            }
            else if (m==r)
            {
                cout << "Hi " << endl;
                return (n * (n-1))/2;
            }
            else
            {
                count+=m*r;
                i=i+m;
                j=j-r;
            }
        } 
        else if(sum>num)
            j--;
        else if(sum<num)
            i++;
    }
     return count; 
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        int x;

        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cin >> x;

        cout << pairSum(input, size, x) << endl;

        delete[] input;
    }
    
    return 0;
}
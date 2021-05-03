#include <iostream>
using namespace std;

void sort012(int *arr, int n)
{
    //Write your code here
    int a[50],b[50],p=0;
    for(p=0;p<n/2;p++)
        a[p] = arr[p];
    for(int j=0;p<n;p++,j++)
        b[j] = arr[p];
    int i=0,j=0,k=0;
    int size1 = n/2,size2=n-n/2+1;;
    while(i<size1 && j<size2)
    {
        if(a[i]<=b[j])
        {
            arr[k++] = a[i];
            i++;
        }
        else if(a[i]>b[j])
        {
            arr[k++] = b[j];
            j++;
        }
    }
    while(i<size1)
    {
        arr[k++] = a[i];
        i++;
    }
    while(j<size2)
    {
        arr[k++] = b[j];
        j++;
    }
}
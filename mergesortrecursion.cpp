#include <iostream>
using namespace std;

void mergeS(int input[],int st,int end)
{
    if(st>end || st==end)
    	return;
    int mid = (st+end)/2;
    mergeS(input,st,mid);
    mergeS(input,mid+1,end);
  	int i=st,j=mid+1,k=0;
    int a[5000]={0};
    while(i<=mid && j<=end)
    {
        if(input[i]<input[j])
        {
            a[k++]=input[i];
            i++;
        }
        else if(input[i]>input[j])
        {
            a[k++]=input[j];
            j++;
        }
        else
        {
            a[k++]=input[i];
            a[k++]=input[j];
            i++;
            j++;
        }
    }
    while(i<=mid)
    {
    	a[k++] = input[i];
    	i++;
    }
    while(j<=end)
    {
    	a[k++] = input[j];
    	j++;
    }
    for(int p=st,k=0;p<=end;p++,k++)
    {
        input[p]=a[k];
    }
    return;
}

void mergeSort(int input[], int size){
	// Write your code here
    return mergeS(input,0,size-1);
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}

#include <iostream>
using namespace std;

int partition(int arr[],int st,int end)
{
    int pivot = arr[st];
    int i=st+1;
    int j = end+1;

    while(i<j)
    {
        for(;i<=end;i++)
        {
            if(arr[i]>pivot)
            {
                break;
            } 
        }
        j--;
        for(;j>=st && i<=end;j--)
        {
            if(arr[j]<pivot)
            {
               break;
            }
        }
        if(i<j)
        {
            int temp = arr[j];
            arr[j]=arr[i];
            arr[i] = temp;
        }
        else break;
    }
    if(i>j)
    {
        if(j<st)
            j++;
        int temo = arr[j];
        arr[j] = arr[st];
        arr[st] = temo;
        return j;
    }

    else if(i==j)
    {
        int temo = arr[j];
        arr[j] = arr[st];
        arr[st] = temo;
        return j;
    }
}

void quickS(int a[],int st,int end)
{
    if (st>end || st==end)
    {
        return;
    }
    int sp = partition(a,st,end);
    quickS(a,st,sp-1);
    quickS(a,sp+1,end);
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    return quickS(input,0,size-1); 
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}

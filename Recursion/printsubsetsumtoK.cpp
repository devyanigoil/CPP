#include <iostream>
using namespace std;
void printsub(int a[],int n,int out[],int m,int k)
{
    if(n==0)
    {
        if(k==0)
        {
            for(int i=0;i<m;i++)
                cout << out[i] << " ";
            cout << endl;
            return;
        }
        else 
            return;
    }
    printsub(a+1,n-1,out,m,k);
    int o1[50];
    int i=0;
    for(;i<m;i++)
        o1[i]=out[i];
    o1[i]=a[0];
    printsub(a+1,n-1,o1,m+1,k-a[0]);
    
}
void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int output[50];
    return printsub(input,size,output,0,k);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
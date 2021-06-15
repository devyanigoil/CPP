#include <iostream>
using namespace std;

int subset(int input[], int n, int output[][20]) {
    // Write your code here
    if(n==0)
    {
        output[0][0]=0;
        output[0][1]=0;
        return 1;
    }
    int subnum = subset(input+1,n-1,output);
    for(int i=0;i<subnum;i++)
    {
        output[i+subnum][0]=output[i][0]+1;
        for(int j=1;j<=output[i][0];j++)
        {
            output[i+subnum][j]=output[i][j];
        }  
    }
    for(int i=subnum;i<2*subnum;i++)
    {
        int j=output[i][0];
        if (j==1)
        {
            output[i][1] = input[0];
        }
        else
        {
            for(;j>1;j--)
                output[i][j]=output[i][j-1];
            output[i][1] = input[0];
        }
    }
    return 2*subnum;
}

int main() {
  int input[20],length, output[35][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
    for( int j = 1; j <= output[i][0]; j++) { 
        cout << output[i][j] << " ";
    }
    cout << endl;
  }
}



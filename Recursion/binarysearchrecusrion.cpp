#include <iostream>
using namespace std;

int bsearch(int a[],int l,int r,int ele)
{
    if(l<=r)
    {   
        int mid = l+(r-l)/2;
        if(ele==a[mid])
            return mid;
        else if(ele<a[mid])
            return bsearch(a,l,mid-1,ele);
        else if(ele>a[mid])
            return bsearch(a,mid+1,r,ele);
    }
    else
        return -1;
}
int binarySearch(int input[], int size, int element) {
    // Write your code here
    return bsearch(input,0,size-1,element);
    
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}



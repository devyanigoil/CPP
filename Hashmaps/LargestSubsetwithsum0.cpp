#include <iostream>
#include<unordered_map>
using namespace std;

//Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
//input: 10 
// 95 -97 -387 -435 -5 -70 897 127 23 284
//output: 5
// (-387 -435 -5 -70 897) 
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int,int> ourmap;
    int sum=0,maxlength=0,length;
    
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(ourmap.count(sum)>0)
        {
            length = i-ourmap.at(sum);
            if(length>maxlength)
                maxlength = length; 
        }
        if(sum==0)
        {
            length = i+1;
            if(length>maxlength)
                maxlength = length; 
        }
        ourmap[sum]=i;
    }
    return maxlength;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}
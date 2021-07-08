//You are given with an array of integers and an integer K. 
//You have to find and print the count of all such pairs which have difference K.
//Note: Take absolute difference between the elements of the array.
//input:4 
//5 1 2 4
//3
//output: 2

#include <iostream>
#include<unordered_map>
using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    int count=0;
    unordered_map<int,int> ourmap;
    for(int i=0;i<n;i++)
        ourmap[arr[i]]++;
    if(k==0)
    {
        for(int i=0;i<n;i++)
    	{
        	if(ourmap.count(arr[i])>0)
        	{
            	count+=(ourmap.at(arr[i])*(ourmap.at(arr[i])-1))/2;
        	}
        	ourmap.at(arr[i])=0;
            if(ourmap.size()==0)
            	break;
    	}
    	return count;
    }
    
    for(int i=0;i<n;i++)
    {
        int num = arr[i]+k;
        if(ourmap.count(num)>0)
        {
            count+=ourmap.at(arr[i])*ourmap.at(num);
        }
        num = arr[i]-k;
        if(ourmap.count(num)>0)
        {
            count+=ourmap.at(arr[i])*ourmap.at(num);
        }
        ourmap.at(arr[i])=0;
        if(ourmap.size()==0)
            break;
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}
#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;

//You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, 
//print the resulting median.
//input 6
//6 2 1 3 7 5
//output: 6 4 2 2 3 4


void findMedian(int *arr, int n) {
    // Write your code here
    if(n==0)
        return;
    priority_queue<int> pqmax;
    priority_queue<int,vector<int>,greater<int>> pqmin;

    pqmax.push(arr[0]);
    cout << arr[0] << " ";
    
    for(int i=1;i<n;i++)
    {
        if(arr[i]>pqmax.top())
        {
            pqmin.push(arr[i]);
        }
        else
        {
            pqmax.push(arr[i]);
        }
        int s2 = (pqmin.size())-(pqmax.size());
        int s1 = (pqmax.size())-(pqmin.size());
        
        if(s1>1)
        {
            int temp = pqmax.top();
            pqmax.pop();
            pqmin.push(temp);
        }
        else if(s2>1)
        {
            int temp = pqmin.top();
            pqmin.pop();
            pqmax.push(temp);
        }
        
        if(pqmax.size()>pqmin.size())
        {
            cout << pqmax.top() << " ";
        }
        else if(pqmin.size()>pqmax.size())
            cout << pqmin.top() << " ";
        else
        {
            int maxnum = pqmax.top();
            int minnum = pqmin.top();
            cout << (maxnum+minnum)/2 << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}

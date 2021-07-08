#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int kthLargest(int* arr, int n, int k) {
    // Write your code here
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++)
    {
        int top = pq.top();
        if(arr[i]>top)
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    int res;
    res = pq.top();
    //pq.pop();
    return res;
}


int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << kthLargest(arr, n, k);

    delete[] arr;
}
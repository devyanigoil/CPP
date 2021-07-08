#include <iostream>
#include <vector>
#include<queue>
using namespace std;

//A queue is maintained for buying the tickets and every person is attached with a priority 
//(an integer, 1 being the lowest priority).
//The tickets are sold in the following manner -
//1. The first person (pi) in the queue requests for the ticket.
//2. If there is another person present in the queue who has higher priority than pi, 
//then ask pi to move at end of the queue without giving him the ticket.
//3. Otherwise, give him the ticket (and don't make him stand in queue again).

//input: 3
//3 9 4
//2
//output: 2

int buyTicket(int *arr, int n, int k) {
    // Write your code here
    queue<int> q;
    priority_queue<int> pq;
    int time=0;
    for(int i=0;i<n;i++)
    {
        q.push(i);
        pq.push(arr[i]);
    }
    while(!(q.front()==k && arr[q.front()]==pq.top()))
    {
        if(pq.top()==arr[q.front()])
        {
            time++;
            q.pop();
            pq.pop();
        }
        else
        {
            int num = q.front();
            q.pop();
            q.push(num);
        }
    }
    time++;
    return time;
}


int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}
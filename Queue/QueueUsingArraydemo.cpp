#include <iostream>
using namespace std;
#include "QueueUsingDynamicArray.h"

int main()
{
	QueueUsingArray<int> q1(5);

	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(50);
	q1.enqueue(60);
	q1.enqueue(70);

	cout << q1.front() << endl;
	cout << q1.dequeue() << endl;
	cout << q1.dequeue() << endl;
	cout << q1.dequeue() << endl;

	cout << q1.getSize() << endl;
	cout << q1.isEmpty() << endl;
}
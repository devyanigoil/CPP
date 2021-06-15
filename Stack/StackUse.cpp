#include <iostream>
using namespace std;
#include "StackUsingArray.cpp"

int main()
{
	StackUsingArray s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	s.top();

	int ele = s.pop();
	cout << ele << endl;
	ele = s.pop();
	cout << ele << endl;

	ele = s.size();
	cout << ele << endl;

	bool ans = s.isEmpty();
	cout << ans << endl;
}
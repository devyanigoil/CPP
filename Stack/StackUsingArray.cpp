#include <climits>
class StackUsingArray{
	int *data;
	int capacity;
	int tos;

public:
	StackUsingArray(){
		data = new int[4];
		capacity = 4;
		tos = 0; 
	}

	int size()
	{
		return tos;
	}

	bool isEmpty()
	{
		return tos==0;
	}

	void push(int ele)
	{
		if(tos==capacity)
		{
			int *newdata = new int[2*capacity];
			for (int i = 0; i < capacity; ++i)
			{
				newdata[i] = data[i];
			}
			capacity*=2;
			delete [] data;
			data = newdata;
			//cout << "Stack is Full"<< endl;
			//return;
		}
		data[tos]=ele;
		tos++;
	}
	
	int pop()
	{
		if(isEmpty())
		{
			
			cout << "Stack is empty" << endl;
			return INT_MIN;
		}
		tos--;
		return data[tos];
	}

	int top()
	{
		if(isEmpty())
		{
			cout << "Stack is empty" << endl;
			return INT_MIN;
		}
		return data[tos-1];
	}
};
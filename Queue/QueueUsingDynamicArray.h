template <typename T>
class QueueUsingArray
{
	T *data;
	int nextIndex,FirstIndex;
	int size;
	int capacity;
	
	public: 
	QueueUsingArray(int s)
	{
		data = new T[s];
		nextIndex=0;
		FirstIndex=-1;
		size=0;
		capacity = s;
	}

	int getSize()
	{
		return size;
	}
	bool isEmpty()
	{
		return size==0;
	}

	void enqueue(T ele)
	{
		if(size==capacity)
		{
			T* newData = new T[2*capacity];
			int j=0;
			for (int i = FirstIndex; i < capacity; ++i)
				newData[j++]=data[i];
			for(int i=0; i<FirstIndex; i++)
				newData[j++]=data[i];
			delete [] data;
			data = newData;
			FirstIndex=0;
			nextIndex=capacity;
			capacity *= 2;
		}
		data[nextIndex]=ele;
		nextIndex = (nextIndex+1)%capacity;
		if(FirstIndex==-1)
			FirstIndex=0;
		size++;
	}

	T front()
	{
		if(FirstIndex==-1)
		{
			cout << "Queue is empty!" << endl;
			return 0; 
		}
		return data[FirstIndex];
	}

	T dequeue()
	{
		if(FirstIndex==-1)
		{
			cout << "Queue is empty!" << endl;
			return 0; 
		}
		T elem = data[FirstIndex];
		FirstIndex = (FirstIndex+1)%capacity;
		size--;
		if(size==0)
		{
			FirstIndex=-1;
			nextIndex=0;
		}
		return elem;
	}
};
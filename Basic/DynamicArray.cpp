class DynamicArray{
	int *data;
	int nextIndex,capacity;

	public :

	DynamicArray()
	{
		data = new int[5];
		nextIndex = 0;
		capacity = 5;
	}
	void add(int ele)
	{
		if (nextIndex==capacity)
		{
			int *newArray = new int[2*capacity];
			for (int i = 0; i < capacity; ++i)
				newArray[i]=data[i];
			delete [] data;
			data = newArray;
			capacity*=2;
		}
		data[nextIndex]=ele;
		nextIndex++;
	}
	int get(int i)
	{
		if (i<nextIndex)
		{
			return data[i];
		}
		else
			return -1;
	}
	void add(int i,int ele)
	{
		if (i<nextIndex)
		{
			data[i]=ele;
		}
		else if(i==nextIndex)
			add(ele);
		else
			return;
	}
	void print()
	{
		for (int i = 0; i < nextIndex; ++i)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
};
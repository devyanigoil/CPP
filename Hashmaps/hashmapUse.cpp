#include<iostream>
#include "ourmap.h"
using namespace std;

int main()
{
	ourmap<int> map;
	for(int i=0;i<10;i++)
	{
		char c = '0' + i;
		string key = "abc";
		key = key+c;
		int value = i+c;
		map.insert(key,value);
		cout << map.getLoadFactor() << endl;
	}
	cout << map.size() << endl;
	int temp = map.remove("abc2");
	temp = map.remove("abc7");
	cout << map.size() << endl;
	
	for(int i=0;i<10;i++)
	{
		char c = '0' + i;
		string key = "abc";
		key = key+c;
		cout << "key: " << map.getValue(key) << endl;
	}

	cout << map.size() << endl;
}
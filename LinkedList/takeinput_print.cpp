#include<iostream>
using namespace std;
#include "Node.cpp"
Node* takeinput()
{
	int data;
	cin >> data;
	Node* head=NULL;
	while(data!=-1)
	{
		Node* n = new Node(data);//Allocate dynamically so that it is not deallocated automatically
		if(head==NULL)
			head = n;
		else
		{
			Node* temp = head;
			while(temp->next!=NULL)
				temp = temp->next;
			temp->next = n;
		}
		cin >> data;
	}
	return head;
}
void print(Node* head)
{
	Node* temp = head;
	while(temp!=NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main()
{
	Node* header = takeinput();
	print(header);
}

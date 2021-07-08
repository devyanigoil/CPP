#include<iostream>
#include "BST.h"
using namespace std;

int main()
{
	BST* tree = new BST();

	tree->insert(10);
	tree->insert(20);
	tree->insert(5);
	tree->insert(3);
	tree->insert(4);
	tree->insert(15);
	tree->insert(77);

	tree->printTree();
	cout << tree->search(15) << endl;
	//tree->deleteData(7);
	//tree->printTree();
	tree->deleteData(10);
	tree->printTree();
	delete tree;
}
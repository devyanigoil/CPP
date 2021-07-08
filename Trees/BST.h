#include<iostream>
#include "BinaryTree.cpp"
using namespace std;
class BST
{
	BinaryTree<int>* root;

public:

	BST()
	{
		root=NULL;
	}

	~BST()
	{
		delete root;
	}

private:

	bool searchPri(int data,BinaryTree<int>* node)
    {
        if(node==NULL)
            return false;
        if(node->data==data)
            return true;
        if(data<node->data)
            return searchPri(data,node->left);
        else if(data>node->data)
            return searchPri(data,node->right);
    }

	BinaryTree<int>* insertPri(int data,BinaryTree<int>* node)
	{
		if(node==NULL)
		{
			BinaryTree<int>* newnode = new BinaryTree<int>(data);
			return newnode;
		}
		// the <= indicates that duplicate values are allowed in the left subtree
		if(data<=node->data)
			node->left = insertPri(data,node->left);
		if(data>node->data)
			node->right = insertPri(data,node->right);
		return node;
	}

	BinaryTree<int>* minimum (BinaryTree<int>* node)
	{
		if(node==NULL)
			return NULL;
		if(node->left==NULL && node->right==NULL)
			return node;
		BinaryTree<int>* min = minimum(node->left);
		if(min->data>node->data)
			min = node;
		return min;
	}

	BinaryTree<int>* deleteNode(int data,BinaryTree<int>* node)
	{
		if(node==NULL)
			return NULL;
		if(data<node->data)
			node->left = deleteNode(data,node->left);
		else if(data>node->data)
			node->right = deleteNode(data,node->right);
		else
		{
			if(node->left==NULL && node->right==NULL)
			{
				delete node;
				return NULL;
			}
			else if(node->left==NULL && node->right!=NULL)
			{
				BinaryTree<int>* temp = node->right;
				node->right=NULL;
				delete node;
				return temp;
			}
			else if(node->left!=NULL && node->right==NULL)
			{
				BinaryTree<int>* temp = node->left;
				node->left=NULL;
				delete node;
				return temp;
			}
			else
			{
				BinaryTree<int>* min = minimum(node->right);
				node->data = min->data;
				node->right = deleteNode(min->data,node->right);
				return node;
			}
		}
	}
	void printTreePri(BinaryTree<int>* root)
	{
		if(root==NULL)
			return;
		cout << root->data << ":";
		if(root->left!=NULL)
			cout << "L:" << root->left->data << ", ";
		if(root->right!=NULL)
			cout << "R:" << root->right->data << " ";
		cout << endl;
		printTreePri(root->left);
		printTreePri(root->right);
	}

public:

	bool search(int data) 
	{
        return searchPri(data,root);
    }

	void insert(int data)
	{
		root = insertPri(data,root);
		cout << "Root data: " << root->data << endl;
	}

	void deleteData(int data)
	{
		root = deleteNode(data,root);
		cout << "Root Data: " << root->data << endl;
	}
	void printTree()
	{
		printTreePri(root);
	}
};
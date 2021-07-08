#include "BinaryTree.cpp"
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

	bool hasDataPri(int data,BinaryTree<int>* node)
	{
		if(node==NULL)
			return false;
		if(node->data==data)
			return true;
		else if(data<root->data)
			return hasDataPri(data,node->left);
		else
			return hasDataPri(data,node->right);
	}

	BinaryTree<int>* insertPri(int data,BinaryTree<int>* node)
	{
		if(node==NULL)
		{
			BinaryTree<int>* newnode = new BinaryTree<int>(data);
			return newnode;
		}
		if(data<node->data)
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
		if(min->data>root->data)
			min = root;
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
				return NULL;
			else if(node->left==NULL && node->right!=NULL)
				return node->right;
			else if(node->left!=NULL && node->right==NULL)
				return node->left;
			else
			{
				BinaryTree<int>* min = minimum(node->right);
				node->data = min->data;
				return deleteNode(min,node->right);
			}
		}
	}

public:

	bool hasData(int data)
	{
		return hasDataPri(data,root);
	}

	void insert(int data)
	{
		BinaryTree<int>* node = insertPri(data,root);
		cout << "Root data: " << node->data << endl;
	}

	void deleteData(int data)
	{
		BinaryTree<int>* node = deleteNode(data,root);
		cout << "Root Data: " << node->data << endl;
	}
}
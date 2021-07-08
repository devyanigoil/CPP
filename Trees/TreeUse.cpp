#include <iostream>
#include "TreeNode.h"
#include <queue>
#include <algorithm>
using namespace std;

int getHeight(TreeNode<int>* root) 
{
    // Write your code here
    if(root==NULL)
        return 0;
    int height = 0;
    for(int i=0;i<root->children.size();i++)
    {
     	height = std::max(height,getHeight(root->children[i]));   
    }
    return height +1;
}

void PrintAtLevelK(TreeNode<int>* root,int k)
{
	if(root==NULL)
		return;
	if(k==0)
	{
		cout << root->data << endl;
		return;
	}
	for(i=0;i<root->children.size();i++)
		PrintAtLevelK(root->children[i],k-1);
}
void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        TreeNode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        cout << front->data << ":";
        int i;
        if(front->children.size()==0)
        {
            cout << endl;
            continue;
        }    
        for(i=0;i<front->children.size()-1;i++)
        {
            cout << front->children[i]->data << ",";
            pendingnodes.push(front->children[i]);
        }
        cout << front->children[i]->data;
        pendingnodes.push(front->children[i]);
        cout << endl;
    } 
}

TreeNode<int>* takeInputLevelwise()
{
	int rootData;
	cout << "Enter root data: " << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0)
	{
		TreeNode<int>* front = pendingnodes.front();
		pendingnodes.pop();

		int num;
		cout << "Enter the number of children of " << front->data << endl;
		cin >> num;

		for (int i = 0; i < num; ++i)
		{
			int ele;
			cout << "Enter data of " << i << "th child of " << front->data << endl;
			cin >> ele;
			TreeNode<int>* child = new TreeNode<int>(ele);
			front->children.push_back(child);
			pendingnodes.push(child);
		}
	}
	return root;
}
TreeNode<int>* takeInput()
{
	int rootData;
	cout << "Enter Data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	int n;
	cout << "Enter the no. of children" << endl;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int>* root)
{
	//edge case not a base case
	if(root==NULL)
		return;

	cout << root->data <<": ";
	for(int i=0;i<root->children.size();i++)
	{
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size(); ++i)
	{
		printTree(root->children[i]);
	}
}

int numnodes(TreeNode<int>* root)
{
	if(root==NULL)
		return 0;
	int ans=1;
	for(int i=0;i<root->children.size();i++)
		ans += numnodes(root->children[i]);
	return ans;
}

void printPostOrder(TreeNode<int>* root) {
    if(root==NULL)
        return;
    for(int i=0;i<root->children.size();i++)
    {
        printPostOrder(root->children[i]);
    }
   cout << root->data << " ";
}

void printpreorder(TreeNode<int>* root)
{
	if(root==NULL)
        return;
    cout << root->data << " ";
    for(int i=0;i<root->children.size();i++)
    {
        printpreorder(root->children[i]);
    }
}

//10 3 20 30 40 2 400 50 0 0 0 0 
int main()
{
	/*
	TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* n1 = new TreeNode<int>(2);
	TreeNode<int>* n2 = new TreeNode<int>(3);

	root->children.push_back(n1);
	root->children.push_back(n2);
	*/
	TreeNode<int>* root = takeInputLevelwise();
	printTree(root);
	int ans = numnodes(root);
	cout << "No of node: " << ans << endl;
}

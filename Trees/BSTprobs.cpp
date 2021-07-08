#include<iostream>
#include "BinaryTree.cpp"
#include<queue>
#include<climits>
using namespace std;

BinaryTree<int>* takeinputlevelwise()
{
	int rootdata;
	cout << "Enter data: " << endl;
	cin >> rootdata;
	if(rootdata==-1)
		return NULL;
	BinaryTree<int>* root = new BinaryTree<int>(rootdata);
	queue<BinaryTree<int>*> pendingnodes;

	pendingnodes.push(root);

	while(pendingnodes.size()!=0)
	{
		BinaryTree<int>* front = pendingnodes.front();
		pendingnodes.pop();
		int lchild;
		cout << "Enter left child of " << front->data << endl;
		cin >> lchild;
		if(lchild!=-1)
		{
			BinaryTree<int>* lroot = new BinaryTree<int>(lchild);
			front->left = lroot;
			pendingnodes.push(lroot);
		}
		int rchild;
		cout << "Enter right child of " << front->data << endl;
		cin >> rchild;
		if(rchild!=-1)
		{
			BinaryTree<int>* rroot = new BinaryTree<int>(rchild);
			front->right = rroot;
			pendingnodes.push(rroot);
		}
	}
	return root;
}

void printTree(BinaryTree<int>* root)
{
	if(root==NULL)
		return;
	cout << root->data << ":";
	if(root->left!=NULL)
		cout << "L" << root->left->data << " ";
	if(root->right!=NULL)
		cout << "R" << root->right->data << " ";
	cout << endl;
	printTree(root->left);
	printTree(root->right);
}

//1 10 5 6 11 -1 2 -1 -1 9 -1 -1 -1 -1 -1
//Height of the largest BST subtree would be 2 here
class Pair{
    public:
    int min;
    int max;
    bool isBst;
    int height;
};
Pair helper(BinaryTree<int> *root)
{
	if(root==NULL)
    {
        Pair temp;
        temp.min = INT_MAX;
        temp.max = INT_MIN;
        temp.isBst = true;
        temp.height = 0;
        return temp;
    }
    
    Pair leftAns = helper(root->left);
    Pair rightAns = helper(root->right);
    
    Pair ans;
    if(leftAns.isBst && rightAns.isBst)
    {
        if(leftAns.max<root->data && rightAns.min>root->data)
        {
            ans.min = min(root->data,leftAns.min);
            ans.max = max(root->data,rightAns.max);
            ans.isBst = true;
            ans.height = 1+max(leftAns.height,rightAns.height);
        }
        else
        {
            ans.min = min(leftAns.min,min(root->data,rightAns.min));
            ans.max = max(leftAns.max,max(root->data,rightAns.max));
            ans.isBst = false;
            ans.height = max(leftAns.height,rightAns.height);
        }
    }
    else
    {
        ans.min = min(leftAns.min,min(root->data,rightAns.min));
        ans.max = max(leftAns.max,max(root->data,rightAns.max));
        ans.isBst = false;
        ans.height = max(leftAns.height,rightAns.height);
    }
    return ans;
}

int largestBSTSubtree(BinaryTree<int> *root) {
    return (helper(root)).height;
}

int replace(BinaryTree<int> *root,int sum)
{
    if(root==NULL)
        return 0;
	int rsum = replace(root->right,sum);
    rsum += root->data;
    root->data = rsum+sum;
    if(root->left)
    {
    	int lsum = replace(root->left,root->data);
		return lsum+rsum;        
    }
	return rsum;
}
void replaceWithLargerNodesSum(BinaryTree<int> *root) {
    int sum = replace(root,0);
}

//8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
int main()
{
	BinaryTree<int>* root = takeinputlevelwise();
	cout << "Height of the largest BST: " << largestBSTSubtree(root) << endl;
	replaceWithLargerNodesSum(root);
	printTree(root);
	delete root;
}
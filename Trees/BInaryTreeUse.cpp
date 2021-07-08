#include<iostream>
#include "BinaryTree.cpp"
#include "Node.cpp"
#include<queue>
#include<stack>
using namespace std;

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

void printLevelWise(BinaryTree<int> *root) {
    if(root==NULL)
        return;
    queue<BinaryTree<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        BinaryTree<int>* front = pendingnodes.front();
        cout << front->data << ":";
        pendingnodes.pop();
        
        if(front->left!=NULL)
    	{
        	cout << "L:" << front->left->data << ","; 
        	pendingnodes.push(front->left);
    	}
        else
            cout << "L:-1,";
    	if(front->right!=NULL)
    	{
        	cout << "R:" << front->right->data; 
        	pendingnodes.push(front->right);
    	}
        else
            cout << "R:-1";
        cout << endl;
    }
    
}

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

int numNodes(BinaryTree<int>* root)
{
	if(root==NULL)
		return 0;
	return 1+numNodes(root->left) + numNodes(root->right);
}

int height(BinaryTree<int>* root) {
    // Write our code here
    if(root!=NULL)
    {
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh>rh)
            return lh+1;
        else 
            return rh+1;
    }
}

void mirrorBinaryTree(BinaryTree<int>* root) {
    // Write your code here
    if(root)
    {
        BinaryTree<int>* temp = root->left;
    	root->left = root->right;
    	root->right = temp;
    
    	mirrorBinaryTree(root->left);
    	mirrorBinaryTree(root->right);
    }
}

bool isNodePresent(BinaryTree<int> *root, int x) {
    // Write your code here
    if(root==NULL)
        return false;
    if(root->data==x)
        return true;
    return isNodePresent(root->left,x) || isNodePresent(root->right,x);
}

//printing like this:
/*
10
20 30
40 50 60
for tree like this:
		10
		/\
	  20  30
	  /\   \
	40 50  60
*/
void printLevelWiseNewLine(BinaryTree<int> *root) {
    if(root==NULL)
        return;
    queue<BinaryTree<int>*> pendingnode;
    pendingnode.push(root);
    pendingnode.push(NULL);
    while(pendingnode.size()!=0)
    {
        BinaryTree<int>* front = pendingnode.front();
        pendingnode.pop();
        if(front!=NULL)
        	cout << front->data << " ";
        else if(front==NULL)
        {
            if(pendingnode.size()!=0)
            {
                cout << endl;
            	pendingnode.push(NULL);
            	continue;
            }
            else
                break;
            
        }
        if(front->left)
        	pendingnode.push(front->left);
        if(front->right)
        	pendingnode.push(front->right);
    }
}

BinaryTree<int>* removeLeafNodes(BinaryTree<int> *root) {
    if(root==NULL)
        return NULL;
    if(root->left)
    {
        if(root->left->left==NULL && root->left->right==NULL)
        root->left=NULL;
    }
    if(root->right)
    {
        if(root->right->left==NULL && root->right->right==NULL)
        root->right=NULL;
    }
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    return root;
}

void printNodesWithoutSibling(BinaryTree<int> *root) {
    // Write your code here
    if(root==NULL)
        return;
    if(root->left!=NULL && root->right!=NULL)
    {
        printNodesWithoutSibling(root->left);
        printNodesWithoutSibling(root->right);
    }
    else if(root->right==NULL && root->left!=NULL)
    {
        cout << root->left->data << " ";
        printNodesWithoutSibling(root->left);
    }
    else if(root->left==NULL && root->right!=NULL)
    {
        cout << root->right->data << " ";
        printNodesWithoutSibling(root->right);
    }
}


// 1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1
pair<int,int> heightDiameter(BinaryTree<int>* root)
{
	if(root==NULL)
	{
		pair<int,int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}

	pair<int,int> leftAns = heightDiameter(root->left);
	pair<int,int> rightAns = heightDiameter(root->right);

	int lh = leftAns.first;
	int ld = leftAns.second;
	int rh = rightAns.first;
	int rd = rightAns.second;

	int height = 1 + max(lh,rh);
	int diameter = max(lh+rh,max(ld,rd)); 

	pair<int,int> p;
	p.first = height;
	p.second = diameter;
	return p;
}

pair<int,bool> helper(BinaryTree<int> *root)
{
    if(root==NULL)
    {
        pair<int,bool> p;
        p.first = 0;
        p.second = true;
        return p;
    }
    pair<int,bool> leftans=helper(root->left);
    pair<int,bool> rightans=helper(root->right);
    
    pair<int,bool> ans;
	ans.first = 1 + max(leftans.first,rightans.first);
    ans.second = leftans.second && rightans.second;
    if(ans.second)
    {
        if(abs(leftans.first-rightans.first)>1)
            ans.second=false;
    }
    return ans;
}

bool isBalanced(BinaryTree<int> *root) {
	// Write your code here
    pair<int,bool> p = helper(root);
    return p.second;
}

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTree<int> *root) {
    // Write your code here
    vector<Node<int>*> LLstart;
    if(root==NULL)
        return LLstart;
    queue<BinaryTree<int>*> pendingnodes;
    pendingnodes.push(root);
    pendingnodes.push(NULL);
    Node<int>* head=NULL;
    Node<int>* tail = NULL;
    while(pendingnodes.size()!=0)
    {
        BinaryTree<int>* front = pendingnodes.front();
        pendingnodes.pop();
        if(front==NULL)
        {
            LLstart.push_back(head);
            head=NULL;
            tail=NULL;
            if(pendingnodes.size()==0)
                break;
            else
            {
                pendingnodes.push(NULL);
                continue;
            }
        }
        else
        {
    		Node<int>* frontNode = new Node<int>(front->data);
            if(head==NULL && tail==NULL)
            {
                head=frontNode;
                tail=frontNode;
            }
            else
            {
                tail->next=frontNode;
                tail=tail->next;
            }
        }
        if(front->left)
            pendingnodes.push(front->left);
        if(front->right)
            pendingnodes.push(front->right);
    }
    return LLstart;
}

//Odd rows from L->R
//Even rows from R->L
void zigZagOrder(BinaryTree<int> *root) {
	stack<BinaryTree<int>*> s1;
	stack<BinaryTree<int>*> s2;    
    s1.push(root);
    while(s1.size()!=0 || s2.size()!=0)
    {
        while(s1.size()!=0)
    	{
        	BinaryTree<int>* top = s1.top();
        	s1.pop();
            cout << top->data << " ";
        
        	if(top->left)
    			s2.push(top->left);
        	if(top->right)
            	s2.push(top->right);
    	} 
        cout << endl;
        while(s2.size()!=0)
        {
            BinaryTree<int>* top = s2.top();
        	s2.pop();
       		cout << top->data << " ";
            
            if(top->right)
            	s1.push(top->right);
            if(top->left)
    			s1.push(top->left);
        }
        cout << endl;
    }
}

vector<int>* RootToNodePath(BinaryTree<int>* root,int data)
{
	if(root==NULL)
		return NULL;
	if(root->data==data)
	{
		vector<int>* v = new vector<int>();
		v->push_back(root->data);
		return v;
	}
	vector<int>* left = RootToNodePath(root->left,data);
	if(left!=NULL)
	{
		left->push_back(root->data);
		return left;
	}
	vector<int>* right = RootToNodePath(root->right,data);
	if(right!=NULL)
	{
		right->push_back(root->data);
		return right;
	}
	else
		return NULL;
}

//Least common Ancestor
// eg: 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
//the LCA of 2 and 6 would be 5, 2 and 10 would be 10
int getLCA(BinaryTree <int>* root , int a, int b) {
    // Write your code here
    if(root==NULL)
        return -1;
    if(root->data==a || root->data==b)
        return root->data;
    int leftlca = getLCA(root->left,a,b);
    int rightlca = getLCA(root->right,a,b);
    
    if(leftlca!=-1 && rightlca==-1)
        return leftlca;
    else if(leftlca==-1 && rightlca!=-1)
        return rightlca;
    else if(leftlca!=-1 && rightlca!=-1)
        return root->data;
    else 
        return -1;
}

//2 3 9 4 8 -1 2 4 -1 -1 -1 6 -1 -1 -1 -1 -1
//13
//ans : 2 3 4 4
//		2 3 8
// find out the path from root to node where sum is equal to k (here k=13)
void pathsum(BinaryTreeNode<int> *root, int k,vector<int> v)
{
    if(root==NULL)
        return;
    v.push_back(root->data);
    if(root->left==NULL && root->right==NULL)
    {
        if(root->data==k)
    	{
        	for(int i=0;i<v.size();i++)
            	cout << v.at(i) << " ";
            cout << endl;
        	return;
    	}
    	else
    	{
        	while(v.size()!=0)
                v.pop_back();
            return;
    	}
    }
    pathsum(root->left,k-root->data,v);
    pathsum(root->right,k-root->data,v);
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
    vector<int> v;
    pathsum(root,k,v);
}

//print the longest path from root to leaf
// eg: input: 1 2 3 -1 -1 -1 4 -1 -1
// output: 4 3 1
vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
    
    if(root==NULL)
    {
        vector<int>* v = new vector<int>();
        return v;
    }
    vector<int>* left = longestPath(root->left);
    vector<int>* right = longestPath(root->right);
    
    if(left->size()>right->size())
        left->push_back(root->data);
    else
        right->push_back(root->data);
    
   	return (left->size()>right->size()?left:right);
}

//Determine whether the two nodes are cousins of each other or not. 
//Two nodes are said to be cousins of each other if they are at same level of the Binary Tree 
//and have different parents.
//eg:	5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
//		2
//		4
//output: true
int level(BinaryTreeNode<int> *root,int num,int lev)
{
    if(root==NULL)
        return 0;
    if(root->data==num)
        return lev;
    int left = level(root->left,num,lev+1);
    if(left!=0)
        return left;
    return level(root->right,num,lev+1);
}
bool isSibling(BinaryTreeNode<int> *root,int num1,int num2)
{
    if(root==NULL)
        return false;
    if(root->right && root->left)
    {
        return(
        	(root->left->data==num1 && root->right->data==num2)
        	||(root->right->data==num1 && root->left->data==num2)
        	||(isSibling(root->left,num1,num2))
        	|| (isSibling(root->right,num1,num2))
    	);
    }
    else if(root->right)
        return(isSibling(root->right,num1,num2));
    else if (root->left)
        return(isSibling(root->left,num1,num2));
    else
        return false;
}
bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
	if(root==NULL)
        return false;
    if((level(root,p,1)==level(root,q,1)) && !isSibling(root,p,q))
        return true;
    else return false;
}

//4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
	BinaryTree<int>* root = takeinputlevelwise();
	printTree(root);
	pair<int,int> p = heightDiameter(root);
	cout << "Height: " << p.first << endl;
	cout << "Diameter: " << p.second << endl;
	//Demonstrating root to node path
	vector<int>* output = RootToNodePath(root,8);
	for (int i = 0; i < output->size(); ++i)
	{
		cout << output->at(i) << endl;
	}
	delete output;
}
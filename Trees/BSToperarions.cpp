#include<iostream>
#include "BinaryTree.cpp"
#include "Node.cpp"
#include<queue>
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

void elementsInRangeK1K2(BinaryTree<int>* root, int k1, int k2) {
    if(root==NULL)
        return;
    if(root->data<=k2 && root->data>=k1)
    {
        elementsInRangeK1K2(root->left,k1,k2);
        cout << root->data << " ";
        elementsInRangeK1K2(root->right,k1,k2);
    }
    else if(root->data<k1)
        elementsInRangeK1K2(root->right,k1,k2);
    else if(root->data>k2)
        elementsInRangeK1K2(root->left,k1,k2);
}

bool searchInBST(BinaryTree<int> *root , int k) {
    if(root==NULL)
        return false;
    if(root->data==k)
        return true;
    else if(k<root->data)
        return searchInBST(root->left,k);
    else if(k>root->data)
        return searchInBST(root->right,k);
}

pair<Node<int>*,Node<int>*> helper(BinaryTree<int>* root)
{
    if(root==NULL)
    {
        pair<Node<int>*,Node<int>*> p;
        p.first=NULL;
        p.second=NULL;
        return p;
    }
    pair<Node<int>*,Node<int>*> leftAns = helper(root->left);
    pair<Node<int>*,Node<int>*> rightAns = helper(root->right);
    
    Node<int>* LLNode = new Node<int>(root->data); 
    pair<Node<int>*,Node<int>*> res;
    if(leftAns.first==NULL && rightAns.first==NULL)
    {
        res.first = LLNode;
        res.second = LLNode;
    }
    else if(leftAns.first==NULL && rightAns.first!=NULL)
    {
        LLNode->next=rightAns.first;
        res.first = LLNode;
        res.second = rightAns.second;
    }
    else if(leftAns.first!=NULL && rightAns.first==NULL)
    {
        leftAns.second->next=LLNode;
        res.first = leftAns.first;
        res.second = LLNode;
    }
    else
    {
        leftAns.second->next=LLNode;
        LLNode->next=rightAns.first;
        res.first = leftAns.first;
        res.second = rightAns.second;
    }
    return res;
}
//Constructing a sorted LL of any given BST 
Node<int>* constructLinkedList(BinaryTree<int>* root) {
    pair<Node<int>*,Node<int>*> p = helper(root);
    return p.first;
}

//Least common Ancestor
// eg: 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
//the LCA of 1 and 5 would be 4, 1 and 2 would be 2
int getLCA(BinaryTree<int>* root , int val1 , int val2){
    // Write your code here
    if(root==NULL)
        return -1;
    if(root->data==val1 || root->data==val2)
        return root->data;
    int leftlca=-1,rightlca=-1;
    if(val1<root->data || val2<root->data)
        leftlca = getLCA(root->left,val1,val2);
    if(val1>root->data || val2>root->data)
        rightlca = getLCA(root->right,val1,val2);
    
    if(leftlca!=-1 && rightlca==-1)
        return leftlca;
    else if(leftlca==-1 && rightlca!=-1)
        return rightlca;
    else if(leftlca!=-1 && rightlca!=-1)
        return root->data;
    else 
        return -1;
    
}

//4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTree<int>* root = takeinputlevelwise();
    Node<int>* head = constructLinkedList(root);

    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
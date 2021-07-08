#include<iostream>
#include "BinaryTree.cpp"
#include<queue>
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

BinaryTree<int>* Prehelper(int *preorder, int *inorder,int preS,int preE,int inS,int inE)
{ 	
    if(preS>preE || inS>inE)
        return NULL;
    
    int rootdata = preorder[preS];
    
    BinaryTree<int>* root = new BinaryTree<int>(rootdata);
    
    int pos;
    
    for(int i=inS;i<=inE;i++)
    {
        if(rootdata==inorder[i])
        {
            pos = i;
            break;
        }
    }
    
    int linS=inS;
    int linE=pos-1;
    
    int rinS=pos+1;
    int rinE=inE;
    
    int lpreS=preS+1;
    int lpreE=(preS+1) + (linE-linS);
    
    int rpreS=lpreE +1;
    int rpreE=preE;
    
    root->left = Prehelper(preorder,inorder,lpreS,lpreE,linS,linE);
    root->right = Prehelper(preorder,inorder,rpreS,rpreE,rinS,rinE);
		
    return root;
}

BinaryTree<int>* buildTreePre(int *preorder, int preLength, int *inorder, int inLength) {
  	return Prehelper(preorder,inorder,0,preLength-1,0,inLength-1);
}

BinaryTree<int>* Posthelper(int *post,int *in, int posS,int posE,int inS,int inE)
{
    if(inS>inE)
        return NULL;
    int rootdata = post[posE];
    BinaryTree<int>* root = new BinaryTree<int>(rootdata);
    
    int pos;
    for(int i=inS;i<=inE;i++)
    {
        if(in[i]==rootdata)
        {
            pos=i;
            break;
        }    
        
    }
    
    int lposS = posS;
    int linS = inS;
    int linE = pos-1;
    int lposE = linE-linS+lposS;
    
    int rposS = lposE+1;
    int rposE = posE-1;
    int rinS = pos+1;
    int rinE = inE;
    
    root->left = Posthelper(post,in,lposS,lposE,linS,linE);
    root->right = Posthelper(post,in,rposS,rposE,rinS,rinE);
    return root;
}
BinaryTree<int>* buildTreePost(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return Posthelper(postorder,inorder,0,postLength-1,0,inLength-1);
}

//MIND BLOWING QUESTION
//Print the data of all nodes that have a distance K from the target node.
// eg: 3 5 1 6 2 0 8 -1 -1 7 4 -1 -1 -1 -1 -1 -1 -1 -1
// target node: 5, k = 2
// ans: 7 4 1 
void printNodesAtDepthK(BinaryTree<int> *root,int depth)
{
    if(root==NULL)
        return;
    if(depth==0)
    {
        cout << root->data << endl;
        return;
    }
    printNodesAtDepthK(root->left,depth-1);
    printNodesAtDepthK(root->right,depth-1);
}
int nodesAtDistanceKhelper(BinaryTree<int> *root, int node, int k)
{
    if(root==NULL)
        return -1;
    if(root->data==node)
    {
        printNodesAtDepthK(root,k);
        return 0;
    }
    int ld = nodesAtDistanceKhelper(root->left,node,k);
    if(ld!=-1)
    {
        if(ld+1==k)
            cout << root->data << endl;
        else
            printNodesAtDepthK(root->right,k-ld-2);
        return ld+1;
    }
    int rd = nodesAtDistanceKhelper(root->right,node,k);
    if(rd!=-1)
    {
        if(rd+1==k)
            cout << root->data << endl;
        else
            printNodesAtDepthK(root->left,k-rd-2);
        return rd+1;
    }
    else
        return -1;
}
void nodesAtDistanceK(BinaryTree<int> *root, int node, int k) {
    int d = nodesAtDistanceKhelper(root,node,k);
}

int main()
{
    BinaryTree<int>* root = takeinputlevelwise();
    cout << "Enter target node and distance: " << endl;
    int targetnode, distance;
    cin >> targetnode >> distance;
    nodesAtDistanceK(root,targetnode,distance);
    /*
    int* post[]={4,5,2,6,7,3,1};
    int* in[] = {4,2,5,1,6,3,7};
    int* pre[]={1,2,4,5,3,6,7};

    BinaryTree<int>* root1 = buildTreePost(pos,7,in,7);
    BinaryTree<int>* root2 = buildTreePre(pre,7,in,7);

    printTree(root1);
    cout << endl;
    printTree(root2);
    */
}
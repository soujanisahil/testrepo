/*
*Create Binary tree and perform following operations: 
a.Insert b.Display c.Depth of a treed. d.Display leaf-nodes e.Create a copy of a tree
*/

#include <bits/stdc++.h>
using namespace std;
#define COUNT 10

class Node{
    public:
    Node *left,*right;
    int data;
    Node(int data){
        this->data=data;
        this->left= NULL;
        this->right= NULL;
    }
};

void printTree(Node *root,int space){
    if (root==NULL)
        return;
    space+=COUNT;
    printTree(root->right,space);

    for(int i=COUNT; i<space; i++)
        cout<<" ";
    
    cout<<root->data<<"\n";
    printTree(root->left,space);
    
}

int height(Node* node) 
{ 
    if (node == NULL) 
        return -1;
    else
    { 
        /* compute the depth of each subtree */
        int lDepth = height(node->left); 
        int rDepth = height(node->right); 
    
        /* use the larger one */
        if (lDepth > rDepth) 
            return(lDepth + 1); 
        else return(rDepth + 1); 
    } 
}
// nodes from left to right
void printLeafNodes(Node *root)
{
    // if node is null, return
    if (!root)
        return;
     
    // if node is leaf node, print its data   
    if (!root->left && !root->right)
    {
        cout << root->data << " ";
        return;
    }
 
    // if left child exists, check for leaf
    // recursively
    if (root->left)
       printLeafNodes(root->left);
         
    // if right child exists, check for leaf
    // recursively
    if (root->right)
       printLeafNodes(root->right);
}

int main()
{
    Node *root = new Node(43);
    root->left = new Node(25);
    root->right = new Node(67);
    root->left->left = new Node(14);
    root->left->right = new Node(51);
    root->right->left = new Node(26);
    root->right->right = new Node(97);
    root->left->left->left = new Node(81);
    root->left->left->right= new Node(49);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(31);
    root->right->left->left = new Node(29);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(59);
    root->right->right->right = new Node(16);
    
    printTree(root,0);
    cout << "\nHeight of tree is " << height(root);
    cout << "\nLeafnodes are: " ;
    printLeafNodes(root);
    
    return 0;
}
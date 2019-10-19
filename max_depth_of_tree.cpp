#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

struct Node* insert(struct Node* node, int data)
{
    if(node == NULL)
        return( new Node(data));
    else
    {
        if(data<= node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
        return node;
    }
}

int maxDepth(struct Node* node)
{
    if(node == NULL)
        return 0;
    else
        return(max(maxDepth(node->left),maxDepth(node->right))+1);
}

int main()
{
    struct Node* root = NULL;
    root = insert(root,1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    insert(root,5);
    cout<<"\n Depth of BST is "<<maxDepth(root);
    return 0;

}

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * left;
    node * right;

    node()
    {
        left = NULL;
        right = NULL;
    }
    node(int num)
    {
        data = num;
        left = NULL;
        right = NULL;
    }
};

node * sortedArrayToBST(int arr[], int start, int end)
{
    if(start>end)
    return NULL;

    int mid = (start+end)/2;
    node * root = new node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1,end);
    
    return root;
}

void preorderBST(node * root)
{
    if(root == NULL)
    return;

    cout<<" --> "<<root->data;

    preorderBST(root->left);
    preorderBST(root->right);
}

void inorderBST(node * root)
{
    if(root == NULL)
    return;

    inorderBST(root->left);
    cout<<" --> "<<root->data;
    inorderBST(root->right);
}

void postorderBST(node * root)
{
    if(root == NULL)
    return;

    postorderBST(root->left);
    postorderBST(root->right);
    cout<<" --> "<<root->data;
}

int main()
{
    int size;
    cout<<"Enter size: ";
    cin>>size;
    cout<<"\nEnter elements:\n";

    int arr[size];
    
    for(int i=0;i<size;i++)
    cin>>arr[i];
    
    sort(arr, arr + size);

    cout<<"\nSorted Array : ";
    for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";

    node * root = sortedArrayToBST(arr, 0, size-1);

    cout<<"\nPrinting the BST in PREORDER : \n";
    preorderBST(root);

    cout<<"\nPrinting the BST in INORDER : \n";
    inorderBST(root);

    cout<<"\nPrinting the BST in POSTORDER: \n";
    postorderBST(root);
}
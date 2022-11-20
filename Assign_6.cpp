//////////
////////////////// NAME - Keshav Bansal
///////////SID - 21105096
////////////////// BRANCH - ECE


#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

template <typename T>
////// Here we are creating a binary tree class//
class binarytreeNode
{
public:
    T data;
    binarytreeNode *left;
    binarytreeNode *right;

    binarytreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~binarytreeNode()
    {
        delete left;
        delete right;
    }
};


binarytreeNode<int> *createBST(int arr[], int si, int ei)// Sorted array to a  binary search tree
{
    if (si > ei)
    {
        return NULL;
    }
    int mid = (si + ei) / 2;
    binarytreeNode<int> *root = new binarytreeNode<int>(arr[mid]);

    root->left = createBST(arr, si, mid - 1);
    root->right = createBST(arr, mid + 1, ei);
    return root;
}

// CHECK BST

int minimum(binarytreeNode<int> *root)
{
    if (root == NULL) // IT IS A EMPTY SET
    {
        return INT32_MAX; 
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
int maximum(binarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT32_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool isBST(binarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}


binarytreeNode<int>* minValueNode(binarytreeNode<int>* node)
{
    binarytreeNode<int>* current = node;
  
    /* Loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
  
    return current;
}

binarytreeNode<int> *deleteNode(binarytreeNode<int> *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if (root->left == NULL)
        {
            binarytreeNode<int> *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            binarytreeNode<int> *temp = root->left;
            free(root);
            return temp;
        }
        binarytreeNode<int> *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}

    int main()
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n); // WE ARE SORTING THE  ARRAY.
        binarytreeNode<int> *root = createBST(arr, 0, n - 1);
        cout << isBST(root) << endl;

        int data;
        cin >> data;
        root = deleteNode(root,data);
    }
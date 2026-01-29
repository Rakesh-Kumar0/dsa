#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

// Node class represent the node in the binary tree
class Node{
    public:
    int data;  // store the value of the node
    Node* left;  // pointer to the left child  node
    Node* right; // pointer to the right child node


    // constructor to initialize the node with the given value
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// this class containing the logic for binary tree creation
class Solution{
    public:
    Node* createBinaryTree(){
     // create a root node with key value is 5   
    Node* root = new Node(5);

    // create a left child with key value is 6
    root->left = new Node(6);

    // create a right child with key value is 4
    root->right = new Node(4);

    
    root->left->right = new Node(8);
    return root;
    }
};

// main function
int main(){
    Solution solution;
    Node * root = solution.createBinaryTree();
    return 0;
}
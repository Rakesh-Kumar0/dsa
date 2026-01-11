#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// Node class represent the node of linkedlist
class Node {
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

// solution class represents the operation on nodes
class Solution {
    
};

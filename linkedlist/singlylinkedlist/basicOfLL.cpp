#include<bits/stdc++.h>
using namespace std;

// Node class represents node in the linked list

class Node {
    public:
    int data; // Data value
    Node* next; //Pointer to next node
    
    // constructor with data and next
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    
    // constructor with data
    Node(int data1){
        data = data1; 
        next = nullptr;
     // next = NULL; 
    }
};
int main(){
    // creating an array
    vector<int> arr = {2,5,9,6};

    // creating first node
    Node* node = new Node(arr[0]);

    //printing memory address of node
    cout <<node <<endl;

    // printing data value of node
    cout <<"the value of data in node : " <<node->data <<endl;
    return 0;
}

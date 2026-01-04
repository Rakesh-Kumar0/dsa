#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

// Node class represents nodes in the linkedlist
class Node {
    public:
    int data; // data value
    Node* next; // pointer to next node
    Node* back; // pointer to previous node
    
    //  constructor with data, next and previous
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    // constructor with data
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Solution class represents operation on nodes
class Solution {
    public:

    // function to convert array to Linkedlist
    Node* convertArray2DLL(vector<int> &arr){
        Node* head = new Node(arr[0]);
        Node* prev = head;
        for(int i=1; i<arr.size(); i++){
            Node* temp = new Node(arr[i], nullptr, prev);
            prev->next = temp;
            prev = temp;
        }
        return head;
    }

    // function to print DLL
    void printList(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<endl;
    }

    // Function to reverse a doubly linked list using a stack (brute force)
    Node* reverseDLL(Node* head) {
    // If list is empty or has only one node, return as-is
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Stack to store node data
    stack<int> st;

    // Pointer to traverse the list
    Node* temp = head;

    // Push all node values to stack
    while (temp != nullptr) {
        st.push(temp->data);
        temp = temp->next;
    }

    // Reset temp to head for second pass
    temp = head;

    // Replace node values with those from stack
    while (temp != nullptr) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    // Return head of reversed list
    return head; 
    }
};



// Driver code
int main() {
    Solution sol;
    // Input array
    vector<int> arr = {12, 5, 8, 7, 4};

    // Convert array to doubly linked list
    Node* head = sol.convertArray2DLL(arr);

    // Print original DLL
    cout << endl << "Doubly Linked List Initially: " << endl;
    sol.printList(head);

    // Reverse the DLL
    head = sol.reverseDLL(head);

    // Print reversed DLL
    cout << endl << "Doubly Linked List After Reversing: " << endl;
    sol.printList(head);

    return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// Node class represents node of linked list
class Node{
    public:
    int data; // data value
    Node* next; // pointer to next node

    // constructor with data and next
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    // constructor with data
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

// Solution class represents the operation of linked list
class solution{
    public:
    
    // function to insert new node at head
    Node* insertAtHead(Node* head, int newdata){
        //create newnode whose next point to current head
        Node* newnode = new Node(newdata, head);
        // return the new node as the head
        return newnode;
    }

    // function to print  linked list
    void printlist(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data <<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    solution sol;

    // create a sample linked list
    Node* head = new Node(2);
    head->next = new Node(3);
    cout<<"Original linked list: " <<endl;
    sol.printlist(head);
    // insert new node at head
    head = sol.insertAtHead(head , 1);
    cout<<"After insertion at head: "<<endl;
    sol.printlist(head);
    return 0;
}
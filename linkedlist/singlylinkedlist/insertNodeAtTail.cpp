#include<bits/stdc++.h>
using namespace std; 

// Node class represents node of linked list
class Node{
    public:
    int data; // data value
    Node * next; // pointer to next node

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

// Solution class deals with operation of linked list
class solution{
    public:

    // function that insert new node at tail
    Node* insertAtTail(Node* head, int newdata){
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        // create newnode whose next is null
        Node* newnode = new Node(newdata);
        temp->next = newnode;
        return head;
    }
    
    // function that print linked list
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
    // creating object of Solution class
    solution sol;
    Node* head = new Node(2);
    head->next = new Node(3);
    cout<<"original list: "<<endl;
    sol.printlist(head);
    sol.insertAtTail(head, 4);
    cout<<"After insertion list: "<<endl;
    sol.printlist(head);
    return 0;
}
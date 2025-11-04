#include<bits/stdc++.h>
using namespace std;

// Node class represents node of linkedlist
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

// Solution class represents operation of linkedlist
class Solution{
    public:

    // function to convert array to LL
    Node* convertArray2LL(vector<int> &arr){
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for(int i=1;i<arr.size();i++){
            Node* newnode = new Node(arr[i]);
            temp->next = newnode;
            temp = newnode;
        }
        return head;
    }

    // function to print LL
    void printlist(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"-> ";
            temp = temp->next;
        }
        cout<<endl;
    }

    // function to delete tail node 
    Node* deleteTail(Node* head){
        if(head==NULL || head->next==NULL) return NULL;
        Node* temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
        return head;
    }

};
int main(){

    // create oblect of Solution class
    Solution sol;
    // create array
    vector<int> arr = {2,4,3,5,6,8};
    Node* head = sol.convertArray2LL(arr);
    cout<<"Original LL"<<endl;
    sol.printlist(head);
    head = sol.deleteTail(head);
    cout<<"After deletion of head "<<endl;
    sol.printlist(head);
    return 0;
}
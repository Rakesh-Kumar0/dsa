#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
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

    // function to insert new node at head
    Node* insertAtHead(Node* head, int newdata){
        //create newnode whose next point to current head
        Node* newnode = new Node(newdata, head);
        // return the new node as the head
        return newnode;
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

    // function to insert node at kth node
    Node* insertAtKthElement(Node* head,int k,int val){
        int cnt = 0;
        Node* temp = head;
        while(temp != NULL){
            cnt++;
            if(cnt==k) break;
            temp = temp->next;
        }
        Node* newnode = new Node(val,temp->next);
        temp->next = newnode;
        return head;
    }

};
int main(){

    // create oblect of Solution class
    Solution sol;
    // create array
    vector<int> arr = {2,4,3,5,6,8};
    Node* head = sol.convertArray2LL(arr);
    head = sol.insertAtKthElement(head,4,10);
    sol.printlist(head);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// Node class represents node of DLL
class Node{
    public:
    int data; // data value
    Node* next; // pointer to netx node
    Node* back; // pointer to back node
    
    // constructor with data next pointer and back pointer
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    // constructor with data 
    Node(int data1){
        data = data1;
        next = NULL;
        back = NULL;
    }
};

// Solution class represents operation of DLL
class Solution{
    public:

    // function to convert array to DLL
    Node* convertArray2DLL(vector<int> &arr){
        Node* head = new Node(arr[0]);
        Node* prev = head;
        for(int i=1;i<arr.size();i++){
            Node* temp = new Node(arr[i],NULL,prev);
            prev->next = temp;
            prev = temp;
        }
        return head;
    }

    // function to print DLL
    void printlist(Node* head){
        Node* temp = head;
        while(temp !=NULL){
            cout<<temp->data<<"-> ";
            temp = temp->next;
        }
        cout<<endl;
    }

    // function to insert node before head
    Node* insertBeforeHead(Node* head, int val){
        Node* newhead = new Node( val,head,NULL);
        head->back = newhead;
        return newhead;
    }

    // function to insert node before tail
    Node* insertBeforeTail(Node* head, int val){
        if(head->next==NULL) return insertBeforeHead(head,val);
        Node* temp = head;
        while(temp->next !=NULL){
            temp = temp->next;
        }
        Node* prev = temp->back;
        Node* newtail = new Node( val,temp,prev);
        prev->next = newtail;
        temp->back = newtail;
        return head;
    }
};

int main(){
    // create object of Solution class
    Solution sol;
    // create array
    vector<int> arr = {2,3,5,4,7,9};
    Node* head = sol.convertArray2DLL(arr);
    sol.printlist(head);
    head = sol.insertBeforeTail(head,10);
    sol.printlist(head);
    return 0;
}
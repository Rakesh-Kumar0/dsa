#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// Node class represents node in the linked list
class Node{
    public:
    int data;    // Data value
    Node* next;  //Pointer to next node
    Node* back;  //Pointer to previous node

    // constructor with data and next and previous
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

 //Solution  class represents operation of the linked list
class Solution{
    public:

    // fuction to convert array to DLL
    Node* convertArray2DLL(vector<int> &arr){
        Node* head = new Node(arr[0]);
        Node* prev = head;
        for(int i=1;i<arr.size();i++){
            Node* temp = new Node(arr[i], nullptr, prev);
            prev->next = temp;
            prev = temp;
        }
        return head;
    }

    // function to print DLL
    void printlist(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"-> ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){

    // creating objest of Solution class
    Solution sol;

    // creating an array
    vector<int> arr = {2,4,6,8,9};
    Node* head = sol.convertArray2DLL(arr);
    sol.printlist(head);
    return 0;
}
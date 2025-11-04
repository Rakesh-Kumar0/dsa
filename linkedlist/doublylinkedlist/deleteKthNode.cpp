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

    // function to delete  head node
    Node* deleteHead(Node* head){
        if(head==nullptr || head->next==nullptr) return head;
        Node* prev = head;
        head = head->next;
        head->back = nullptr;
        prev->next = nullptr;
        delete prev;
        return head;
    }

    // function to delete  tail node
    Node* deleteTail(Node* head){
        if(head==nullptr || head->next==nullptr) return head;
        Node* tail = head;
        while(tail->next !=NULL){
            tail = tail->next;
        }
        tail->back->next = nullptr;
        tail->back = nullptr;
        delete tail;
        return head;
    }

    // function to delete kth node
    Node* deleteKthNode(Node* head,int k){
        if(head==nullptr) return NULL;
        Node* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            if(cnt==k) break;
            temp = temp->next;
        }
        Node* prev = temp->back;
        Node* front = temp->next;
        if(prev==NULL && front==NULL){
            delete(temp);
            return NULL;
        }
        else if(prev==NULL){
            return deleteHead(head);
             
        }
        else if(front==NULL){
            return deleteTail(head);
            
        }
        prev->next = front;
        front->back = prev;
        temp->back = NULL;
        temp->next = NULL;
        delete(temp);
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
    head = sol.deleteKthNode(head,4);
    sol.printlist(head);
    return 0;
}
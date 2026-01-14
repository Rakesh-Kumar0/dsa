#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
class ArrayStack {
    private:
    int* stackArray; // array to hold elements
    int capacity;   // maximum capacity
    int topIndex;   // index of top element
    public:

    // constructor
    ArrayStack(int size = 1000){
        capacity = size;
        stackArray = new int[capacity];
        topIndex = -1; // initilize stack as empty
    }
      
    // destructor
    ~ ArrayStack(){
            delete[] stackArray;
    }
    

    // push function
    void push(int val){
        if(topIndex == capacity - 1){
            cout<< "stack is overflow "<<endl;
            return;
        }
        stackArray[++topIndex] = val;
    }
    
    // pop function to delete element
    int pop(){
        if(topIndex == -1){
            cout<< "stack is underflow "<< endl;
            return -1;
        }
        return stackArray[topIndex--];
    }

    // top function to return top element
    int top(){
        if(topIndex == -1){
            cout<<"stack is empty " <<endl;
            return -1;
        }
        return stackArray[topIndex];
    }

    // isEmpty function to check stack is empty or not
    bool isEmpty(){
        if(topIndex == -1){
            return true;
        }
        return false;
    }
    
        
};

// Main Function
int main() {
    ArrayStack stack;
    vector<string> commands = {"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            stack.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << stack.pop() << " ";
        } else if (commands[i] == "top") {
            cout << stack.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (stack.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayStack") {
            cout << "null ";
        }
    }

    return 0;
}

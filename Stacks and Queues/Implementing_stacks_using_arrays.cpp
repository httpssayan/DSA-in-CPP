#include<bits/stdc++.h>
using namespace std;

class ArrayStack{
    int *arr;
    int topIndex;
    int capacity;
public:
    ArrayStack(int size=100){
        arr = new int[size];
        capacity = size;
        topIndex = -1;
    }
    ~ArrayStack(){
        delete[] arr;
    }

    void push(int x){
        if(topIndex == capacity-1){
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++topIndex] = x;
    }

    int pop(){
        if(topIndex == -1){
            cout << "Stack underflow" << endl;
            return -1;
        }
        return arr[topIndex--];
    }

    int top(){
        if(topIndex == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty(){
        return topIndex == -1;
    }
};

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
}
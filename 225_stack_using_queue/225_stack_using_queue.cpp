#include <iostream>
#include <deque>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() : size(0) {}
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push_back(x);
        size ++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(empty()){
            cout << "stack empty, cannot pop!\n";
            return 0;
        } else {
            for (int i = 0; i < size - 1; i++){
                int temp = q.front();
                q.pop_front();
                q.push_back(temp);
            }
            int temp = q.front();
            q.pop_front();
            size --;
            return temp;
        }
    }
    
    /** Get the top element. */
    int top() {
        if(empty()) {
            cout << "empty stack, no top element!\n";
            return 0;
        } else {
            return q.back();
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (size == 0);
    }
private:
    int size;
    deque<int> q;
};

int main (){
    MyStack* obj = new MyStack();
    int x = 2;
    obj->push(x);
    int param_3 = obj->top();
    int param_2 = obj->pop();
    bool param_4 = obj->empty();
}


#include <deque>
#include <iostream>
using namespace std;
class MyQueue {
private:
    deque<int> s1;
    deque<int> s2;
    int front; //stores the first element
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty()&&s2.empty();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        // stack is empty
        if(empty()){
            s1.push_back(x);
            front = x;
            return;
        }
        s1.push_back(x);
    }
    
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // stack is empty
        if(empty()){
            cout << "cannot pop, empty queue\n";
            return 10;
        }
        //not empty, two option, either all in s1 or s2
        if(s2.empty()) {
            while(!s1.empty()){
                int temp = s1.back();
                s1.pop_back();
                s2.push_back(temp);
            }
        }
        int temp = s2.back();
        s2.pop_back();
        if(!s2.empty()) {
            front = s2.back();
        } else if(!s1.empty()){
            while(!s1.empty()){
                int temp = s1.back();
                s1.pop_back();
                s2.push_back(temp);
            }
            front = s2.back();   
        } 
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if(empty()){
            cout << "empty queue\n";
            return 10;
        }
        return front;
    }
};

//Your MyQueue object will be instantiated and called as such:
int main(){
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    int param_1 = obj->pop();
    obj->push(5);
    int param_2 = obj->pop();
    int param_3 = obj->pop();
    int param_4 = obj->pop();
    int param_5 = obj->pop();
    return 0;
}

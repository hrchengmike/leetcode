#include <deque>
#include <iostream>
using namespace std;
class MyQueue {
private:
    deque<int> s1;
    deque<int> s2;
    int state; //is 1 if all elements are in s1, vice versa
    int front; //stores the first element
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        state = 1;
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
            state = 1;
            return;
        }
        //not empty, two option, either all in s1 or s2
        if(state == 2) {
            while(!s2.empty()){
                int temp = s2.back();
                s2.pop_back();
                s1.push_back(temp);
            }
        }
        s1.push_back(x);
        state = 1;
    }
    
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // stack is empty
        if(empty()){
            cout << "cannot pop, empty queue\n";
            return 10;
        }
        //not empty, two option, either all in s1 or s2
        if(state == 1) {
            while(!s1.empty()){
                int temp = s1.back();
                s1.pop_back();
                s2.push_back(temp);
            }
        }
        int temp = s2.back();
        s2.pop_back();
        if(!empty()) front = s2.back();
        state = 2;
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
    int param_2 = obj->pop();
    bool param_4 = obj->empty();
    return 0;
}

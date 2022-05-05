class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> a;
    queue<int> b;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        b.push(x);
        while(!a.empty()){
            b.push(a.front());
            a.pop();
        }
        swap(a,b);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = a.front();
        a.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return a.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return a.empty();
    }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
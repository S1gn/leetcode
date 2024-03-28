class MinStack {
    stack<int> mastack;
    stack<int> valstack;
public:
    MinStack() {
        mastack.push(INT_MAX);
    }
    
    void push(int val) {
       valstack.push(val);
       mastack.push(min(val, mastack.top()));
    }
    
    void pop() {
        valstack.pop();
        mastack.pop();
    }
    
    int top() {
        return valstack.top();

    }
    
    int getMin() {
        return mastack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
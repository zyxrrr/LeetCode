class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> a;
    stack<int> b;
    MinStack() {

    }
    
    void push(int x) {
        a.push(x);
        if(b.empty() || x<b.top())
          b.push(x);
        else
          b.push(b.top());
    }
    
    void pop() {
        a.pop();
        b.pop();
    }
    
    int top() {
        return a.top();
    }
    
    int getMin() {
        return b.top();
    }
};

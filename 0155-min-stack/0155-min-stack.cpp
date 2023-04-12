class MinStack {

    int mn;
    
    stack<pair<int, int>> st;
    public:
    MinStack() {
        mn = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty())
            st.push({val, mn});
        else
            st.push({val, min(st.top().second, st.top().first)});
    }
    
    void pop() {
        
        if(!st.empty())
            st.pop();
        
    }
    
    int top() {
        
        return st.top().first;
            
    }
    
    int getMin() {
        
        return min(st.top().first, st.top().second);
        
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
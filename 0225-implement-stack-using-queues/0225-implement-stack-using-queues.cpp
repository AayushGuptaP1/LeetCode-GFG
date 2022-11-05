class MyStack {
private:
    queue<int>q1;
    queue<int>q2;
public:
        
    void push(int x) 
    {
        while(q1.empty()==false)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(q2.empty()==false)
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() 
    {
        int x =-1;
        if(q1.empty())
            return x;
        x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() 
    {
        if(q1.empty())
            return -1;
        return q1.front();
    }
    
    bool empty() 
    {
        return q1.empty();
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
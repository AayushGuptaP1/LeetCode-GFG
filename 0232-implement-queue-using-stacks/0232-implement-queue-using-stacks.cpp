class MyQueue {
private:
    stack<int> input;
    stack<int> output;
public:
   
    
    void push(int x) 
    {
        input.push(x);
    }
    
    int pop() 
    {
        peek();
        if(output.empty())
            return -1;
        int x = output.top();
        output.pop();
        return x;
    }
    
    int peek() {
        if(output.empty())
        {
            while(input.empty()==false)
            {
                output.push(input.top());
                    input.pop();
            }
        }
        return output.empty()? -1 : output.top();
    }
    
    bool empty() {
        return input.empty()&&output.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
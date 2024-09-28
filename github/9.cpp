class MyQueue {
public:
    stack<int> s , z;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        while(!s.empty())
        {
            z.push(s.top());
            s.pop();
        }
        int ans = z.top();
        z.pop();
        while(!z.empty())
        {
            s.push(z.top());
            z.pop();
        }
        return ans;
    }
    
    int peek() {
        while(!s.empty())
        {
            z.push(s.top());
            s.pop();
        }
        int ans = z.top();
        while(!z.empty())
        {
            s.push(z.top());
            z.pop();
        }
        return ans;
    }
    
    bool empty() {
        return s.empty();
    }
};


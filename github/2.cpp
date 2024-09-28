
class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {}
    void push(int x) {s1.push(x);}
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();}}
        if (s2.empty()) return -1;
        int temp = s2.top();
        s2.pop();
        return temp;}
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();}}
        if (s2.empty()) return -1; 
        return s2.top();}
    bool empty() {
        return s1.empty() && s2.empty();}};
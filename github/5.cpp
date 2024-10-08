class MinStack {
public:
    vector<pair<int, int>> v;
    MinStack() {}

    void push(int val) {
        if (v.empty()) {
            v.push_back({val, val});
            return;
        }
        v.push_back({val, val < v.back().second ? val : v.back().second});
    }

    void pop() { v.pop_back(); }

    int top() { return v.back().first; }

    int getMin() { return v.back().second; }
};


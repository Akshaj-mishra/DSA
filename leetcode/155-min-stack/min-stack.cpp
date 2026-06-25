class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
        
    }

    void push(int value) {
        st.push(value);

        if (minSt.empty())
            minSt.push(value);
        else
            minSt.push(min(value, minSt.top()));
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};
class Queue {
    // Define the data members(if any) here.
    stack<int>st;
    public:
    Queue()
     {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        if(st.empty())
        {
            st.push(val);
            return;
        }
        int top=st.top();
        st.pop();
        enQueue(val);
        st.push(top);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(st.size()==0)
        return -1;
        int val=st.top();
        st.pop();
        return val;
    }

    int peek() {
        // Implement the peek() function here.
        if(st.size()==0)
        return -1;
        return st.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return st.empty();
    }
};

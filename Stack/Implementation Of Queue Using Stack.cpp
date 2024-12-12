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

class MyQueue {
public:
stack<int>st1;
stack<int>st2;
    MyQueue() {
        
    }
    
    void push(int x) 
    {
    //    if(st.empty())
    //    {
    //     st.push(x);
    //     return;
    //    }
    //    int val=st.top();
    //    st.pop();
    //    push(x);
    //    st.push(val);

        st1.push(x);
       


    }
    
    int pop() 
    {
        if(st1.empty())
        return -1;
         while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int val=st2.top();
        st2.pop();
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return val;
    }
    
    int peek() {
        if(st1.empty())
        return -1;
          while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
         int val=st2.top();
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return val;
       
    }
    
    bool empty() {
        return st1.empty();
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

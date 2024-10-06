class CustomStack {
public:
// stack<int>st;
vector<int>arr;
int top=-1;
int size=0;
    CustomStack(int maxSize) 
    {
        // size=maxSize;
        arr.resize(maxSize);
    }
    
    void push(int x) 
    {
        if(top+1 == arr.size())
        return;
       top++;
       arr[top]=x;
    }
    
    int pop()
     {
        if(top==-1)
        return -1;

        int val=arr[top];
        top--;
        return val;
    }
    
    void increment(int k, int val)
     {
        if(k>top+1)
        k=top+1;
        for(int i=0;i<k;i++)
        {
            arr[i]=arr[i]+val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

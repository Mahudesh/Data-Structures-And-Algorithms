class MinStack {
public:
stack<long long>st;
long long mini=INT_MAX;
    MinStack() 
    {

        //Formula: 

        //Modified Value Formula : (2*value)-mini
        //Previous Minimum Value Finder : (2*mini)-modifiedValue
        //Logic:
        //If We Found Given Value Is Lesser Than Previous Minimum Value
        //Then Push The Modified Value Into The Stack Else Simply Push The Element
        //Keep The Minimum Value In A Variable

        //Pop()
        //Top() The Element And Check If Top() Is Smaller Than Mini 
        //If So U Popped The Modified Value
        //To Update The Previous Value Of Mini To Mini Since Current Modified Value(Mini) Is Popped
        //Use The Previous Mini Finder Formula And Store It In A Mini Variable

        //Top()
        // //Top() The Element And Check If Top() Is Smaller Than Mini 
        //If So Return Mini It Is The Actual Value Which Has To Be Stored In Stack 

        //Min()
        //To Get The Minimum Value Just Return Mini
    }
    
    void push(long long val) 
    {
        if(st.empty())
        {
            st.push(val);
           mini=val;
        }
        else
        {
            if(val<mini)
            {
                st.push((long long)(2*val)-mini);
                mini=val;
            }
            else
            {
                st.push(val);
            }
        }
    }
    
    void pop() 
    {
        if(st.empty()) return;
       long long modifiedValue=st.top();
       st.pop();
       if(modifiedValue<mini)
       {
        mini=((long long)2*mini-modifiedValue);
       }
    }
    
    int top() 
    {
        if(st.empty()) return -1;
        long long modifiedValue=st.top();
        if(modifiedValue<mini)
        {
            return mini;
        }
        else
        {
            return modifiedValue;
        }
    }
    
    int getMin() 
    {
       return mini;
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

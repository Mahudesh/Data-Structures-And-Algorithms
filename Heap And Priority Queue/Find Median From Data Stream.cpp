class MedianFinder {
public:
        //Max Heap Stores Always Smaller Elements <= Large Heap
        priority_queue<int>smallHeap;
        //Min Heap Stores Always Greater Elements > Small Heap
        priority_queue<int, vector<int>,greater<int>>largeHeap;
    MedianFinder() 
    {

    }
    
    void addNum(int num) 
    {
        smallHeap.push(num);
        if(!smallHeap.empty() && !largeHeap.empty() && smallHeap.top()>largeHeap.top())
        {
            int val=smallHeap.top();
            smallHeap.pop();
            largeHeap.push(val);
        }

        if(smallHeap.size()> 1+largeHeap.size())
        {
            int val=smallHeap.top();
            smallHeap.pop();
            largeHeap.push(val);
        }
        if(largeHeap.size()> 1+smallHeap.size())
        {
            int val=largeHeap.top();
            largeHeap.pop();
            smallHeap.push(val);
        }
        return;
    }
    
    double findMedian()
     {
        if(smallHeap.size()>largeHeap.size())
        return smallHeap.top();
        else if(largeHeap.size()>smallHeap.size())
        return largeHeap.top();
        else
        {
            double a=smallHeap.top();
            double b=largeHeap.top();
            return (a+b)/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

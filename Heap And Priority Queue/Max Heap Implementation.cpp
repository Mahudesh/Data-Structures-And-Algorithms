class Solution{
    public:
    void heapify_down(vector<int>& arr, int ind)
    {
        int largest=ind;
        int leftChild=(2*ind)+1;
        int rightChild=(2*ind)+2;

        if(leftChild<arr.size() && arr[largest]<arr[leftChild])
        {
            largest=leftChild;
        }
        if(rightChild<arr.size() && arr[largest]<arr[rightChild])
        {
            largest=rightChild;
        }
        if(ind!=largest)
        {
            swap(arr[largest],arr[ind]);
            heapify_down(arr,largest);
        }
        return;
    }
    void heapify_up(vector<int>& arr, int ind)
    {
        int parent=(ind-1)/2;
        if(ind>0)
        {
            if(arr[ind]>arr[parent])
            {
                swap(arr[ind],arr[parent]);
                heapify_up(arr,parent);
            }
        }
        return;
    }
    vector<int>arr;
    int size=0;

        void initializeHeap()
        {
            arr.clear();
            size=0;
        }

        void insert(int key)
        {
            arr.push_back(key);
            size++;
            heapify_up(arr,size-1);
            return;
        }

        void changeKey(int index, int new_val)
        {
            if(index<arr.size() && index>=0)
            {
                if(arr[index]<new_val)
                {
                    arr[index]=new_val;
                    heapify_up(arr,index);
                }
                else
                {
                    arr[index]=new_val;
                    heapify_down(arr,index);
                }
            }
            return;
        }

        void extractMax()
        {
            int ele=arr[0];
            swap(arr[0],arr[size-1]);
            size--;
            arr.pop_back();
            heapify_down(arr,0);
            
        }

        bool isEmpty(){
            if(size==0)
            return true;
            return false;
        }

        int getMax(){
            return arr[0];
        }

        int heapSize(){
            return size;
        }
};

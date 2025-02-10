class minHeap {
public:
vector<int>arr;
int size=0;

    void heapify_up(vector<int>& arr, int ind)
    {
        int parent=(ind-1)/2;
        if(ind>0)
        {
            if(arr[ind]<arr[parent])
            {
                swap(arr[ind],arr[parent]);
                heapify_up(arr,parent);
            }
        }
    }
    void heapify_down(vector<int>& arr, int ind)
    {
        int smallest=ind;
        int leftChild=(2*ind)+1;
        int rightChild=(2*ind)+2;

        if(leftChild<arr.size() && arr[smallest]>arr[leftChild])
        smallest=leftChild;
        if(rightChild<arr.size() && arr[smallest]>arr[rightChild])
        smallest=rightChild;

        if(smallest!=ind)
        {
            swap(arr[ind],arr[smallest]);
            heapify_down(arr,smallest);
        }
    }
    // Constructor for the class.
    minHeap(int cap)
     {
        // Write your code here.
        arr.clear();
        size=0;
    }

    // Implement the function to remove minimum element.
    int extractMinElement() 
    {
        // Write you code here.
        int ele=arr[0];
        swap(arr[0],arr[size-1]);

        arr.pop_back();
        size--;

        heapify_down(arr,0);
        return ele;
    }

    // Implement the function to delete an element.
    void deleteElement(int ind) 
    {
        // Write you code here.
        if(ind>=0 && ind<arr.size())
        {
            swap(arr[ind],arr[size-1]);
            size--;
            arr.pop_back();

            int parent=(ind-1)/2;
            if(ind>0 && arr[ind]>arr[parent])
            {
                heapify_down(arr,ind);
            }
            else
            {
                heapify_up(arr,ind);
            }
        }
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val)
     {
        // Write you code here.
        arr.push_back(val);
        size++;
        heapify_up(arr,size-1);
    }
};

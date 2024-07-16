#LeetCode: 146

class LRUCache {
public:

    class Node
    {
        public:
        int key;
        int data;
        Node* prev;
        Node* next;

        Node(int key, int data)
        {
            this->key=key;
            this->data=data;
            // prev=nullptr;
            // next=nullptr;
        }
    };

    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

   

    unordered_map<int,Node*>Map;
    int cap=0;
    LRUCache(int capacity) 
    {
        cap=capacity;
         head->next=tail;
    tail->prev=head;
        
    }
    void deleteNode(Node* delNode)
    {
        Node* delPrevious=delNode->prev;
        Node* delNext=delNode->next;
        delPrevious->next=delNext;
        delNext->prev=delPrevious;
        //Do Not Delete The Node Because This Node Memory Is Going To Be Inserted In Head->next
        //By Deleting It Can Cause Dangling Pointer Error
        // delete(delNode);
    }
    void addNode(Node* addNode)
    {
        Node* temp=head->next;
        head->next=addNode;
        temp->prev=addNode;  
        addNode->next=temp;
        addNode->prev=head;
          
          
   
    }
    int get(int key)
     {
        if(Map.find(key)!=Map.end())
        {
            Node* getNode=Map[key];
            int value=getNode->data;
            Map.erase(key);
            deleteNode(getNode);
            addNode(getNode);
            Map[key]=head->next;
            return value;
        }
        return -1;
    }
    
    void put(int key, int value)
     {
         if(Map.find(key)!=Map.end())
        {
            Node* oldNode=Map[key];
            Map.erase(key);
            deleteNode(oldNode);
        }
        else if(Map.size()==cap)
        {
            Map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
       

        Node* insertNode=new Node(key,value);
        addNode(insertNode);
        Map[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

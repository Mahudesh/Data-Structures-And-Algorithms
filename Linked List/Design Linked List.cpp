
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        next=nullptr;
    }
};
class MyLinkedList {
public:
    Node* head;
    int size;

    MyLinkedList() 
    {
        head=nullptr;
        size=0;
    }
    
    int get(int index) 
    { // 1 2 3
      // 0 1 2
        if(index<0 || index>=size || head==nullptr)
        return -1;
        int cnt=0;
        Node* temp=head; // 1 3
        while(temp!=nullptr)
        {
            if(cnt==index)
            break;
            cnt++;
            temp=temp->next;
        }
        return temp->data;
    }
    
    void addAtHead(int val) 
    {
        
        Node* newNode=new Node(val);
        newNode->next=head;
        head=newNode;
        size++;

    }
    
    void addAtTail(int val)
     {
        Node* newNode=new Node(val);
        if(head==nullptr)
        {
            head=newNode;
            size++;
        }
        else{
            Node* temp=head;
            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next=newNode;
            size++; 
            temp=newNode;
            newNode->next=nullptr;
        }
    }
    
    void addAtIndex(int index, int val)
     {
        //If Size==1 And Index=1 (Considering Element Present At Index 0)
        //Then I Can Add An Element Before Index 1
        if(index<0 || index>size)
        return;
        Node* newNode=new Node(val);
       if(index==0)
       {
            newNode->next=head;
            head=newNode;
            size++;
            return;
       }
        Node* temp=head;
        int cnt=1;
        while(temp!=nullptr)
        {
            if(cnt==index)
            break;
            cnt++;
            temp=temp->next;
        }
        Node* next=temp->next;
        newNode->next=next;
        temp->next=newNode;
        size++;
    }
    
    void deleteAtIndex(int index)
     {
        //If Size==1 And Asking To Delete Index 1 (0-based) Then There Is No Index In It
        //So Return It
        if(index<0 || index>=size || head==nullptr)
        return;
        if(index==0)
        {
            Node* del=head;
            head=head->next;
            delete(del);
            size--;
        }
        else
        {
            int cnt=1;
            Node* temp=head;
            while(temp!=nullptr)
            {
                if(cnt==index)
                break;
                cnt++;
                temp=temp->next;
            }
            Node* delNode=temp->next;
            temp->next=delNode->next;
            delete(delNode);
            size--;

        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

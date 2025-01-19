Solution {
  public:
    Node* rotate(Node* head, int k) 
    {
        // Your code here
        if(!head || head->next==nullptr)
        return head;
        int len=0;
        Node* temp=head;
        while(temp!=nullptr)
        {
            len++;
            temp=temp->next;
        }
        if(k%len==0)
        return head;
        k=k%len;
        
        temp=head;
        int cnt=1;
        while(temp!=nullptr)
        {
            if(cnt==k)
            break;
            cnt++;
            temp=temp->next;
        }
        Node* newHead=temp->next;
        temp->next=nullptr;
        temp=newHead;
        while(temp->next!=nullptr)
        temp=temp->next;
        
        temp->next=head;
        
        return newHead;
        
    }

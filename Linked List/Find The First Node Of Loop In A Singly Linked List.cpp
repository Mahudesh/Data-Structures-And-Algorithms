int findFirstNode(Node* head) 
    {
        // your code here
        Node* slow=head;
        Node* fast=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                slow=head;
                while(slow!=fast)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow->data;
            }
        }
        // if(fast==nullptr || fast->next==nullptr)
        return -1;
        
    }

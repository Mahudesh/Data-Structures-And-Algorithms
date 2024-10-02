 public:
    Node* sortedMerge(Node* head1, Node* head2) 
    {
        // code here
        if(head1==nullptr && head2==nullptr)
        return nullptr;
        Node* dummyNode=new Node(-1);
        Node* currNode=dummyNode;
        Node* temp1=head1;
        Node* temp2=head2;
        while(temp1!=nullptr && temp2!=nullptr)
        {
            int first=temp1->data;
            int second=temp2->data;
            if(first>second)
            {
                currNode->next=temp2;
                currNode=currNode->next;
                temp2=temp2->next;
            }
            else
            {
                currNode->next=temp1;
                currNode=currNode->next;
                temp1=temp1->next;
            }
        }
        // if(temp1!=nullptr)
        // currNode->next=temp1;
        // else if(temp2!=nullptr)
        // currNode->next=temp2;
        // return dummyNode->next;
        while(temp1!=nullptr)
        {
            currNode->next=temp1;
            currNode=currNode->next;
            temp1=temp1->next;
        }
        while(temp2!=nullptr)
        {
            currNode->next=temp2;
            currNode=currNode->next;
            temp2=temp2->next;
        }
        return dummyNode->next;
    }

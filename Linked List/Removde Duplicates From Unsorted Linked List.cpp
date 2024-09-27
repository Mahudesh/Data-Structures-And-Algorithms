class Solution {
  public:
    Node *removeDuplicates(Node *head)
    {
        // your code goes here
        //Use A Set Data Structure To Store Unique Elements To Find Whether The Element Is Seen Or Not
        set<int>st;
        Node* temp=head;
        Node* prev=head;
        while(temp!=nullptr)
        {
            if(st.find(temp->data)!=st.end())
            {
                Node* deltemp=temp;
                prev->next=deltemp->next;
                temp=temp->next;
                delete(deltemp);
                
                
            }
            else
            {
                st.insert(temp->data);
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};

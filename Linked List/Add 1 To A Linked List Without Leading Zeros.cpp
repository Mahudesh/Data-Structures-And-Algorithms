
class Solution {
  public:
  Node* reverse(Node* head)
  {
      Node* prev=nullptr;
      Node* temp=head;
      while(temp)
      {
          Node* next=temp->next;
          temp->next=prev;
          prev=temp;
          temp=next;
      }
      return prev;
  }
    Node* addTwoLists(Node* num1, Node* num2) 
    {
        // code here
        Node* revHead1=reverse(num1);
        Node* revHead2=reverse(num2);
        Node* temp1=revHead1;
        Node* temp2=revHead2;
        
        Node* dummyNode=new Node(-1);
        Node* curr=dummyNode;
        int sum=0;
        int carry=0;
        
        while(temp1!=nullptr || temp2!=nullptr)
        {
            sum=carry;
            if(temp1)
            {
                sum=sum+temp1->data;
            }
            if(temp2)
            {
                sum=sum+temp2->data;
            }
            
            Node* newNode=new Node(sum%10);
            curr->next=newNode;
            curr=curr->next;
            carry=(sum/10);
            
            if(temp1)
            temp1=temp1->next;
            if(temp2)
            temp2=temp2->next;
            
        }
        Node* head=reverse(dummyNode->next);
        if(carry>0)
        {
            Node* newNode=new Node(carry);
            newNode->next=head;
            head=newNode;
        }
        temp1=head;
        while(temp1!=nullptr && temp1->data==0)
        {
            Node* next=temp1->next;
            head=head->next;
            delete(temp1);
            temp1=next;
            
        }
        return head;
    }

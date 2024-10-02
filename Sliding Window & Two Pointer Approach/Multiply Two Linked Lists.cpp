class solution {
  public:
  long long listToInteger(Node* head)
  {
      Node* temp=head;
      long long num=0;
      while(temp!=nullptr)
      {
          num=(num*10)+temp->data;
          temp=temp->next;
      }
      return num;
  }
    long long multiplyTwoLists(Node *first, Node *second) 
    {
        // code here
        long long num1=listToInteger(first);
        long long num2=listToInteger(second);
        int mod=1e9+7;
        return (num1*num2)%mod;
        
        // Node* head2=reverseNode(second);
    }

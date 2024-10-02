/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
Node* reverseNode(Node* head)
{
    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=nullptr)
    {
        Node* next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev;
}
Node *addOne(Node *head)
{
    // Write Your Code Here.
   Node* newHead= reverseNode(head);
   Node* temp=newHead;
//    Node* prev=temp;
   int carry=1;
   while(temp!=nullptr)
   {
       temp->data=temp->data+carry;
       if(temp->data<=9)
       {
           carry=0;
           break;
       }
       else if(temp->data>9)
       {
           temp->data=0;
       }
    //    prev=temp;
       temp=temp->next;
   }
   newHead=reverseNode(newHead);
   if(carry==1)
   {
       Node* newNode=new Node(1);
       newNode->next=newHead;
       newHead=newNode;
   }
   return newHead;

}

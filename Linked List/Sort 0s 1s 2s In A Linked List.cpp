/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head)
{
    // Write your code here.
    Node* dummyZero=new Node(-1);
    Node* dummyOne=new Node(-1);
    Node* dummyTwo=new Node(-1);
    Node* zero=dummyZero;
    Node* one=dummyOne;
    Node* two=dummyTwo;
    Node* temp=head;
    while(temp!=nullptr)
    {
        if(temp->data==0)
        {
            zero->next=temp;
            zero=zero->next;
        }
        else if(temp->data==1)
        {
            one->next=temp;
            one=one->next;
        }
        else
        {
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }
    if(one!=dummyOne)
    {
        zero->next=dummyOne->next;
    }
    else if(one==dummyOne)
    {
        zero->next=dummyTwo->next;
    }
    one->next=dummyTwo->next;
    two->next=nullptr;
    return dummyZero->next;
}

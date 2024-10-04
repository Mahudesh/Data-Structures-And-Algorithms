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
Node* func(Node* head1, Node* head2)
{
    Node* temp1=head1;
    Node* temp2=head2;
    Node* dummyNode=new Node(-1);
    Node* currNode=dummyNode;
    while(temp1!=nullptr && temp2!=nullptr)
    {
        int first=temp1->data;
        int second=temp2->data;
        if(first<second)
        {
            currNode->next=temp1;
            currNode=currNode->next;
            temp1=temp1->next;
        }
        else
        {
            currNode->next=temp2;
            currNode=currNode->next;
            temp2=temp2->next;
        }
    }
    if(temp1)
    currNode->next=temp1;
    else
    currNode->next=temp2;
    return dummyNode->next;
}

Node* mergeKLists(vector<Node*> &listArray)
{
    // Write your code here.
    Node* head=listArray[0];
    for(int i=1;i<listArray.size();i++)
    {
        head=func(head,listArray[i]);
    }
    return head;
}

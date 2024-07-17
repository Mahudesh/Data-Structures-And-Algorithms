/****************************************************************

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


*****************************************************************/

class Stack
{
    //Write your code here
    Node* top=nullptr;
    int size=0;

public:
    Stack()
    {
        //Write your code here
    }

    int getSize()
    {
        //Write your code here
        return size;
    }

    bool isEmpty()
    {
        //Write your code here
        if(size==0)
        return true;
        return false;
    }

    void push(int data)
    {
        //Write your code here
        Node* newNode = new Node(data);
        newNode->next=top;
        top=newNode;
        size++;

    }

    void pop()
    {
        //Write your code here
        if(size<=0) return;
        Node* deltemp=top;
        top=top->next;
        delete(deltemp);
        size--;
    }

    int getTop()
    {
        //Write your code here
        if(size<=0) return -1;
        int value=top->data;
        return value;
    }
};

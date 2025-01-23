class BrowserHistory {
public:
class Node
{
    public:
    Node* prev;
    Node* next;
    string data;
    Node(string data)
    {
        this->data=data;
        prev=next=nullptr;
    }
};
Node* curr=nullptr;
    BrowserHistory(string homepage)
     {
        curr=new Node(homepage);
    }
    
    void visit(string url)
     {
        Node* newNode=new Node(url);
        curr->next=newNode;
        newNode->prev=curr;
        curr=curr->next;
    }
    
    string back(int steps) 
    {
        while(steps>0)
        {
            if(curr->prev)
            curr=curr->prev;
            else
            break;
            steps--;
        }
        return curr->data;
    }
    
    string forward(int steps)
     {
        while(steps>0)
        {
            if(curr->next)
            curr=curr->next;
            else
            break;
            steps--;
        }
        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

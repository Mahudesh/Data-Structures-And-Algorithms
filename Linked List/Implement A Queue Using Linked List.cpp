/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
// Node* head=nullptr;
void MyQueue:: push(int x)
{
        // Your Code
        QueueNode* newNode=new QueueNode(x);
        if(front==nullptr && rear==nullptr)
        {
            front=newNode;
            rear=newNode;
            return;
        }
        rear->next=newNode;
        rear=rear->next;
        
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code       
        if(front==nullptr && rear==nullptr)
        return -1;
      if(front==rear)
      {
          int val=front->data;
          front=nullptr;
          rear=nullptr;
          return val;
      }
      int val=front->data;
      front=front->next;
      return val;
}

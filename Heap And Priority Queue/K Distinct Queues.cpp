Problem Statement



Prakash is implementing a program to manage k distinct queues within a single array for a college library system. The program should support efficient enqueue and dequeue operations for each queue, ensuring no overlap and optimal use of array space.



Assist Prakash in completing the program.

Input format :
The first line consists of two integers, k and n, representing the number of queues and the total size of the array respectively.

Then, the input consists of inputs for enqueue and dequeue operations.

For each operation:

If 'operation' is 1 (enqueue), it takes two more integers representing the item and queue number to enqueue the item into the specified queue each separated by a space.
If 'operation' is 2 (dequeue), it takes one more integer representing the queue number to dequeue an element from the specified queue each separated by space.
If 'operation' is 0 (exit), the program exits which is a mandatory input to end the program.

Output format :
The output prints the following corresponding to the specified operations:

Enqueue Operation:

If the specified queue is full, the output prints: "Queue X overflow" where X is the queue number.
If the enqueue operation is successful: nothing will be printed.
Dequeue Operation:

If the specified queue is empty, the output prints: "Queue X underflow" where X is the queue number.
If the dequeue operation is successful, the output prints: "Dequeued element from queue X is Y," where X is the queue number and Y is the dequeued item.
Exit Operation: Nothing will be printed in the console.


  // You are using GCC
#include<bits/stdc++.h>
using namespace std;

int maxsize;
int siz;
int s;

class Demo
{
    public:
    int front;
    int rear;
    // int arr[100];
    vector<int>arr;
    Demo()
    {
        
    }
    Demo(int front, int rear)
    {
        
       this->front=front;
       this->rear=rear;
       arr.resize(10000);
    //   arr[100]={0};
    }
    void enqueue(int val, int qno)
    {
        if(siz>=maxsize)
        {
            cout<<"Queue "<<qno<<" overflow"<<endl;
            return;
        }
        
        if(front==-1 && rear==-1)
        {
            front++;
            rear++;
            arr[rear]=val;
            siz++;
            return;
        }
        rear++;
        arr[rear]=val;
        siz++;
        
        
    }
    void dequeue(int qno)
    {
        if(siz<=0 || front==-1)
        {
            cout<<"Queue "<<qno<<" underflow"<<endl;
            return;
        }
        int val=arr[front];
        front++;
        siz--;
        
        if(front>rear)
        {
            front=-1;
            rear=-1;
        }
        cout<<"Dequeued element from queue "<<qno<<" is "<<val<<endl;
        return;
        
    }
    
};
int main()
{
    int k,n;
    cin>>k>>n;
    maxsize=n;
    siz=0;
    s=100;
    Demo ob[k];
    for(int i=0;i<k;i++)
    {
        ob[i]= Demo(-1,-1);
    }
    int ch;
    while(true)
    {
        cin>>ch;
        if(ch==1)
        {
            int val;
            int qno;
            cin>>val>>qno;
            ob[qno].enqueue(val,qno);
        }
        else if(ch==2)
        {
            int qno;
            cin>>qno;
            ob[qno].dequeue(qno);
        }
        else if(ch==0)
        {
            return 0;
        }
    }
    
}

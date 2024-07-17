#include <bits/stdc++.h> 
class Queue 
{
    class Node
    {
        public:
        int data;
        Node* next;
        Node(int data)
        {
            this->data=data;
            this->next=nullptr;
        }
    };

    Node* frontt=nullptr;
    Node* rear=nullptr;
public:
    Queue() 
    {
        // Implement the Constructor
         
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(frontt==nullptr)
        return true;
        return false;
    }

    void enqueue(int data)
     {
        // Implement the enqueue() function
        Node* newNode=new Node(data);
        if(frontt==nullptr && rear==nullptr)
        {
            frontt=newNode;
            rear=newNode;
            return;
        }
        rear->next=newNode;
        rear=newNode;
    }

    int dequeue() 
    {
        // Implement the dequeue() function
        if(frontt==nullptr) 
        return -1;
        int value=frontt->data;
        Node* deltemp=frontt;
        frontt=frontt->next;
        if(frontt==nullptr) 
        rear=nullptr;
        delete(deltemp);
        return value;
    }

    int front() {
        // Implement the front() function
        if(frontt==nullptr) return -1;
        return frontt->data;
    }
};

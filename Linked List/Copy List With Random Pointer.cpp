#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    // unordered_map<Node*,pair<Node*,Node*>>Map;
    unordered_map<LinkedListNode<int>*,LinkedListNode<int>*>Map;


    LinkedListNode<int>* temp=head;
    while(temp!=nullptr)
    {
        // Map[]
        // Map[temp]={temp->next,temp->random};
        int val=temp->data;
        LinkedListNode<int>* newNode=new LinkedListNode<int>(val);
        Map[temp]=newNode;
        temp=temp->next;
    }
   temp=head;
   while(temp)
   {
       LinkedListNode<int>* copyNode = Map[temp];
       copyNode->next=Map[temp->next];
       copyNode->random=Map[temp->random];
       temp=temp->next;
   }
   return Map[head];
}

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node* findMiddle(Node* head)
{
	if(head==nullptr || head->next==nullptr)
	return head;
	Node* slow=head;
	Node* fast=head->next;
	while(fast!=nullptr && fast->next!=nullptr)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
Node* mergeLL(Node* left, Node* right)
{
	Node* dummyNode=new Node(-1);
	Node* curr=dummyNode;
	while(left!=nullptr && right!=nullptr)
	{
		if(left->data<=right->data)
		{
			curr->next=left;
			curr=curr->next;
			left=left->next;
		}
		else
		{
			curr->next=right;
			curr=curr->next;
			right=right->next;
		}
	}
	if(left!=nullptr)
	{
		curr->next=left;

	}
	else
	{
		curr->next=right;
	}
	return dummyNode->next;
}
Node *sortLL(Node *head)
{
    // Write your code here.
	//Merge Sort
	if(head==nullptr || head->next==nullptr)
	return head;

	Node* middle=findMiddle(head);
	Node* left=head;
	Node* right=middle->next;
	middle->next=nullptr;

	left=sortLL(left);
	right=sortLL(right);
	return mergeLL(left,right);
}

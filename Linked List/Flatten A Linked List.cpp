/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
#include<algorithm>
Node* mergeTwoLists(Node* head1, Node* head2)
{
	Node* temp1=head1;
	Node* temp2=head2;

	Node* dummyNode=new Node(-1);
	Node* curr=dummyNode;
	while(temp1!=nullptr  && temp2!=nullptr)
	{
		if(temp1->data<=temp2->data)
		{
			curr->child=temp1;
			curr=curr->child;
			temp1=temp1->child;
		}
		else
		{
			curr->child=temp2;
			curr=curr->child;
			temp2=temp2->child;
		}
		// curr->next=nullptr;
	}
	if(temp1)
	{
		curr->child=temp1;
	}
	else
	{
		curr->child=temp2;
	}
	return dummyNode->child;
}
Node* flattenLinkedList(Node* head) 
{
	if(head==nullptr || head->next==nullptr)
	return head;

	Node* mergeHead=flattenLinkedList(head->next);
	//Detach The Next Pointer To Prevent Loop
	head->next=nullptr;
	return mergeTwoLists(head,mergeHead);

	// Write your code here
	// vector<int>arr;
	// Node* temp=head;
	// while(temp)
	// {
	// 	arr.push_back(temp->data);
	// 	if(temp->child)
	// 	{
	// 		Node* t2=temp->child;
	// 		while(t2!=nullptr)
	// 		{
	// 			arr.push_back(t2->data);
	// 			t2=t2->child;
	// 		}
	// 	}
	// 	temp=temp->next;
	// }
	// sort(arr.begin(),arr.end());
	// int n=arr.size();
	// 	Node* newHead=new Node(arr[0]);
	// 	 temp=newHead;
	// for(int i=1;i<n;i++)
	// {
	// 	Node* newNode=new Node(arr[i]);
	// 	temp->child=newNode;
	// 	temp=temp->child;
	// }
	// return newHead;

	
}

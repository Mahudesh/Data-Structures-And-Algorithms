/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        if(!head)
        return head;
        ListNode* dummyNode1=new ListNode(-1);
        ListNode* curr1=dummyNode1;
        ListNode* dummyNode2=new ListNode(-1);
        ListNode* curr2=dummyNode2;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            if(temp->val<x)
            {
                curr1->next=temp;
                curr1=curr1->next;
            }
            else if(temp->val>=x)
            {
                curr2->next=temp;
                curr2=curr2->next;
            }
            temp=temp->next;
        }
        curr1->next=dummyNode2->next;
        //To Terminate The Last Node Which May Connect To The Any Element Of DummyNode 1(Original List)
        curr2->next=nullptr;
        return dummyNode1->next;
    }
};

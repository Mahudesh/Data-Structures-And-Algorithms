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
ListNode* reverseback(ListNode* head)
{
    ListNode* temp=head;
    ListNode* prev=nullptr;
    while(temp!=nullptr)
    {
        ListNode* next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev;
}
    void reorderList(ListNode* head) 
    {
        //Find Middle Element
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* middle=slow;
        ListNode* newHead=middle->next;
        middle->next=nullptr;
        newHead=reverseback(newHead);
        ListNode* temp1=head;
        ListNode* temp2=newHead;
        ListNode* f=nullptr;
        ListNode* s=nullptr;
        while(temp1!=nullptr && temp2!=nullptr)
        {
            f=temp1->next;
            s=temp2->next;
            temp1->next=temp2;
            temp2->next=f;

            temp1=f;
            temp2=s;
        }
            // 1 2 3   5 4
        // 1 2 3
        // 5 4

    }
};

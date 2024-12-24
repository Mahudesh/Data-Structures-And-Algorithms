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
ListNode* mergeLL(ListNode* left, ListNode* right)
{
    ListNode* dummyNode=new ListNode(-1);
    ListNode* temp=dummyNode;

    while(left!=nullptr && right!=nullptr)
    {
        if(left->val<=right->val)
        {
            temp->next=left;
            temp=temp->next;
            left=left->next;
        }
        else
        {
            temp->next=right;
            temp=temp->next;
            right=right->next;
        }
    }
    if(left)
    {
        temp->next=left;
    }
    else if(right)
    {
        temp->next=right;
    }
    return dummyNode->next;
}
    ListNode* sortList(ListNode* head) 
    {
        if(!head || head->next==nullptr)
        return head;

        //Always Keep fast=head->next One Step Ahead To Match Correctly For Even Length
        //In Even Length Linked List Slow Can Go One Ahead Of Middle Element
        //Hence Start Fast From head->next
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* left=head;
        ListNode* right=slow->next;
        slow->next=nullptr;
        left=sortList(left);
        right=sortList(right);
        return mergeLL(left,right);
    }
};

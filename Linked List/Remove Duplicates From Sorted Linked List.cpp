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
    ListNode* deleteDuplicates(ListNode* head)
     {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* temp = head;
        ListNode* prev = head;
        while(temp!=nullptr && temp->next!=nullptr)
        {
            if(temp->val==temp->next->val) //1 1 1
            {
                ListNode* del = temp->next;
                temp->next=del->next;
                delete(del);
            }
            else
            temp=temp->next;
        }
        return head;
    }
};

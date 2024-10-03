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
    ListNode* swapNodes(ListNode* head, int k)
     {
        // if(head==nullptr) return nullptr;
        // if(head->next==nullptr)
        // return head;
        // ListNode* temp=head;
        // int cnt=0,c=0;
        // while(temp!=nullptr)
        // {
        //     cnt++;
        //     temp=temp->next;
        // }
        // temp=head;
        // ListNode* temp2=head;
        // while(temp!=nullptr)
        // {
        //     c++;
        //     if(c==k)
        //     {
        //         break;
        //     }
        //     temp=temp->next;
        // }
        // c=(cnt-k)+1;
        // cnt=0;
        // while(temp2!=nullptr)
        // {
        //     cnt++;
        //     if(cnt==c)
        //     {
        //         break;
        //     }
        //     temp2=temp2->next;
        // }
        // swap(temp->val,temp2->val);
        // return head;

        if(head==nullptr)
        {
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        int cnt=1;
        while(cnt<k)
        {
            cnt++;
            fast=fast->next;
        }
        ListNode* ref=fast;
        while(fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next;
        }
        swap(ref->val,slow->val);
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        //Use Cycle Detection Algorithm By Connecting Tail To Its Head
        //And Traverse Slow And Fast From Other Linked List
        //If They Meet Loop Exists Then Find The Starting Point Of Loop
        //Else Then Sure (2nd Linked List) Other One Is Not Connected To (1st Linked List) Current List

        ListNode* tail=headA;
        while(tail->next!=nullptr)
        {
            tail=tail->next;
        }
        //Form The Loop By Connecting Tail To Its Head
        tail->next=headA;

        ListNode* slow=headB;
        ListNode* fast=headB;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                slow=headB;
                while(slow!=fast)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                tail->next=nullptr;
                return slow;
            }
        }
        //Alter Tail->next==nullptr
        tail->next=nullptr;
        return tail->next;
    }
};

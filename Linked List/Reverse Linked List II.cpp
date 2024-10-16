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
ListNode* reverse(ListNode* head)
{
    ListNode* temp=head;
    ListNode* prev=nullptr;
    while(temp)
    {
        ListNode* next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev;
}
    ListNode* reverseBetween(ListNode* head, int Left, int Right)
     {
    //     if(head==nullptr || head->next==nullptr || left==right)
    //      return head;

    //     ListNode* slow = head;
    //     ListNode* slowprev=nullptr;
    //      ListNode* lefthead=nullptr;

    //     for(int i=1;i<left;i++)
    //     {
    //         slowprev=slow;
    //         slow=slow->next;
    //     }
    //      lefthead = slowprev;
    //    ListNode* reversehead = slow;
    //     for(int i=left;i<=right;i++)
    //     {
    //         ListNode*next=slow->next;
    //         slow->next=slowprev;
    //         slowprev=slow;
    //         slow=next;
    //     }
    //     if(lefthead!=nullptr)
    //     {
    //         lefthead->next=slowprev;
    //     }
    //     else
    //     {
    //         head=slowprev;
    //     }
    //     reversehead->next=slow;
    //     return head;



            if(!head || head->next==nullptr || left==right)
            return head;

            ListNode* left=head;
            ListNode* leftPrev=nullptr;
            int cnt=1;
            while(cnt<Left)
            {
                leftPrev=left;
                left=left->next;
                cnt++;
            }
            ListNode* right=left;
            ListNode* rightNext=left;
            // cnt=1;
            while(cnt<Right)
            {
                right=right->next;
                cnt++;
            }
            rightNext=right->next;
            if(leftPrev)
            leftPrev->next=nullptr;
            right->next=nullptr;
           ListNode* newhead= reverse(left);
           if(leftPrev)
           {
             leftPrev->next=newhead;
           }
           else
           {
            head=newhead;
           }
           left->next=rightNext;
           return head;



        
    }
};

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
    while(temp!=nullptr)
    {
        ListNode* next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev;
}
    ListNode* swapPairs(ListNode* head)
     {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* temp=head;
        ListNode* dummyNode=new ListNode(-1);
        ListNode* currNode=dummyNode;
        ListNode* prev=head;
        ListNode* prevKNode=head;
            int cnt=1;
        while(temp!=nullptr)
        {
            if(cnt==2)
            {
                cnt=1;
                ListNode* nextNode=temp->next;
                temp->next=nullptr;
                ListNode* newhead=reverse(prev);
                if(prev==head)
                {
                    head=newhead;
                }
                else
                {
                    prevKNode->next=newhead;;
                }
                temp=nextNode;
                prevKNode=prev;
                prev=temp;

            }
            else
            {
                cnt++;
                temp=temp->next;
            }
        }
        if(cnt>1)
        {
            prevKNode->next=prev;
        }
        return head;
        // int cnt=0;
        // while(temp!=nullptr)
        // {
        //     cnt++;
        //     temp=temp->next;
        // }
        // temp=head;
        // for(int i=1;i<=cnt-1;i=i+2)
        // {
        //     swap(temp->val,temp->next->val);
        //     temp=temp->next;
        //     temp=temp->next;
        // }
        // return head;
    }
}; 

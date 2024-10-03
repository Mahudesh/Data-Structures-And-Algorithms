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
ListNode* reverseNode(ListNode* head)
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
     {
        ListNode* head1=l1;
        ListNode* head2=l2;
        ListNode* temp1=reverseNode(l1);
        ListNode* temp2=reverseNode(l2);
        ListNode* dummyNode=new ListNode(-1);
        ListNode* currNode=dummyNode;
        int sum=0;
        int carry=0;
        while(temp1!=nullptr || temp2!=nullptr)
        {
            if(temp1!=nullptr)
            {
                sum=sum+temp1->val;
            }
            if(temp2!=nullptr)
            {
                sum=sum+temp2->val;
            }
            ListNode* newNode=new ListNode(sum%10);
            currNode->next=newNode;
            currNode=currNode->next;
            carry=sum/10;

            sum=carry;

            if(temp1!=nullptr)
            temp1=temp1->next;
            if(temp2!=nullptr)
            temp2=temp2->next;
        }
        if(carry>0)
        {
            ListNode* newNode= new ListNode(carry);
            currNode->next=newNode;
        }

        return reverseNode(dummyNode->next);
     }
};

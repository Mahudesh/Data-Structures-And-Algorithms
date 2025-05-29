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
ListNode* reverse(ListNode* head, int& size)
{
    ListNode* prev=nullptr;
    ListNode* temp=head;
    while(temp)
    {
        size++;
        ListNode* next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev;
}
    vector<int> nextLargerNodes(ListNode* head)
    {
        int size=0;
        ListNode* newHead=reverse(head,size);
        stack<int>st;
        vector<int>nextGreater(size,0);
        ListNode* temp=newHead;
        int ind=size-1;
        while(temp)
        {
            int val=temp->val;
            while(!st.empty() && st.top()<=val)
            {
                st.pop();
            }
            if(!st.empty())
            {
                nextGreater[ind]=st.top();
            }
            st.push(val);
            ind--;
            temp=temp->next;
        }
        return nextGreater;
    }
};

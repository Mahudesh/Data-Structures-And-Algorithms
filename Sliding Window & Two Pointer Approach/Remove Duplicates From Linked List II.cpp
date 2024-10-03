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
        ListNode* dummyNode = new ListNode(-1);
        ListNode* current=dummyNode;
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr)
        {
            if(temp->next!=nullptr && temp->val==temp->next->val)
            {
                //Remove Untill All Duplicates
                while(temp->next!=nullptr && temp->val==temp->next->val)
                {
                    temp=temp->next;
                    //Remove The Last Duplicated Element
                    //Eg 1 2 2 2 3 4
                    //Remove 3rd Occurrence Of 2
                }
                temp=temp->next;
            }
            else
            {
                current->next=temp;
                current=current->next;
                temp=temp->next;
            }
        }
        current->next=nullptr;
        return dummyNode->next;
    }
};

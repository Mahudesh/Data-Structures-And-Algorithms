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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
// TreeNode* helper(vector<int>&inorder,int left, int right)
// {
//     if(left>right)
//     return nullptr;
//     int mid=(left+right)/2;
//     TreeNode* root=new TreeNode(inorder[mid]);
//     root->left=helper(inorder,left,mid-1);
//     root->right=helper(inorder,mid+1,right);
//     return root;
// }
    TreeNode* sortedListToBST(ListNode* head)
     {
        //Bruteforce
        // vector<int>inorder;
        // ListNode* temp=head;
        // while(temp!=nullptr)
        // {
        //     inorder.push_back(temp->val);
        //     temp=temp->next;
        // }
        // return helper(inorder,0,inorder.size()-1);

        //Optimal
        if(head==nullptr)
        return nullptr;;
        if(head->next==nullptr)
        {
            return new TreeNode(head->val);
        }
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev_tail=head;
        //Find Middle Element Which Is Ultimately A Root
        while(fast!=nullptr && fast->next!=nullptr)
        {
            prev_tail=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        //Make The Root Of The Tree By Using The Middle Element
        TreeNode* root=new TreeNode(slow->val);
        //Make The Prev->next As Nullptr And Return Root's Left As From Head To Prev
        //Since Head To Prev Containing All The Nodes Should Be On The Left Of Binary Search Tree
        prev_tail->next=nullptr;
        root->left=sortedListToBST(head);
        //Now For Root's Right As From slow->next To End
        //Since Slow->next To End Containing All The Nodes Should Be On The Right Side Of BST
        root->right=sortedListToBST(slow->next);
        return root;
    }
};

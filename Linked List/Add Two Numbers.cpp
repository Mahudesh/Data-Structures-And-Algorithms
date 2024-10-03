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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
     {
        // ListNode* temp1=l1;
        // ListNode* temp2=l2;
        // //Keep Dummy Node To Keep Track Of Head
        // ListNode* dummyNode=new ListNode(-1);
        // ListNode* current=dummyNode;
        // int sum=0;
        // int carry=0;
        // //Traverse Untill Both The List Reaches Null Pointer
        // while(temp1!=nullptr || temp2!=nullptr)
        // {
        //     //If Not A Nullptr Then Add The Data
        //     if(temp1!=nullptr)
        //     {
        //         sum=sum+temp1->val;
        //     }
        //     //If Not A Nullptr Then Add The Data
        //     if(temp2!=nullptr)
        //     {
        //         sum=sum+temp2->val;
        //     }
        //     //Create A New Node And Add The Sum%10 To Retrieve The Last Element If There Are Any Carry
        //     ListNode* newnode=new ListNode(sum%10);
        //     //Find The Carry By Doing Sum%10
        //     carry=sum/10;
        //     //Connect The Current Node To NewNode To Form A List
        //     current->next=newnode;
        //     current=newnode;
        //     //If Any Carry Then Add It To Sum
        //     sum=carry;

        //     if(temp1!=nullptr) temp1=temp1->next;
        //     if(temp2!=nullptr) temp2=temp2->next;
        // }
        // //After Doing Sum Operation If You Find Any Carry Left Out Then Add It To The New Node
        // if(carry>0)
        // {
        //     ListNode* newnode=new ListNode(carry);
        //     current->next=newnode;
        //     newnode->next=nullptr;
        // }
        // //Return The DummyNode Next As Head
        // return dummyNode->next;

    //     ListNode* temp1=l1;
    //     ListNode* temp2=l2;
    //     ListNode* dummyNode=new ListNode(-1);
    //     ListNode* current=dummyNode;
    //     int sum=0,carry=0;
    //     while(temp1!=nullptr || temp2!=nullptr)
    //     {
    //         if(temp1!=nullptr)
    //         {
    //             sum=sum+temp1->val;
    //         }
    //         if(temp2!=nullptr)
    //         {
    //             sum=sum+temp2->val;
    //         }

    //         ListNode* newnode=new ListNode(sum%10);
    //         carry=sum/10;

    //         sum=carry;

    //         current->next=newnode;
    //         current=newnode;

    //         if(temp1!=nullptr) temp1=temp1->next;
    //         if(temp2!=nullptr) temp2=temp2->next;
    //     }
    //     if(carry>0)
    //     {
    //         ListNode* newnode=new ListNode(carry);
    //         current->next=newnode;
    //     }
    //    return dummyNode->next;

        
    }
};

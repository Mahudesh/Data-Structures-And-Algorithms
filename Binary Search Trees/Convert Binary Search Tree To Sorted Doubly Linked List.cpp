class Solution {
  public:
  void inorder(Node* root,Node*& prev, Node*& head)
  {
      if(!root)
      return;
      
      inorder(root->left,prev,head);
      if(prev==nullptr)
      {
          prev=root;
          head=prev;
      }
      else
      {
          prev->right=root;
          root->left=prev;
          prev=root;
      }
      inorder(root->right,prev,head);
  

  }
    Node* bToDLL(Node* root)
    {
        // code here
        Node* head=nullptr;
        Node* prev=nullptr;
        inorder(root,prev,head);
        return head;
        
    }
};

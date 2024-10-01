
class Solution{
  public:
//   void inorderfunc(Node* root, vector<Node*>&arr)
//   {
//       if(!root)
//       return;
//       inorderfunc(root->left,arr);
//       arr.push_back(root);
//       inorderfunc(root->right,arr);
//   }
//   int findUpperBound(vector<Node*>&arr, int x)
//   {
//       int low=0;
//       int high=arr.size()-1;
//       while(low<=high)
//       {
//           int mid=(low+high)/2;
//           if(arr[mid]->data>x)
//           {
//               high=mid-1;
//           }
//           else
//           {
//               low=mid+1;
//           }
//       }
//       return low;
//   }
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node* successor=nullptr;
    void func(Node* root, int x)
    {
        if(!root)
        return;
        if(root->data>x)
        {
            successor=root;
            func(root->left,x);
        }
        else
        {
            func(root->right,x);
        }
    }
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //BruteForce
        // vector<Node*>inorder;
        // inorderfunc(root,inorder);
        // int val=x->data;
        // int ind=findUpperBound(inorder,val);
        // // ind++;
        // if(ind>=inorder.size())
        // return nullptr;
        // return inorder[ind];
        //Optimal
        func(root,x->data);
        return successor;
    }

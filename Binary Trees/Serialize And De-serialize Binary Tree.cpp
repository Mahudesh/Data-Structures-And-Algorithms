/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string ans="";
        if(!root)
        return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp==nullptr)
            {
                ans.append("#,");
            }
            else
            {
                ans=ans+to_string(temp->val)+",";
                q.push(temp->left);
                q.push(temp->right);
            }
            
            
        }
        // cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
     {
        // TreeNode* d=new TreeNode(-1);
        // return d;
        if(data.length()==0)
        return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")
            {
                temp->left=nullptr;
            }
            else
            {
                TreeNode* newNode=new TreeNode(stoi(str));
                temp->left=newNode;
                q.push(newNode);
            }
            getline(s,str,',');
            if(str=="#")
            {
                temp->right=nullptr;
            }
            else
            {
                TreeNode* newNode=new TreeNode(stoi(str));
                temp->right=newNode;
                q.push(newNode);
            }
        }  
        return root;      
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

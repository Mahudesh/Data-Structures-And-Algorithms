#GFG
class Solution{
public:

    void create_tree(node* root0, vector<int> &vec)
    {
        //Your code goes here
        int i=1;
        queue<node*>q;
        q.push(root0);
        while(!q.empty() && i<vec.size())
        {
            node* temp=q.front();
            q.pop();
            if(temp->left==NULL)
            {
                temp->left=newNode(vec[i]);
                i++;
                q.push(temp->left);
            }
            if(i<vec.size() && temp->right==NULL)
            {
                temp->right=newNode(vec[i++]);
                q.push(temp->right);
            }
           
        }
    }

};

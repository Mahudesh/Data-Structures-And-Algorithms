 int verticalWidth(Node* root) 
    {
        // code here
        if(!root)
        return 0;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        map<int,int>Map;
        while(!q.empty())
        {
            Node* temp=q.front().first;
            int vertical=q.front().second;
            q.pop();
            if(Map.find(vertical)==Map.end())
            Map[vertical]=temp->data;
            if(temp->left)
            {
                q.push({temp->left,vertical-1});
            }
            if(temp->right)
            {
                q.push({temp->right,vertical+1});
            }
        }
        return Map.size();

lass Solution {
  public:
    vector <int> bottomView(Node *root) {
        
        // Your Code Here
        queue<pair<Node*,int>>q;
    map<int,int>Map;

    q.push({root,0});
    while(!q.empty())
    {
        auto todo=q.front();
        q.pop();
        Node* temp=todo.first;
        int vertical=todo.second;

        
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
    vector<int>ans;
    for(auto pair: Map)
    {
        ans.push_back(pair.second);
    }
    return ans;
    }
};

Solution {
  public:
  vector<int> topoSort(int v, vector<vector<int>> &adj)
{
    vector<int>topo;
    vector<int>inDegree(v,0);
    for(int i=0;i<v;i++)
    {
        for(auto ele : adj[i])
        {
            inDegree[ele]++;
        }
    }
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(inDegree[i]==0)
        q.push(i);
    }

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        topo.push_back(node);
        for(auto adjacent : adj[node])
        {
            inDegree[adjacent]--;
            if(inDegree[adjacent]==0)
            q.push(adjacent);
        }
    }
    return topo;
}
    string findOrder(vector<string> &dictionary) 
    {
        // code here
        int n=dictionary.size();
        unordered_set<char>st;
        for(int i=0;i<n;i++)
        {
            for(char ch : dictionary[i])
            st.insert(ch);
        }
        int k=st.size();
        
        //If Alien Dictionary Contains 'a' 'b' 'x' 'y'
        //I Created Only For Consecutive Indexing Like 0,1,2,3,4 In adj List
        //But 'x'-'a' Will Give 23 Which Is Index Out Of Bound List
        //Index Out Of Bound Error Happens
        //To Neglect That Kind Of Errors
        //Map Stores Index Of Each Character In A Consecutive Manner
        //Hence If I Create adj[4] 0,1,2,3 Index Will Be Occupied
         unordered_map<char, int> charIndex;
         unordered_map<int, char> indexToChar;
         int index = 0;
    
        for (char ch : st) 
        {
            charIndex[ch] = index;
            indexToChar[index] = ch;
            index++;
        }
        // vector<int>adj[k];
        vector<vector<int>>adj(k);
        for(int i=0;i<n-1;i++)
        {
            string s1=dictionary[i];
            string s2=dictionary[i+1];
            
            int minLen=min(s1.length(),s2.length());
            bool found=false;
            for(int ptr=0;ptr<minLen;ptr++)
            {
                if(s1[ptr]!=s2[ptr])
                {
                    adj[charIndex[s1[ptr]]].push_back(charIndex[s2[ptr]]);
                    found=true;
                    break;
                }
            }
            if(!found && s1.length()>s2.length())
            return "";
        }
        vector<int>topo=topoSort(k,adj);
        if(topo.size()!=k)
        return "";
        string res="";
        for(int i=0;i<topo.size();i++)
        {
            res=res+(indexToChar[topo[i]]);
        }
        return res;
    }

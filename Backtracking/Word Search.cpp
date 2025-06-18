    class Solution {
    public:
    bool helper(int r, int c, int ind, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited,int n, int m)
    {
        if(ind==word.length())
        return true;

        if(r<0 || c<0 || r>=n || c>=m || visited[r][c]==true || board[r][c]!=word[ind])
        return false;

        visited[r][c]=true;

        bool left=helper(r,c-1,ind+1,board,word,visited,n,m);
        bool right=helper(r,c+1,ind+1,board,word,visited,n,m);
        bool top=helper(r-1,c,ind+1,board,word,visited,n,m);
        bool down=helper(r+1,c,ind+1,board,word,visited,n,m);

        visited[r][c]=false;

        if(left || right || top || down)
        return true;
        return false;

    }   
        bool exist(vector<vector<char>>& board, string word)
        {
            // Check For Every Word And Every Cell Recursively

            int ind=0;
            int n=board.size();
            int m=board[0].size();
            vector<vector<bool>>visited(n, vector<bool>(m,false));

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(helper(i,j,ind,board,word,visited,n,m))
                    return true;
                }
            }
            return false;
        }
    };

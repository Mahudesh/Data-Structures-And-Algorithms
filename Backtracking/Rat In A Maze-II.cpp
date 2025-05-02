
class Solution {
  public:
  void helper(int n, int r, int c, vector<string>& ans, string& temp, vector<vector<int>>& maze,
  vector<vector<bool>>&visited)
  {
      if(r==n-1 && c==maze[0].size()-1)
      {
          ans.push_back(temp);
          return;
      }
      if(r<0 || c<0 || r>=maze.size() || c>=maze[0].size())
      return;
      
      if(visited[r][c]==true)
      return;
      

        visited[r][c]=true;
      
      if(maze[r][c]==1)
      {
      
          temp.push_back('D');
          helper(n,r+1,c,ans,temp,maze,visited);
          temp.pop_back();
          
          temp.push_back('U');
          helper(n,r-1,c,ans,temp,maze,visited);
          temp.pop_back();
          
          temp.push_back('L');
          helper(n,r,c-1,ans,temp,maze,visited);
          temp.pop_back();
          
          temp.push_back('R');
          helper(n,r,c+1,ans,temp,maze,visited);
          temp.pop_back();
          
      }
           visited[r][c]=false;
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string>ans;
        string temp="";
        int n=maze.size();
        vector<vector<bool>>visited(n, vector<bool>(n,false));
        helper(n,0,0,ans,temp,maze,visited);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

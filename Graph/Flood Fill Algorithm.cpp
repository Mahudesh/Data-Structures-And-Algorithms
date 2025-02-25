int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
void dfs(int x, int y, vector<vector<int>>& image,vector<vector<int>>& ans, int newColor, int initialColour)
{
    ans[x][y]=newColor;
    int n=image.size();
    int m=image[0].size();
    for(int d=0;d<4;d++)
    {
        int nxtRow=x+dx[d];
        int nxtCol=y+dy[d];
        //Last 2 Conditions
        //Question Should Contain Same Initial Colour
        //That New Coordinate Should Not Be Visited Which Means It Should Not Have New Colour Painted
        if(nxtRow>=0 && nxtCol>=0 && nxtRow<n && nxtCol<m && image[nxtRow][nxtCol]==initialColour && ans[nxtRow][nxtCol]!=newColor)
        {
            dfs(nxtRow,nxtCol,image,ans,newColor,initialColour);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int initialColour=image[x][y];
    vector<vector<int>>ans=image;
    dfs(x,y,image,ans,newColor,initialColour);
    return ans;
}

Problem Statement



You are given a directed graph in the form of an adjacency matrix. Your task is to determine the type of connectivity the graph exhibits. A graph may fall into one of the following categories:



Strongly Connected: There is a directed path from any node to every other node and vice versa.



Unilaterally Connected: For every pair of vertices u and v, there is at least one directed path between them in one direction (either from u to v or from v to u), but not necessarily both.

Weakly Connected: The directed graph becomes connected when its edges are treated as undirected.



Your program should read the graph and print the appropriate type of connectivity.

Input format :
The first line contains an integer n, representing the number of nodes in the graph.

The next n lines each contain n integers, where each integer is either 0 or 1, representing the adjacency matrix of the graph:

1 at position (i, j) indicates a directed edge from node i to node j.

0 indicates no edge.

Output format :
The output consists of a single line containing one of the following strings, based on the type of connectivity of the graph: "Strongly Connected", "Unilaterally Connected", or "Weakly Connected".



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the given test cases will fall under the following constraints:

1 ≤ N ≤ 6

Path matrix elements are either 0 or 1.

Sample test cases :
Input 1 :
3
1 1 1 
1 1 1
1 1 1
Output 1 :
Strongly Connected
Input 2 :
3
0 1 1 
0 0 1
0 0 0
Output 2 :
Unilaterally Connected
Input 3 :
3
0 1 0
0 0 0
0 1 0
Output 3 :
Weakly Connected

// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited)
{
    visited[node]=true;
    for(int adjnode=0;adjnode<(int)graph.size();adjnode++)
    {
        if(graph[node][adjnode]==1 && !visited[adjnode])
        dfs(adjnode,graph,visited);
    }
}
bool isConnected(vector<vector<int>>& graph)
{
    int n=graph.size();
    vector<bool>visited(n,false);
    dfs(0,graph,visited);
    for(auto ele : visited)
    {
        if(!ele)
        return false;
    }
    return true;
}
vector<vector<int>> transpose(vector<vector<int>>& graph)
{
    int n=graph.size();
    vector<vector<int>>rev(n, vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            rev[j][i]=graph[i][j];
        }
    }
    return rev;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>mat(n, vector<int>(n));
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
            c+=mat[i][j];
        }
    }
    vector<vector<int>>rev=transpose(mat);
    if(isConnected(mat) && isConnected(rev))
    {
        cout<<"Strongly Connected";
    }
    else if(isConnected(mat) || isConnected(rev))
    {
        cout<<"Weakly Connected";
    }
    else
    {
        cout<<"Weakly Connected";
    }
    // if(c==n*n || c==(n*n)-n)
    // cout<<"Strongly Connected";
    // else
    // cout<<"Weakly Connected";
}

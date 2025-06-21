#include<bits/stdc++.h>
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
Node* helper(Node* node, unordered_map<Node*,Node*>& Map)
{
    if(Map.find(node)!=Map.end())
    return Map[node];
    Node* copy=new Node(node->val);
    // Create And Store A Copy Of OldNode->NewNode
    Map[node]=copy;
    for(Node* adj : node->neighbors)
    {
        // Connect All Copy Nodes To Their Neighbours Of Original Node By Creating Their Copy In DFS
        copy->neighbors.push_back(helper(adj,Map));
    }
    return copy;
}
    Node* cloneGraph(Node* node) {

        // Use The HashMap + DFS
      unordered_map<Node*,Node*>Map;
      if(!node)
      return node;
       return helper(node,Map);
    }
};

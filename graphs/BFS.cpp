
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> ans;
    void helper(int V, vector<int> adj[], vector<int>& vis)
    {
        
        queue<int> q1;
        q1.push(0);
        vis[0]=1;
        
        while(!q1.empty())
        {
            int front = q1.front();
            q1.pop();
            ans.push_back(front);
            
            for(auto i : adj[front])
            {
                if(vis[i]!=1)
                
                {
                    q1.push(i);
                    vis[i]=1;
                }
                    
            }
        }
        
       
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> vis(V,0);
        helper(V,adj,vis);
       return ans;
    }
};

int main() {
    int V = 7; // Number of vertices

    // Create an adjacency list for a sample graph
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(5);
    adj[2].push_back(6);

    Solution ob;
    vector<int> result = ob.bfsOfGraph(V, adj);

    cout << "Breadth-First Traversal of the graph: ";
    for (int vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}

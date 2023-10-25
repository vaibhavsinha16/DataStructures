#include <bits/stdc++.h>
using namespace std;
int n =0,m=0;
class graph
{
    public:
    
    //direction = 0->undirected
    void addedge(vector<int> adj[],int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if(direction==0)
        {
            adj[v].push_back(u);
        }
    }
    
    void printgraph(vector<int> adj[])
    {
        for(int i=0;i<n;i++)
        {
            cout<<i<<"->";
            for(auto j : adj[i])
            {
                cout<<j<<",";
            }
            cout<<endl;
            
        }
    }
};


int main() {
      
    cout<<"enter number of nodes";
    cin>>n;
    cout<<"enter number of edges";
    cin>>m;
    vector<int> adj[m];
    graph g;
      
    for(int i =0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        g.addedge(adj,u,v,0);
    }
	
	g.printgraph(adj);
	return 0;
}
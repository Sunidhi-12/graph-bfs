/******************************************************************************

BFS of graph

*******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<int> adj[n+1];

    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    //printing adjacents of 
    for(int i=1;i<n+1;i++)
    {
        cout<<i<<": ";
        for(auto x: adj[i])
        {
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    int vis[n+1]={0};
    
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                cout<<node<<" ";
                
                for(auto x:adj[node])
                {
                    if(!vis[x])
                    {
                        q.push(x);
                        vis[x]=1;
                    }
                }
            }
        }
    }
    return 0;
}

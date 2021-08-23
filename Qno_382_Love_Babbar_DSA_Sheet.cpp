//Question No. 382 Love Babbar DSA Sheet
//Question :- Minimum edges to reverse to make path from a source to a destination

//Question Article :- https://www.geeksforgeeks.org/minimum-edges-reverse-make-path-source-destination/

//For Referance video :- https://youtu.be/porShXfpPqA
// This question is based on djistra algorithm

#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ipair;

void modify_adjacency_list(int V, vector<int> adj[], vector<ipair> modified_adj[])
{
    int u, wt=0, rev_wt=1;
    for(int i=0; i<V; i++)
    {
        u = i;
        for(int v : adj[i])
        {
            modified_adj[u].push_back({v, wt});
            modified_adj[v].push_back({u, rev_wt});
        }
    }
}

int djikstra(int src, int dest, int V, vector<ipair> modified_adj[])
{
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;

    vector<int> dist(V, INT_MAX);

    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty())
    {
        auto temp = pq.top();
        int u = temp.second;
        pq.pop();

        for(auto x : modified_adj[u])
        {
            int v = x.first;
            int wt = x.second;

            if(dist[v] > dist[u]+wt)
            {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[dest];
}

void solve_the_problem(int V, vector<int> adj[], int src, int dest)
{
    vector<ipair> modified_adj[V];
    
    //modifying adjacency list

    modify_adjacency_list(V, adj, modified_adj);

    //djikstra algorithm

    int result = djikstra(src, dest, V, modified_adj);

    if(result != INT_MAX)
    {
        cout<<result;
    }    
    else
    {
        cout<<-1;
    }
}

//Driver Code
int main()
{
    int V, E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0; i<E; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int src, dest;
    cin>>src>>dest;
    vector<int> madj[V];

    solve_the_problem(V, adj, src, dest);
    return 0;
}

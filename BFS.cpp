#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<queue>
using namespace std;

void prepareAdjset(unordered_map<int,set<int>>&adjset, vector<pair<int,int>>&edges)
{
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjset[u].insert(v);
        adjset[v].insert(u);
    }
}

void bfs(unordered_map<int,set<int>>&adjset, unordered_map<int,bool>&visited, vector<int>&ans, int node)
{
    queue <int> q;
    q.push(node);
    visited[node] = 1;
    
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        
        ans.push_back(frontNode);
        for(auto i: adjset[frontNode])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int>BFS(int vertex, vector<pair<int,int>>edges)
{
    vector<int>ans;
    unordered_map<int,bool>visited;
    unordered_map<int,set<int>>adjset;
    
    prepareAdjset(adjset,edges);
    
    for(int i = 0; i < vertex; i++)
    {
        if(!visited[i])
        {
            bfs(adjset,visited,ans,i);
        }
    }
    return ans;
}

int main()
{
    int vertex, edgesCount;
    cout << "Enter number of vertices: ";
    cin >> vertex;

    cout << "Enter number of edges: ";
    cin >> edgesCount;

    vector<pair<int, int>> edges;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edgesCount; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<int> result = BFS(vertex, edges);

    cout << "\nBFS Traversal: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

// static

// int main()
// {
//     int vertex = 5;
//     vector<pair<int, int>> edges = {
//         {0, 1}, {0, 2}, {1, 3}, {2, 4}
//     };

//     vector<int> result = BFS(vertex, edges);

//     cout << "BFS Traversal: ";
//     for (int node : result)
//     {
//         cout << node << " ";
//     }
//     cout << endl;

//     return 0;
// }

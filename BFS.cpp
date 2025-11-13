#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void adjacencylist(int vertex, const vector<vector<int>>&edges, unordered_map<int, unordered_set<int>>&adjlist)
{
    
    // for(int i = 0; i < vertex; i++)
    //     adjlist[i];
        
    
    // creating adjacency list
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjlist[u].insert(v);
    }
    
    // printing adjacenecy list
    // adjlist : map<int,set<int>>adjlist
    // list of : ( _ : _, _, _ ) such list
    // so it is used to access elements of adjlist, adjlist has 2 elements (int, list of int)
    // so it.first is int & it.second is that list
    // so br is accessing each element of that list
    
    cout << "Adjacency list: \n";
    for(auto &it: adjlist)
    {
        cout << it.first << " -> ";
        for(auto &br: it.second)
        {
            cout << br << " ";
        }
        cout << endl;
    }
}

void bfs(unordered_map<int, unordered_set<int>>&adjlist, unordered_map<int,bool>&visited, vector<int>&ans, int node)
{
    queue<int>q;
    q.push(node);
    visited[node] = 1;
    
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        
        ans.push_back(frontNode);
        
        for(auto &i: adjlist[frontNode])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<vector<int>>&edges)
{
    unordered_map<int, unordered_set<int>>adjlist;
    unordered_map<int,bool>visited;
    vector<int>ans;
    adjacencylist(vertex, edges,adjlist);
    
    for(auto &it: adjlist)
    {
        int i = it.first;
        if(!visited[i])
        {
            bfs(adjlist,visited,ans,i);
        }
    }
    return ans;
}

int main()
{
    int vertex, n;
    vector<vector<int>>edges;
    
    cout << "Enter total no.of vertex: ";
    cin >> vertex;
    cout << "Enter total no.of edges :";
    cin >> n;
    cout << "Enter all the edges: \n";
    for(int  i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u,v});
    }
    
    vector <int> result = BFS(vertex,edges);
    cout << "\nBFS: ";
    for(auto &i: result)
    {
        cout << i << "  ";
    }
    return 0;
}

/*
for sorted output
simply replace unordered_map with map and unordered_set with 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void adjacencylist(int vertex, const vector<vector<int>>& edges, map<int, set<int>>& adjlist)
{
    // Create adjacency list
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].insert(v);
    }

    cout << "Adjacency list:\n";
    for (auto &it : adjlist)
    {
        cout << it.first << " -> ";
        for (auto &br : it.second)
        {
            cout << br << " ";
        }
        cout << endl;
    }
}

void bfs(map<int, set<int>>& adjlist, unordered_map<int, bool>& visited, vector<int>& ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for (auto &i : adjlist[frontNode]) // set → always gives sorted neighbors
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<vector<int>>& edges)
{
    map<int, set<int>> adjlist;  // keeps everything sorted
    unordered_map<int, bool> visited;
    vector<int> ans;

    adjacencylist(vertex, edges, adjlist);

    for (auto &it : adjlist)
    {
        int i = it.first;
        if (!visited[i])
        {
            bfs(adjlist, visited, ans, i);
        }
    }
    return ans;
}

int main()
{
    int vertex, n;
    vector<vector<int>> edges;

    cout << "Enter total no.of vertex: ";
    cin >> vertex;
    cout << "Enter total no.of edges: ";
    cin >> n;

    cout << "Enter all the edges: \n";
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<int> result = BFS(vertex, edges);
    cout << "\nBFS: ";
    for (auto &i : result)
    {
        cout << i << "  ";
    }
    cout << endl;
    return 0;
}


*/

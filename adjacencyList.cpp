#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void adjacencylist(int n, vector<vector<int>>&edges)
{
    unordered_map<int, unordered_set<int>> adjlist;
    
    // for(int i = 0; i < n; i++)
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
    
    adjacencylist(vertex, edges);
    return 0;
}

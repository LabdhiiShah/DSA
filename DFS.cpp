#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

void dfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, int node, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;

    for (auto i : adjList[node])
    {
        if (!visited[i])
        {
            dfs(adjList, visited, i, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adjList;

    // Build adjacency list
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int w = edges[i][1];

        adjList[u].push_back(w);
        adjList[w].push_back(u);
    }

    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    // Run DFS for all nodes that appear in edges
    for (auto &p : adjList)
    {
        int node = p.first;
        if (!visited[node])
        {
            vector<int> component;
            dfs(adjList, visited, node, component);
            ans.push_back(component);
        }
    }

    return ans;
}

int main()
{
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> edges(e, vector<int>(2));
    cout << "Enter each edge (u v):\n";
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> result = depthFirstSearch(v, e, edges);

    // Print only the components
    cout << "\nDFS Traversal (components):\n";
    for (auto &component : result)
    {
        for (int node : component)
            cout << node << " ";
        cout << endl;
    }

    return 0;
}

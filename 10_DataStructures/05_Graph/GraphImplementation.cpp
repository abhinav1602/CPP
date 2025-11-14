/**
 * @file GraphImplementation.cpp
 * @brief Simple adjacency list graph with BFS & DFS.
 * @date 2025-11-15
 */

#include <iostream>
#include <vector>
#include <queue>

class Graph {
    std::vector<std::vector<int>> adj;
public:
    explicit Graph(int n) : adj(n) {}
    void addEdge(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); }
    void bfs(int start) const {
        std::vector<bool> vis(adj.size());
        std::queue<int> q; q.push(start); vis[start] = true;
        std::cout << "BFS: ";
        while(!q.empty()) {
            int u = q.front(); q.pop();
            std::cout << u << ' ';
            for (int v : adj[u]) if(!vis[v]) { vis[v]=true; q.push(v); }
        }
        std::cout << '\n';
    }
    void dfsUtil(int u, std::vector<bool>& vis) const {
        vis[u] = true; std::cout << u << ' ';
        for (int v : adj[u]) if (!vis[v]) dfsUtil(v, vis);
    }
    void dfs(int start) const {
        std::vector<bool> vis(adj.size());
        std::cout << "DFS: ";
        dfsUtil(start, vis);
        std::cout << '\n';
    }
};

int main() {
    Graph g(6);
    g.addEdge(0,1); g.addEdge(0,2); g.addEdge(1,3); g.addEdge(2,4); g.addEdge(4,5);
    g.bfs(0);
    g.dfs(0);
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 GraphImplementation.cpp -o GraphImplementation */


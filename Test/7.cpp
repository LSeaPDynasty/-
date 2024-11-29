#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;
class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v);
    void dfsTree(int startVertex);
    void bfsTree(int startVertex);

private:
    int V; 
    unordered_map<int, vector<int>> graph; 
    unordered_map<int, int> parent; 

    void dfs(int vertex, vector<bool>& visited);
    void bfs(int vertex, vector<bool>& visited);
    void printTree(const unordered_map<int, vector<int>>& tree, const string& name);
};

Graph::Graph(int vertices) : V(vertices) {}

void Graph::addEdge(int u, int v) {
    graph[u].push_back(v);
    
}

void Graph::dfs(int vertex, vector<bool>& visited) {
    visited[vertex] = true;
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            parent[neighbor] = vertex;
            dfs(neighbor, visited);
        }
    }
}

void Graph::dfsTree(int startVertex) {
    vector<bool> visited(V, false);
    parent.clear();
    dfs(startVertex, visited);

    unordered_map<int, vector<int>> dfsTree;
    for (const auto& pair : parent) {
        if (pair.second != -1) { 
            if (pair.second != 1) {
                dfsTree[pair.second].push_back(pair.first);
            } else {
                dfsTree[pair.second].emplace_back(pair.first);
            }
        }
    }

    
    int root = startVertex;
    while (parent.find(root) != parent.end() && parent[root] != -1) {
        root = parent[root];
    }
    
    printTree(dfsTree, "DFS");
}

void Graph::bfs(int vertex, vector<bool>& visited) {
    queue<int> queue;
    visited[vertex] = true;
    queue.push(vertex);
    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                parent[neighbor] = current;
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
}

void Graph::bfsTree(int startVertex) {
    vector<bool> visited(V, false);
    parent.clear();
    bfs(startVertex, visited);

    unordered_map<int, vector<int>> bfsTree;
    for (const auto& pair : parent) {
        if (pair.second != -1) { 
            if (bfsTree.find(pair.second) == bfsTree.end()) {
                bfsTree[pair.second] = vector<int>{pair.first};
            } else {
                bfsTree[pair.second].push_back(pair.first);
            }
        }
    }


    printTree(bfsTree, "BFS");
}

void Graph::printTree(const unordered_map<int, vector<int>>& tree, const string& name) {
    cout << name << " Tree:" << endl;
    for (const auto& pair : tree) {
        cout << pair.first << " -> ";
        for (int child : pair.second) {
            cout << child << " ";
        }
        cout << endl;
    }
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0); 
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    int startVertex = 2;
    g.dfsTree(startVertex);
    g.bfsTree(startVertex);

    return 0;
}
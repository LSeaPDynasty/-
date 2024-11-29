#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    int V;
    list<int> *adj;
    vector<int> inDegree;

public:
    Graph(int V);
    void addEdge(int v, int w); 
    void topologicalSort(); 
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
    inDegree.resize(V, 0);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    inDegree[w]++;
}

void Graph::topologicalSort() {
    stack<int> S; 
    int count = 0; 


    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            S.push(i);
        }
    }

    while (!S.empty()) {
        int vj = S.top();
        S.pop();
        cout << vj << " ";
        count++;

        for (auto it = adj[vj].begin(); it != adj[vj].end(); ++it) {
            inDegree[*it]--; 
            if (inDegree[*it] == 0) {
                S.push(*it); 
            }
        }
    }

    if (count != V) {
        cout << "\n图中存在回路";
    } else {
        cout << "\n拓扑排序完成";
    }
}

int main() {
    int V = 6; 
    Graph g(V);
 
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

    return 0;
}
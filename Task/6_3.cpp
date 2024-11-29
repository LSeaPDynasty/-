/*
3����ͼ��ʾ�Ĵ�Ȩ����ͼ���밴Ҫ��ش����⣺
1��������ͼ���ڽӾ��󣬲�������ķ�㷨������С��������
�ڽӾ���
0 6 0 0 5 1
6 0 3 0 0 5
0 3 0 6 0 6
0 0 6 0 2 4
5 0 0 2 0 5
1 5 6 4 5 0

2��������ͼ���ڽӱ�������³˹�����㷨������С��������


*/
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();
struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;
};
void primMST(vector<vector<int>>& graph, int V) {
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; ++count) {
        int u = -1;
        for (int i = 0; i < V; ++i) {
            if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        inMST[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "����ķ��С�������ıߺ�Ȩ�أ�" << endl;
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << " : " << graph[parent[i]][i] << endl;
    }
}


bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(vector<int>& parent, int i) {
    if (parent[i] == i) return i;
    return find(parent, parent[i]);
}

void unionSets(vector<int>& parent, int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void kruskalMST(Graph& graph) {
    vector<Edge> result;
    sort(graph.edges.begin(), graph.edges.end(), compare);

    vector<int> parent(graph.V);
    for (int i = 0; i < graph.V; ++i) {
        parent[i] = i;
    }

    int e = 0;
    for (int i = 0; e < graph.V - 1 && i < graph.E; ++i) {
        Edge next_edge = graph.edges[i];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result.push_back(next_edge);
            unionSets(parent, x, y);
            e++;
        }
    }

    cout << "��³˹������С�������ıߺ�Ȩ�أ�" << endl;
    for (Edge& edge : result) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
}

int main() {
    int V = 6;
    vector<vector<int>> graph = {
        {0, 6, 0, 0, 5, 1},
        {6, 0, 3, 0, 0, 5},
        {0, 3, 0, 6, 0, 6},
        {0, 0, 6, 0, 2, 4},
        {5, 0, 0, 2, 0, 5},
        {1, 5, 6, 4, 5, 0}
    };

    primMST(graph, V);

    int Vs = 6;
    int E = 11;

    Graph graphs = {Vs, E};

    graphs.edges = {
        {0, 1, 6}, {0, 4, 5}, {0, 5, 1},
        {1, 2, 3}, {1, 5, 5},
        {2, 3, 6}, {2, 5, 6},
        {3, 4, 2}, {3, 5, 4},
        {4, 5, 5}
    };

    kruskalMST(graphs);


    return 0;
}
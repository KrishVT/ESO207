#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
};

int findParent(map<int, int>& parent, int u) {
    if (parent[u] != u)
        parent[u] = findParent(parent, parent[u]);
    return parent[u];
}

void unionSet(map<int, int>& parent, int u, int v) {
    int pu = findParent(parent, u);
    int pv = findParent(parent, v);
    if (pu != pv)
        parent[pu] = pv;
}

int kargerMinCut(vector<Edge>& edges, int V) {
    int minCut = edges.size();
    srand(time(0));

    for (int i = 0; i < V * V; i++) {
        map<int, int> parent;
        for (int j = 0; j < V; j++) parent[j] = j;

        int vertices = V;
        vector<Edge> tempEdges = edges;

        while (vertices > 2) {
            int idx = rand() % tempEdges.size();
            int u = tempEdges[idx].u;
            int v = tempEdges[idx].v;

            if (findParent(parent, u) == findParent(parent, v)) continue;
            unionSet(parent, u, v);
            vertices--;
        }

        int cut = 0;
        for (Edge e : edges)
            if (findParent(parent, e.u) != findParent(parent, e.v))
                cut++;
        minCut = min(minCut, cut);
    }
    return minCut;
}

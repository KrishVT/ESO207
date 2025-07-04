#include <bits/stdc++.h>
using namespace std;

struct Edge {
    string u, v;
    int w;
};

unordered_map<string, int> bellman_ford(const vector<Edge>& edges,
                                        const vector<string>& vertices,
                                        const string& src) {
    unordered_map<string, int> dist;
    for(const auto& v : vertices) dist[v] = INT_MAX;
    dist[src] = 0;

    for(size_t i = 0; i < vertices.size() - 1; ++i) {
        for(const auto& e : edges) {
            if(dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v])
                dist[e.v] = dist[e.u] + e.w;
        }
    }
    return dist;
}

int main() {
    vector<Edge> edges = {{"A","B",1},{"B","C",3},{"A","C",10},{"C","D",-4}};
    vector<string> vertices = {"A","B","C","D"};
    auto dist = bellman_ford(edges, vertices, "A");
    for(const auto& [v, d] : dist) cout << v << ": " << d << "\n";
    return 0;
}
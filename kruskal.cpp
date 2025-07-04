#include <bits/stdc++.h>
#include "disjoint_set.hpp"
using namespace std;

struct Edge {
    string u, v;
    int w;
};

vector<Edge> kruskal(const vector<string>& vertices, vector<Edge> edges) {
    DisjointSet<string> ds(vertices);
    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) { return a.w < b.w; });
    vector<Edge> mst;
    for(const auto& e : edges) {
        if(ds.find(e.u) != ds.find(e.v)) {
            mst.push_back(e);
            ds.unite(e.u, e.v);
        }
    }
    return mst;
}

int main() {
    vector<string> V = {"A","B","C","D"};
    vector<Edge> edges = {{"A","B",2},{"A","C",3},{"B","C",1},{"B","D",4},{"C","D",5}};
    auto mst = kruskal(V, edges);
    for(const auto& e : mst) cout << e.u << " - " << e.v << " : " << e.w << "\n";
    return 0;
}
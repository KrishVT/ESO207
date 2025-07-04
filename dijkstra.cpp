#include <bits/stdc++.h>
using namespace std;

using Node = string;
using Edge = pair<Node, int>;
using Graph = unordered_map<Node, vector<Edge>>;

unordered_map<Node, int> dijkstra(const Graph& graph, const Node& start) {
    unordered_map<Node, int> dist;
    for(const auto& kv : graph) dist[kv.first] = INT_MAX;
    dist[start] = 0;
    using State = pair<int, Node>;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u]) continue;
        for(const auto& [v, w] : graph.at(u)) {
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    Graph g = {
        {"A", {{"B",1},{"C",4}}},
        {"B", {{"C",2},{"D",5}}},
        {"C", {{"D",1}}},
        {"D", {}}
    };
    auto dist = dijkstra(g, "A");
    for(const auto& [v, d] : dist) cout << v << ": " << d << "\n";
    return 0;
}
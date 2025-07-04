#include <bits/stdc++.h>
using namespace std;

using Node = string;
using Edge = pair<Node, int>;
using Graph = unordered_map<Node, vector<Edge>>;

vector<tuple<Node, Node, int>> prim(const Graph& graph, const Node& start) {
    unordered_set<Node> visited;
    using State = tuple<int, Node, Node>; // weight, node, prev
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, start, ""});
    vector<tuple<Node, Node, int>> mst;

    while(!pq.empty()) {
        auto [w, u, prev] = pq.top();
        pq.pop();
        if(visited.count(u)) continue;
        visited.insert(u);
        if(!prev.empty()) mst.push_back({prev, u, w});
        for(const auto& [v, weight] : graph.at(u)) {
            if(!visited.count(v)) pq.push({weight, v, u});
        }
    }
    return mst;
}

int main() {
    Graph g = {
        {"A", {{"B",2},{"C",3}}},
        {"B", {{"A",2},{"C",1},{"D",1}}},
        {"C", {{"A",3},{"B",1},{"D",4}}},
        {"D", {{"B",1},{"C",4}}}
    };
    auto mst = prim(g, "A");
    for(const auto& [u, v, w] : mst) cout << u << " - " << v << " : " << w << "\n";
    return 0;
}
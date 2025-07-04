#include <bits/stdc++.h>
using namespace std;

using Graph = unordered_map<string, vector<string>>;

int random_min_cut(Graph g) {
    random_device rd;
    mt19937 gen(rd());

    while(g.size() > 2) {
        auto it = next(g.begin(), uniform_int_distribution<int>(0, g.size() - 1)(gen));
        string u = it->first;
        auto& adj_u = it->second;
        string v = adj_u[uniform_int_distribution<int>(0, adj_u.size() - 1)(gen)];

        // Merge v into u
        adj_u.insert(adj_u.end(), g[v].begin(), g[v].end());
        for(auto& vertex : g[v]) {
            auto& adj = g[vertex];
            for(auto& x : adj) if(x == v) x = u;
        }
        g.erase(v);

        // Remove self-loops
        auto& new_adj = g[u];
        new_adj.erase(remove(new_adj.begin(), new_adj.end(), u), new_adj.end());
    }
    return g.begin()->second.size();
}

int main() {
    Graph g = {
        {"A", {"B","C"}},
        {"B", {"A","C"}},
        {"C", {"A","B"}}
    };
    cout << "Min cut: " << random_min_cut(g) << "\n";
    return 0;
}
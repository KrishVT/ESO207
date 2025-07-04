#pragma once
#include <unordered_map>
#include <vector>

template<typename T>
class DisjointSet {
    std::unordered_map<T, T> parent;
    std::unordered_map<T, int> rank;
public:
    explicit DisjointSet(const std::vector<T>& vertices) {
        for(const auto& v : vertices) {
            parent[v] = v;
            rank[v] = 0;
        }
    }
    T find(T u) {
        if(parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }
    void unite(T u, T v) {
        T ru = find(u), rv = find(v);
        if(ru == rv) return;
        if(rank[ru] < rank[rv]) parent[ru] = rv;
        else if(rank[ru] > rank[rv]) parent[rv] = ru;
        else { parent[rv] = ru; rank[ru]++; }
    }
};
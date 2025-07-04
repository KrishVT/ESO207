#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> greedy_set_cover(const unordered_set<int>& universe,
                                            vector<unordered_set<int>> subsets) {
    unordered_set<int> covered;
    vector<unordered_set<int>> selected;

    while(covered != universe) {
        auto best_it = max_element(subsets.begin(), subsets.end(),
            [&covered](const auto& a, const auto& b) {
                size_t ac = 0, bc = 0;
                for(int x : a) if(!covered.count(x)) ++ac;
                for(int x : b) if(!covered.count(x)) ++bc;
                return ac < bc;
            });
        selected.push_back(*best_it);
        for(int x : *best_it) covered.insert(x);
        subsets.erase(best_it);
    }
    return selected;
}

int main() {
    unordered_set<int> U;
    for(int i = 1; i <= 10; ++i) U.insert(i);
    vector<unordered_set<int>> subsets = {
        {1,2,3}, {2,4,5}, {5,6}, {7,8,9,10}, {3,7,10}
    };
    auto res = greedy_set_cover(U, subsets);
    cout << "Selected subsets:\n";
    for(const auto& s : res) {
        cout << "{";
        bool first = true;
        for(int x : s) {
            if(!first) cout << ",";
            cout << x;
            first = false;
        }
        cout << "} ";
    }
    cout << endl;
    return 0;
}
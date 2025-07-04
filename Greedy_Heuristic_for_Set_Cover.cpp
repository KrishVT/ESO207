#include<bits/stdc++.h>
using namespace std;

int greedySetCover(vector<set<int>>& sets, set<int> universe) {
    set<int> covered;
    int count = 0;

    while (covered != universe) {
        int maxCover = -1;
        int idx = -1;
        for (int i = 0; i < sets.size(); i++) {
            int coverCount = 0;
            for (int x : sets[i]) {
                if (!covered.count(x))
                    coverCount++;
            }
            if (coverCount > maxCover) {
                maxCover = coverCount;
                idx = i;
            }
        }
        for (int x : sets[idx])
            covered.insert(x);
        count++;
    }
    return count;
}

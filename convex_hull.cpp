#include <bits/stdc++.h>
using namespace std;

struct Point { long long x, y; };

long long orientation(const Point &p, const Point &q, const Point &r) {
    return (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
}

vector<Point> convex_hull(vector<Point> pts) {
    sort(pts.begin(), pts.end(), [](auto &a, auto &b){ return a.x == b.x ? a.y < b.y : a.x < b.x; });
    vector<Point> lower, upper;
    for(const auto &p: pts) {
        while(lower.size() >= 2 && orientation(lower[lower.size()-2], lower.back(), p) <= 0)
            lower.pop_back();
        lower.push_back(p);
    }
    for(int i = (int)pts.size() - 1; i >= 0; --i) {
        const auto &p = pts[i];
        while(upper.size() >= 2 && orientation(upper[upper.size()-2], upper.back(), p) <= 0)
            upper.pop_back();
        upper.push_back(p);
    }
    if(!lower.empty()) lower.pop_back();
    if(!upper.empty()) upper.pop_back();
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

int main() {
    vector<Point> pts = {{0,0},{1,1},{2,2},{2,0},{2,4},{3,3}};
    auto hull = convex_hull(pts);
    cout << "Convex Hull:\n";
    for(const auto &p: hull) cout << "(" << p.x << ", " << p.y << ") ";
    cout << endl;
    return 0;
}
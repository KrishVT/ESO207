#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

Point p0;

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y);
    return (val == 0) ? 0 : (val > 0 ? 1 : 2); // 0 = colinear, 1 = clockwise, 2 = counterclockwise
}

bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return (pow(p1.x - p0.x, 2) + pow(p1.y - p0.y, 2) <
                pow(p2.x - p0.x, 2) + pow(p2.y - p0.y, 2));
    return o == 2;
}

vector<Point> convexHull(vector<Point> points) {
    int n = points.size();
    if (n < 3) return {}; // Convex hull is not defined for less than 3 points

    // Step 1: Find the bottom-most (or left-most in case of tie) point
    int ymin = points[0].y, minIdx = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < ymin) || 
           (points[i].y == ymin && points[i].x < points[minIdx].x)) {
            ymin = points[i].y;
            minIdx = i;
        }
    }

    swap(points[0], points[minIdx]);
    p0 = points[0];

    // Step 2: Sort points with respect to polar angle with p0
    sort(points.begin() + 1, points.end(), compare);

    // Step 3: Push first three points to the hull
    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);

    // Step 4: Process the rest
    for (int i = 3; i < n; i++) {
        while (hull.size() >= 2 &&
               orientation(hull[hull.size() - 2], hull.back(), points[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}
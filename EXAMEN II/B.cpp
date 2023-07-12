#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

struct Point {
    double x;
    double y;
};

bool comparePointsX(const Point& p1, const Point& p2) {
    return p1.x < p2.x;
}

bool comparePointsY(const Point& p1, const Point& p2) {
    return p1.y < p2.y;
}

double distance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

double stripClosest(const vector<Point>& strip, double minDistance) {
    double minDist = minDistance;

    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            double dist = distance(strip[i], strip[j]);
            minDist = min(minDist, dist);
        }
    }

    return minDist;
}

double closestPair(vector<Point>& points) {
    const int n = points.size();

    if (n <= 3) {
        double minDist = numeric_limits<double>::max();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double dist = distance(points[i], points[j]);
                minDist = min(minDist, dist);
            }
        }

        return minDist;
    }

    const int mid = n / 2;
    const Point midPoint = points[mid];

    vector<Point> leftPoints(points.begin(), points.begin() + mid);
    vector<Point> rightPoints(points.begin() + mid, points.end());

    double distLeft = closestPair(leftPoints);
    double distRight = closestPair(rightPoints);
    double minDist = min(distLeft, distRight);

    vector<Point> strip;

    for (const auto& point : points) {
        if (abs(point.x - midPoint.x) < minDist) {
            strip.push_back(point);
        }
    }

    sort(strip.begin(), strip.end(), comparePointsY);

    double stripMinDist = stripClosest(strip, minDist);
    return min(minDist, stripMinDist);
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<Point> points(n);

        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
        }

        sort(points.begin(), points.end(), comparePointsX);

        double closestDistance = closestPair(points);

        if (closestDistance < 10000.0) {
            cout.precision(4);
            cout << fixed << closestDistance << endl;
        } else {
            cout << "INFINITY" << endl;
        }
    }

    return 0;
}

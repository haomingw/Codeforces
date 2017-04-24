#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cassert>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

struct Point {
    double x, y;
    Point(int x, int y) : x(x), y(y) {}
};

Point operator - (Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}

double operator * (Point a, Point b) {
    return abs(a.x * b.y - a.y * b.x);
}

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

vector<Point> p;

double solve(int a, int b, int c) {
    return (p[b] - p[a]) * (p[c] - p[a]) / distance(p[a], p[c]) / 2.;
}

int main() {
    int n;
    scanf("%d", &n);
    int x, y;
    REP(i, n) {
        scanf("%d%d", &x, &y);
        p.push_back(Point(x, y));
    }
    int a, b, c;
    double ans = 1e18;
    REP(i, n) {
        a = i, b = (i + 1) % n, c = (i + 2) % n;
        ans = min(ans, solve(a, b, c));
    }
    printf("%.8f\n", ans);
    return 0;
}

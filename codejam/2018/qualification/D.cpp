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
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

#define PI (acos(0) * 2)

double a;

struct Point {
    double x, y, z;
    Point(double x, double y, double z): x(x), y(y), z(z) {}
};

ostream& operator << (ostream& out, const Point& point) {
    out << point.x << " " << point.y << " " << point.z;
    return out;
}

void print(Point& p1, Point& p2, Point& p3) {
    cout << endl;
    cout << p1 << fixed << endl;
    cout << p2 << fixed << endl;
    cout << p3 << fixed << endl;
}

void naive(bool isNaive, Point& p1, Point& p2, Point& p3) {
    double theta = isNaive ? PI / 4 - acos(a / sqrt(2)) : PI / 4;
    p1.x *= cos(theta), p1.y = 0.5 * sin(theta);
    p2.x = -0.5 * sin(theta), p2.y *= cos(theta);
}

void solve() {
    cin >> a;
    Point p1 = Point(0.5, 0, 0),
          p2 = Point(0, 0.5, 0),
          p3 = Point(0, 0, 0.5);
    bool isNaive = a * a < 2;
    naive(isNaive, p1, p2, p3);
    if (isNaive) {
        print(p1, p2, p3);
        return;
    }
    double alpha = asin(sqrt(6) / 3);
    double theta = asin(a / sqrt(3)) - alpha;
    p1.z = -p1.y * sin(theta), p1.y *= cos(theta);
    p2.z = -p2.y * sin(theta), p2.y *= cos(theta);
    p3.y = 0.5 * sin(theta), p3.z *= cos(theta);
    print(p1, p2, p3);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cout.precision(10);
    int T; cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}

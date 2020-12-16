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
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

#define PI 3.14159265

int dist(int x, int y) {
    return (x - 50) * (x - 50) + (y - 50) * (y - 50);
}

int solve() {
    int p, x, y;
    cin >> p >> x >> y;
    int d = dist(x, y);
    if (d > 2500) return !printf("white\n");
    double r = (y - 50) / sqrt(d);
    double res = acos(r) * 180 / PI;
    if (x < 50) res = 360 - res;
    res = res / 360.0 * 100;
    if (res <= p) cout << "black" << endl;
    else cout << "white" << endl;
    return 0;
}

int main() {
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}

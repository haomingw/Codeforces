#include <iostream>
#include <cstdio>
#include <cmath>
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

const int inf = 2e9 + 10;

int main() {
    int n, x0, y0;
    cin >> n;
    cin >> x0 >> y0;
    char c, p[8];
    int x, y, d[8];
    REP(i, 8) d[i] = inf;
    REP(k, n) {
        cin >> c >> x >> y;
        x -= x0; y -= y0;
        int i = 0;
        if (x == 0 && y > 0 && abs(y) < d[i]) {
            d[i] = abs(y);
            p[i] = c;
        }
        i++;
        if (x == 0 && y < 0 && abs(y) < d[i]) {
            d[i] = abs(y);
            p[i] = c;
        }
        i++;
        if (y == 0 && x > 0 && abs(x) < d[i]) {
            d[i] = abs(x);
            p[i] = c;
        }
        i++;
        if (y == 0 && x < 0 && abs(x) < d[i]) {
            d[i] = abs(x);
            p[i] = c;
        }
        i++;
        if (y == x && x > 0 && abs(x) < d[i]) {
            d[i] = abs(x);
            p[i] = c;
        }
        i++;
        if (y == x && x < 0 && abs(x) < d[i]) {
            d[i] = abs(x);
            p[i] = c;
        }
        i++;
        if (y == -x && x > 0 && abs(x) < d[i]) {
            d[i] = abs(x);
            p[i] = c;
        }
        i++;
        if (y == -x && x < 0 && abs(x) < d[i]) {
            d[i] = abs(x);
            p[i] = c;
        }
        i++;
    }
    REP(i, 4) {
        if (d[i] < inf && p[i] != 'B') return !printf("YES\n");
    }
    REPP(i, 4, 8) {
        if (d[i] < inf && p[i] != 'R') return !printf("YES\n");
    }
    return !printf("NO\n");
}

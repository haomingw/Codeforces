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

const int inf = 1e9;

int main() {
    int n; cin >> n;
    int c, d, lo = -inf, hi = inf;
    REP(i, n) {
        scanf("%d%d", &c, &d);
        if (d == 1) lo = max(lo, 1900);
        else hi = min(hi, 1899);
        lo += c, hi += c;
    }
    if (lo > hi) cout << "Impossible" << endl;
    else if (hi > inf/ 2) cout << "Infinity" << endl;
    else cout << hi << endl;
    return 0;
}

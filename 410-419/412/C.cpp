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

const ll inf = 1e18;
ll x, y, p, q;

ll solve() {
    cin >> x >> y >> p >> q;
    if ((p == q && x != y) || (p == 0 && x != 0)) return -1;
    ll hi = (inf + y) / q + 1, lo = 0;
    ll a, b;
    while (hi > lo) {
        ll mid = (hi + lo) / 2;
        a = mid * q - y, b = mid * p - x;
        if (b >= 0 && a >= b) hi = mid;
        else lo = mid + 1;
    }
    ll ans = lo * q - y;
    return ans;
}

int main() {
    int T;
    cin >> T;
    REP(t, T) {
        cout << solve() << endl;
    }
    return 0;
}

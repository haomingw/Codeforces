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

int main() {
    ll x, y, l, r;
    cin >> x >> y >> l >> r;
    ll ans = 0;
    vector<ll> v;
    v.push_back(l - 1);
    v.push_back(r + 1);
    for (ll i = 1; ; i *= x) {
        for (ll j = 1; ; j *= y) {
            if (i + j >= l && i + j <= r) v.push_back(i + j);
            if (y > (r - i) / j) break;
        }
        if (x > r / i) break;
    }
    sort(ALL(v));
    REPP(i, 1, SIZE(v)) ans = max(ans, v[i] - v[i - 1] - 1);
    cout << ans << endl;
    return 0;
}

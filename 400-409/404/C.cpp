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

ll calc(ll n) {
    return n * (n + 1) / 2;
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll lo = 0, hi = 1e10;
    if (n <= m) return !printf("%lld\n", n);
    n -= m;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (calc(mid) >= n) hi = mid;
        else lo = mid + 1;
    }
    ll ans = lo + m;
    cout << ans << endl;
    return 0;
}

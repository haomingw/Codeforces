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
    ll base = 2, nb = 1;
    while (n > 1) {
        nb += base;
        n /= 2, base *= 2;
    }
    return nb;
}

ll sum(ll p, ll n) {
    ll t = 0, nb = calc(n);
    while (p) {
        ll mid = (nb + 1) / 2;
        if (p >= mid) {
            p -= mid;
            t += (n + 1) / 2;
        }
        n /= 2, nb /= 2;
    }
    return t;
}

int main() {
    ll n, l, r;
    cin >> n >> l >> r;
    ll ans = sum(r, n) - sum(l - 1, n);
    cout << ans << endl;
    return 0;
}

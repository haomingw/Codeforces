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

ll n, k, a, b;

bool can(ll x) {
    if (x % k != 0) return false;
    if (x == k) return b < (x - 1) * a;
    return b < (x - x / k) * a;
}

int main() {
    cin >> n >> k >> a >> b;
    ll x = n, ans = 0;
    if (k == 1) {
        cout << (x - 1) * a << endl;
        return 0;
    }
    while (x > 1) {
        if (can(x)) ans += b, x /= k;
        else {
            int nb = x % k;
            if (nb == 0) nb = x - x / k;
            if (x < k) nb = x - 1;
            ans += nb * a;
            x -= nb;
        }
    }
    cout << ans << endl;
    return 0;
}

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

ll n, m;

int solve() {
    cin >> n >> m;
    if (1LL << (n - 2) < m) return !printf("IMPOSSIBLE\n");
    printf("POSSIBLE\n");
    int len = n - 2, l = 0; m--;
    cout << 0;
    while (len--) {
        if (m & 1LL << len) l = max(l, len), cout << 1;
        else cout << 0;
    }
    cout << 1 << endl;
    int cible = n - l - 1;
    for (int i = 2; i <= n; i++) {
        if (i < cible) {
            REP(j, n) cout << 0;
            cout << endl;
        } else {
            REP(j, i) cout << 0;
            REP(j, n - i) cout << 1;
            cout << endl;
        }
    }
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

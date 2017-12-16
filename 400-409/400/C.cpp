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

const int maxn = 1e5 + 5;
int a[maxn];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", &a[i]);
    ll ans = 0, s = 0;
    map<ll, int> m;
    m[0] = 1;
    for (int i = 0; i < n; i++) {
        s += a[i];
        for (ll j = 1; j <= 1e15; j *= k) {
            if (m.count(s - j)) ans += m[s - j];
            if (k == 1 || j == -1) break;
        }
        m[s]++;
    }
    cout << ans << endl;
    return 0;
}

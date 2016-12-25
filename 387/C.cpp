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

const int maxn = 105;
int a[maxn];

int main() {
    int n, q; cin >> n >> q;
    REP(i, q) {
        int t, k, d;
        scanf("%d%d%d", &t, &k, &d);
        int cnt = 0;
        REP(j, n) if (a[j] <= t) cnt++;
        if (cnt < k) {
            cout << -1 << endl;
        } else {
            int ans = 0;
            for (int j = 0; j < n && k; j++) if (a[j] <= t)
                a[j] = t + d, k--, ans += j + 1;
            cout << ans << endl;
        }
    }
    return 0;
}

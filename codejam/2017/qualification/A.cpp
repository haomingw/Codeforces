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

int a[1005];

void solve() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    REP(i, n) a[i] = (s[i] == '-') ? 0 : 1;
    int ans = 0, sum = 0;
    REP(i, n - k + 1) if (a[i] == 0) {
        REP(j, k) a[i + j] ^= 1;
        ans++;
    }
    REP(i, k) sum += a[n - 1 - i];
    if (sum == k) cout << ans << endl;
    else cout << "IMPOSSIBLE" << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}

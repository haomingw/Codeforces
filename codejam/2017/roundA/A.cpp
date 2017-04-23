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

void solve() {
    int R, C;
    cin >> R >> C;
    string a[R];
    REP(i, R) cin >> a[i];
    // first fill horizontal ?s
    REP(i, R) REP(j, C) {
        if (a[i][j] != '?') {
            int p = j + 1;
            while (p < C && a[i][p] == '?') a[i][p] = a[i][j], p++;
            p = j - 1;
            while (p >= 0 && a[i][p] == '?') a[i][p] = a[i][j], p--;
        }
    }
    REP(i, R) REP(j, C) {
        if (a[i][j] != '?') {
            int p = i + 1;
            while (p < R && a[p][j] == '?') a[p][j] = a[i][j], p++;
            p = i - 1;
            while (p >= 0 && a[p][j] == '?') a[p][j] = a[i][j], p--;
        }
    }
    REP(i, R) REP(j, C) assert(a[i][j] != '?');
    cout << endl;
    REP(i, R) cout << a[i] << endl;
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

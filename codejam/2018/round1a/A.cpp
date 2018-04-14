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
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 105;
int r, c, h, v, a[maxn][maxn];
int row[maxn], col[maxn];

bool can() {
    int cnt = 0;
    REP(i, r) REP(j, c) cnt += a[i][j];
    if (cnt == 0) return true;
    if (cnt % ((h + 1) * (v + 1)) != 0) return false;
    REP(i, maxn) row[i] = col[i] = 0;
    REP(i, r) REP(j, c) row[i + 1] += a[i][j], col[j + 1] += a[i][j];
    REPP(i, 1, r + 1) row[i] += row[i - 1];
    REPP(i, 1, c + 1) col[i] += col[i - 1];
    int prev = 0, target = cnt / (h + 1);
    vector<int> vr(1), vc(1);
    REPP(i, 1, r + 1) {
        int nb = row[i] - row[prev];
        if (nb == target) prev = i, vr.push_back(i);
        else if (nb > target) return false;
    }
    prev = 0, target = cnt / (v + 1);
    REPP(i, 1, c + 1) {
        int nb = col[i] - col[prev];
        if (nb == target) prev = i, vc.push_back(i);
        else if (nb > target) return false;
    }
    target = cnt / ((h + 1) * (v + 1));
    assert(SZ(vr) == h + 2);
    assert(SZ(vc) == v + 2);
    int x;
    REP(k1, h + 1) REP(k2, v + 1){
        x = 0;
        REPP(i, vr[k1], vr[k1 + 1]) REPP(j, vc[k2], vc[k2 + 1]) x += a[i][j];
        if (x != target) return false;
    }
    return true;
}

void solve() {
    cin >> r >> c >> h >> v;
    string s;
    REP(i, r) {
        cin >> s;
        REP(j, c) a[i][j] = s[j] == '@';
    }
    cout << (can() ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}

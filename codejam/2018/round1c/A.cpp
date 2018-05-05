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

const int maxn = 10;
int n, len, a[maxn];
vector<string> vs;
vector<char> level[maxn];
set<string> total;

void clear() {
    vs.clear();
    REP(i, maxn) level[i].clear();
    total.clear();
    REP(i, maxn) a[i] = 0;
}

void add() {
    a[0]++;
    REP(i, len - 1) {
        if (a[i] >= SZ(level[i])) a[i] -= SZ(level[i]), a[i + 1]++;
    }
}

void solve() {
    clear();
    cin >> n >> len;
    string s;
    REP(i, n) {
        cin >> s;
        vs.push_back(s);
        total.insert(s);
    }
    if (len == 1) {
        cout << "-" << endl;
        return;
    }
    REP(i, n) REP(j, len) level[j].push_back(vs[i][j]);
    REP(i, len) {
        sort(ALL(level[i]));
        int x = unique(ALL(level[i])) - level[i].begin();
        level[i].resize(x);
    }
    string t;
    int nb = 1;
    REP(i, len) {
        nb *= SZ(level[i]);
        if (nb > 5000) break;
    }
    while (nb--) {
        string t = "";
        REP(i, len) {
            t += level[i][a[i]];
        }
        if (!total.count(t)) {
            cout << t << endl;
            return;
        }
        add();
    }
    cout << "-" << endl;
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

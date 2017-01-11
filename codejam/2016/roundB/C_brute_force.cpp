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
typedef pair<string, string> pss;

const int inf = 10000;

void solve() {
    int n; cin >> n;
    string s1, s2;
    unordered_map<string, int> fi, se;
    int cnt = 0;
    vector<pss> p;
    REP(i, n) {
        cin >> s1 >> s2;
        p.push_back(MP(s1, s2));
        fi[s1]++, se[s2]++;
    }
    int a = fi.size(), b = se.size(), h = 1 << n, ans = inf;
    // brute force solution
    REP(i, h) {
        set<string> sa, sb;
        int cnt = 0;
        REP(j, n) if (i & 1 << j) {
            sa.insert(p[j].first);
            sb.insert(p[j].second);
            cnt++;
        }
        if (SIZE(sa) == a && SIZE(sb) == b) ans = min(ans, cnt);
    }
    ans = n - ans;
    cout << ans << endl;
}

int main() {
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}

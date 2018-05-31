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

const int maxn = 105;
int n, m, s[maxn], d[maxn], c[maxn];

int main() {
    cin >> n >> m;
    vector<int> ans(n);
    vector<pii> v;
    REP(i, m) {
        cin >> s[i] >> d[i] >> c[i];
        s[i]--, d[i]--;
        ans[d[i]] = m + 1;
        v.push_back(MP(d[i], i));
    }
    sort(ALL(v));
    int x, cnt = 0;
    for (pii p : v) {
        x = p.second, cnt = 0;
        bool ok = false;
        REPP(i, s[x], d[x]) if (ans[i] == 0) {
            cnt++;
            ans[i] = x + 1;
            if (cnt == c[x]) {
                ok = true;
                break;
            }
        }
        if (!ok) return !printf("-1\n");
    }
    REP(i, n) cout << ans[i] << " ";
    cout << endl;
    return 0;
}

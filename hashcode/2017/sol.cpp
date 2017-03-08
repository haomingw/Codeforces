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

const int maxn = 1e4 + 5, N = 5e5 + 5;
int V, E, R, C, X;
int v[maxn], e[maxn], p[maxn][maxn];
ll dp[maxn][N];
set<pii> rq[maxn];
vector<pii> t[maxn];
vector<vector<int> > server;
vector<int> cache[1005], endpoint[1005];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> V >> E >> R >> C >> X;
    REP(i, V) cin >> v[i];
    int nc;
    REP(i, E) {
        cin >> e[i] >> nc;
        int cid, lc;
        REP(j, nc) {
            cin >> cid >> lc;
            int x = e[i] - lc; // saving time
            cache[cid].push_back(i); // endpoint id
            endpoint[i].push_back(cid);
            p[cid][i] = x;
        }
    }
    int nb, vid, eid;
    server.resize(C);
    REP(i, R) {
        cin >> vid >> eid >> nb;
        rq[eid].insert(MP(vid, nb));
    }
    // determin cache server order
    REP(i, C) {
        // clog << i << " " << SIZE(cache[i]) << endl;
        if (SIZE(cache[i]) == 1) {
            int x = cache[i][0]; // endpoint id
            if (SIZE(endpoint[x]) == 1) continue;
            clog << "cid: " << i << ", size: " << SIZE(endpoint[x]) << endl;
            vector<pii> cs;
            for (int cid : endpoint[x]) cs.push_back(MP(p[cid][x], cid));
            sort(ALL(cs));
            REP(j, SIZE(cs) - 2) {
                // cut the link
                pii q = cs[j];
                int id = q.second;
                REP(k, SIZE(cache[id])) {
                    if (cache[id][k] == x) {
                        cache[id].erase(cache[id].begin() + k);
                        break;
                    }
                }
            }
        }
    }

    ll a[V], x[V];
    REP(c, C) {
        memset(a, 0, sizeof(a));
        memset(x, 0, sizeof(x));
        // clog << c << " serves " << cache[c].size() << " endpoints" << endl;
        REP(i, V) t[i].clear();
        for (int i : cache[c]) {
            for (pii q : rq[i]) {
                vid = q.first, nb = q.second;
                a[vid] += nb * p[c][i];
                t[vid].push_back(MP(i, nb)); // endpoint, nb
            }
        }
        REP(i, V + 1) REP(j, X + 1) {
            dp[i][j] = (i == 0) ? 0 : dp[i - 1][j];
            if (i > 0 && j >= v[i - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + a[i - 1]);
            }
        }
        int j = X;
        for (int i = V; i > 0; i--){
            if (dp[i][j] > dp[i - 1][j]) {
                x[i - 1] = 1;
                j -= v[i - 1];
            }
        }
        int sum = 0;
        REP(i, V) {
            if (x[i] == 1) {
                sum += v[i];
                server[c].push_back(i);
                for (pii q : t[i]) {
                    eid = q.first, nb = q.second;
                    rq[eid].erase(MP(i, nb));
                }
            }
        }
        // clog << "sum : " << sum << endl;
    }

    int ans = 0;
    REP(i, C) if (!server[i].empty()) ans++;
    cout << ans << endl;
    REP(i, C) {
        if (server[i].empty()) continue;
        cout << i;
        REP(j, SIZE(server[i])) cout << " " << server[i][j];
        cout << endl;
    }
    return 0;
}

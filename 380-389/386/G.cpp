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

int main() {
    int n, t, k;
    cin >> n >> t >> k;
    int a[t];
    REP(i, t) scanf("%d", &a[i]);
    int lo = a[t - 1], hi = a[t - 1];
    REP(i, t - 1) {
        lo += max(0, a[i] - a[i + 1]);
        hi += a[i] - 1;
    }
    if (lo > k || hi < k) return !printf("-1\n");
    vector<vector<int> > lv;
    lv.resize(t);
    vector<pii> ans;
    int node = 2, nb = k - lo;
    REP(i, a[0]) {
        ans.push_back(MP(1, node));
        lv[0].push_back(node);
        node++;
    }
    REP(i, t - 1) {
        int x = min(nb, min(a[i], a[i + 1]) - 1);
        nb -= x;
        int nc = min(a[i], a[i + 1]) - x; // nombre de connexion
        REP(j, nc) {
            ans.push_back(MP(lv[i][j], node));
            lv[i + 1].push_back(node);
            node++;
        }
        REP(j, a[i + 1] - nc) {
            ans.push_back(MP(lv[i][nc - 1], node));
            lv[i + 1].push_back(node);
            node++;
        }
    }
    cout << n << endl;
    for (pii p : ans)
        cout << p.first << " " << p.second << endl;
    return 0;
}

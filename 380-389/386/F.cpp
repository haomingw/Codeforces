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
    int n, w, k, ans = 0;
    cin >> n >> w >> k;
    int a[n], t[n];
    REP(i, n) scanf("%d", a + i);
    REP(i, n) scanf("%d", t + i);
    set<pii> full, half;
    int ct = 0, ca = 0, lp = -1;
    REP(i, n) {
        full.insert(MP(t[i], i));
        ca += a[i]; ct += t[i];
        if (half.size() == w) {
            auto it = half.begin();
            ct += it->first / 2;
            full.insert(*it);
            half.erase(*it);
        }
        auto it = full.rbegin();
        ct -= it->first / 2;
        half.insert(*it);
        full.erase(*it);
        while (ct > k) {
            lp++; // remove the most left song
            pii p = MP(t[lp], lp);
            if (half.find(p) != half.end()) {
                half.erase(p);
                ct -= (t[lp] + 1) / 2;
            } else {
                full.erase(p);
                ct -= t[lp];
            }
            ca -= a[lp];
            if (half.size() < w && !full.empty()) {
                auto it = full.rbegin();
                ct -= it->first / 2;
                half.insert(*it);
                full.erase(*it);
            }
        }
        ans = max(ca, ans);
    }
    cout << ans << endl;
    return 0;
}

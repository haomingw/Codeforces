#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
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
    int n, k, x;
    cin >> n;
    int a[n];
    REP(i, n) cin >> a[i];
    cin >> k;
    vector< pair<int, char> > ans;
    int it = 0;
    REP(i, k) {
        cin >> x;
        set<int> sd;
        int ll = it, v = 0, ma = 0, ind;
        while (it < n && a[it] + v <= x) {
            v += a[it];
            sd.insert(a[it]);
            ma = max(a[it], ma);
            it++;
        }
        int rr = it;
        if (v != x || (SIZE(sd) == 1 && ll + 1 < rr))
            return !printf("NO\n");
        REPP(j, ll + 1, rr) {
            if (max(a[j], a[j - 1]) == ma && min(a[j], a[j - 1]) != ma) {
                if (a[j - 1] == ma) {
                    REPP(k, j, rr) ans.push_back(MP(i + j - 1 - ll, 'R'));
                    for (int k = j - 1; k > ll; k--) ans.push_back(MP(i + k - ll, 'L'));
                } else {
                    for (int k = j; k > ll; k--) ans.push_back(MP(i + k - ll, 'L'));
                    REPP(k, j, rr - 1) ans.push_back(MP(i ,'R'));
                }
                break;
            }
        }
    }
    clog << it << endl;
    if (it < n) return !printf("NO\n");
    cout << "YES" << endl;
    REP(i, SIZE(ans))
        cout << ans[i].first + 1 << " " << ans[i].second << endl;
    return 0;
}

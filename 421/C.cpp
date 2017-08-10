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

int main() {
    int a, b, l, r;
    cin >> a >> b >> l >> r;
    string s = "";
    REP(i, a) s += char('a' + i);
    REP(i, b) s += char('a' + a - 1);
    if (a <= b) {
        REP(i, a - 1) s += char('a' + i);
        REP(i, b + 1) s += char('a' + a);
    } else {
        REP(i, b) s += char('a' + i);
        REP(i, a - b) s += char('a' + a + i);
        REP(i, b) s += char('a' + 2 * a - b - 1);
    }
    int n = s.size(), ans;
    set<char> ensemble;
    if (r - l + 1 <= n) {
        l = (l - 1) % n;
        r = (r - 1) % n;
        if (r >= l) {
            REPP(i, l, r + 1) ensemble.insert(s[i]);
            ans = ensemble.size();
        } else {
            REPP(i, l, n) ensemble.insert(s[i]);
            REP(i, r + 1) ensemble.insert(s[i]);
            ans = ensemble.size();
            if (a > b) {
                // start from the first b part
                // so b part doesn't have to be the last letter in a, but as front as possible
                ensemble.clear(); s = "";
                REP(i, a) s += char('a' + i);
                REP(i, b) s += char('a' + b);
                REP(i, b) s += char('a' + i);
                REP(i, a - b) s += char('a' + a + i);
                REP(i, b) s += char('a' + 2 * a - b - 1);
                REPP(i, l, n) ensemble.insert(s[i]);
                REP(i, r + 1) ensemble.insert(s[i]);
                ans = min(ans, SZ(ensemble));
            }
        }
    } else {
        REP(i, n) ensemble.insert(s[i]);
        ans = ensemble.size();
    }
    cout << ans << endl;
    return 0;
}

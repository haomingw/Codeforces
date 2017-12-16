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

#define FOR(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    int l[n], r[n], sl = 0, sr = 0;
    REP(i, n) {
        cin >> l[i] >> r[i];
        sl += l[i];
        sr += r[i];
    }

    int tl, tr, ans = 0, res = abs(sl - sr);
    REP(i, n) {
        tl = sl - l[i] + r[i];
        tr = sr - r[i] + l[i];
        // clog << abs(tl - tr) << endl;
        if (abs(tl - tr) > res) {
            res = abs(tl - tr);
            ans = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}

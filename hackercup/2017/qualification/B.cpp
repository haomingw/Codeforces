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

void solve() {
    int n, t, ans = 0; cin >> n;
    vector<int> p;
    REP(i, n) {
        scanf("%d", &t);
        p.push_back(t);
    }
    sort(ALL(p));
    while (!p.empty()) {
        int top = p.back(), cnt;
        cnt = 50 / top;
        if (50 % top != 0) cnt++;
        if (p.size() >= cnt) {
            REP(i, cnt - 1) p.erase(p.begin());
            p.pop_back();
        } else break;
        ans++;
    }
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

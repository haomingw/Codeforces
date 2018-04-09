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

const int maxn = 30;
int a[maxn], d;
string s;

void reduce(int& damage) {
    int n = s.size();
    for (int i = n - 1; i > 0; i++) if (a[i]) {
        a[i]--, a[i - 1]++;
        damage -= 1 << (i - 1);
        break;
    }
}

void solve() {
    cin >> d >> s;
    int n = s.size(), cnt = 0;
    REP(i, n) a[i] = 0;
    int damage = 0, base = 1;
    REP(i, n) {
        if (s[i] == 'S') a[cnt]++, damage += base;
        else cnt++, base *= 2;
    }
    if (d < n - cnt) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    int ans = 0;
    while (damage > d) {
        reduce(damage);
        ans++;
    }
    cout << ans << endl;
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

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

const int inf = 1e9;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int cur = 0;
    REP(i, m) {
        while (cur < n && s[cur] != t[i]) cur++;
        if (cur == n) a[i + 1] = inf;
        else a[i + 1] = ++cur;
    }
    cur = n - 1;
    REP(i, m) {
        while (cur >= 0 && s[cur] != t[m - i - 1]) cur--;
        if (cur < 0) b[i + 1] = inf;
        else b[i + 1] = n - cur, cur--;
    }
    pii p = MP(0, 0);
    cur = m;
    REP(i, m + 1) {
        cur = min(cur, m - i);
        if (a[i] == inf) break;
        while (b[cur] > n - a[i]) cur--;
        if (i + cur > p.first + p.second) p = MP(i, cur);
    }
    int l = p.first, r = p.second;
    if (l == 0 && r == 0) return !printf("-\n");;
    string ans = t.substr(0, l) + t.substr(m - r);
    cout << ans << endl;
    return 0;
}

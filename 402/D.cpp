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

const int maxn = 2e5 + 5;
int n, m, a[maxn];
bool f[maxn];
string s, t;

bool contains() {
    // check if s constains t
    int p = 0;
    REP(i, m) {
        while (p < n && (t[i] != s[p] || f[p])) p++;
        p++;
    }
    return p <= n;
}

int main() {
    cin >> s >> t;
    n = s.size(), m = t.size();
    REP(i, n) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        fill(f, f + n, false);
        REP(i, mid) f[a[i]] = true;
        if (!contains()) hi = mid;
        else lo = mid + 1;
    }
    cout << lo - 1 << endl;
    return 0;
}

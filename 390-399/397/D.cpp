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

const int maxn = 1e5 + 5;
int f[maxn], a[maxn], g[maxn], h[maxn];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main() {
    int n; cin >> n;
    REP(i, n + 1) f[i] = i;
    REPP(i, 1, n + 1) scanf("%d", &a[i]);
    REPP(i, 1, n + 1) {
        if (a[a[i]] != a[i]) return !printf("-1\n");
    }
    int m = 0;
    REPP(i, 1, n + 1) {
        if (a[i] == i) h[m++] = i, g[i] = m;
        else f[find(i)] = find(a[i]);
    }
    REPP(i, 1, n + 1) g[i] = g[find(i)];
    cout << m << endl;
    REPP(i, 1, n + 1) cout << g[i] << " "; cout << endl;
    REP(i, m) cout << h[i] << " "; cout << endl;
    return 0;
}

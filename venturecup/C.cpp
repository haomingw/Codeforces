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

const int maxn = 1e4 + 5;
int f[maxn];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main() {
    int n; cin >> n;
    REP(i, n) f[i] = i;
    REP(i, n) {
        int u, v = i;
        scanf("%d", &u);
        u--;
        if (v > u) swap(u, v);
        f[find(u)] = f[find(v)];
    }
    int ans = 0;
    REP(i, n) {
        if (find(i) == i) ans++;
    }
    cout << ans << endl;
    return 0;
}

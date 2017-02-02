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
int a[maxn][2], b[maxn], c[maxn];

int main() {
    int n; cin >> n;
    int u, v;
    REP(i, n - 1) {
        scanf("%d%d", &u, &v);
        a[i][0] = u;
        a[i][1] = v;
    }
    REP(i, n) scanf("%d", &c[i + 1]);
    int bad = 0;
    REP(i, n - 1) {
        u = a[i][0], v = a[i][1];
        if (c[u] != c[v]) {
            bad++;
            b[u]++, b[v]++;
        }
    }
    REPP(i, 1 , n + 1) {
        if (b[i] == bad) return !printf("YES\n%d\n", i);
    }
    cout << "NO" << endl;
    return 0;
}

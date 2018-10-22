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

const int maxn = 305;
int n, m;
char c[maxn][maxn];
ll s[maxn][maxn * 2], f[maxn * 2];

void solve() {
    scanf("%d%d", &n, &m);
    memset(s, 0, sizeof(s));
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++)
        scanf("%s", c[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = m + i; k >= 0; k--)
                s[j][k + 1] = s[j][k];
            s[j][0] = 0;
        }
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '1') {
                for (int k = 0; k < m + i; k++)
                    f[k] += s[j][k];
                for (int k = 0; k < m; k++)
                    s[k][abs(j - k)]++;
            }
        }
    }
    for (int i = 1; i <= m + n - 2; i++)
        printf("%lld ", f[i]);
    printf("\n");
}

int main() {
    int T; cin >> T;
    REP(i, T) {
        solve();
    }
    return 0;
}

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
vector<int> g[maxn];
int c[maxn], ans = 1;

void dfs(int p, int cur) {
    int color = 0;
    for (int x : g[cur]) {
        if (x == p) continue;
        REPP(i, color + 1, maxn + 1) {
            if (i != c[p] && i != c[cur]) {
                color = i;
                break;
            }
        }
        c[x] = color;
        ans = max(ans, color);
        dfs(cur, x);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int x, y;
    REP(i, n - 1) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    c[1] = 1;
    dfs(0, 1);
    cout << ans << endl;
    REPP(i, 1, n + 1) cout << c[i] << " ";
    cout << endl;
    return 0;
}

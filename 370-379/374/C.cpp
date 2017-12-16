#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vii;

const int l = 5010;
vii g[l];
int d[l], q[l];
int dp[l][l], pre[l][l];
int tt = 0, h = 0;

inline void bfs(int n) {
    int u;
    while (h < tt) {
        u = q[h++];
        // clog << u << ": ";
        for (auto v : g[u]) {
            int next = v.first, cost = v.second;
            // clog << "  "<< next << " => ";
            for (int j = 1; j <= n; j++) {
                if (dp[u][j] <= 1e9 && dp[next][j + 1] > dp[u][j] + cost) {
                    dp[next][j + 1] = dp[u][j] + cost;
                    pre[next][j + 1] = u;
                    // clog << j << ", " << dp[next][j + 1] << "  ";
                }
            }
        }
        // clog << endl;
    }
}

int main() {
    int n, m, T;
    scanf("%d %d %d", &n, &m, &T);
    for (int i = 1; i <= n; i++)
        for (int j = 1 + (i == 1); j <= n; j++) dp[i][j] = 2e9;
    int u, v, t;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &t);
        g[u].push_back({v, t});
        d[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!d[i]) q[tt++] = i;
    }
    while (h < tt) {
        int u = q[h++];
        for (auto v : g[u]) {
            int next = v.first;
            d[next]--;
            if (!d[next]) q[tt++] = next;
        }
    }
    h = 0;
    bfs(n);
    for (int i = n; i >= 1; i--) {
        if (dp[n][i] <= T) {
            vector<int> order;
            int ville = n, cnt = i;
            while (cnt--) {
                order.push_back(ville);
                ville = pre[ville][cnt + 1];
            }
            reverse(order.begin(), order.end());
            cout << order.size() << endl;
            for (auto c : order) cout << c << " ";
            cout << endl;
            return 0;
        }
    }
    return 0;
}

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

const int maxn = 7005;
int m[2], a[2][maxn], dp[2][maxn];
int nb[2][maxn], q[2 * maxn][2], tot;

void add(int k, int p) {
    q[tot][0] = k;
    q[tot][1] = p;
    tot++;
}

int main() {
    int n;
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    REP(i, 2) {
        scanf("%d", &m[i]);
        REP(j, m[i]) scanf("%d", &a[i][j]);
        REP(j, n) nb[i][j] = m[i];
        dp[i][0] = 0;
        add(i, 0);
    }
    int k, x;
    REP(i, tot) {
        k = q[i][0], x = q[i][1];
        if (dp[k][x] == 0) {
            REP(j, m[k ^ 1]) {
                int y = (x + n - a[k ^ 1][j]) % n;
                if (dp[k ^ 1][y] == -1) {
                    dp[k ^ 1][y] = 1;
                    add(k ^ 1, y);
                }
            }
        } else {
            REP(j, m[k ^ 1]) {
                int y = (x + n - a[k ^ 1][j]) % n;
                nb[k ^ 1][y]--;
                if (nb[k ^ 1][y] == 0 && dp[k ^ 1][y] == -1) {
                    dp[k ^ 1][y] = 0;
                    add(k ^ 1, y);
                }
            }
        }
    }
    REP(i, 2) REPP(j, 1, n) {
        if (dp[i][j] == -1) cout << "Loop ";
        else if (dp[i][j] == 0) cout << "Lose ";
        else cout << "Win ";
        if (j == n - 1) cout << endl;
    }
    return 0;
}

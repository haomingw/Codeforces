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
#define REPP(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 305;
int a[3];
double dp[maxn][maxn][maxn];

int main() {
    int n;
    scanf("%d", &n);
    int x;
    REP(i, n) {
        scanf("%d", &x);
        a[x - 1]++;
    }
    double p = 1. / n;
    REP(k, n + 1) REP(j, n + 1) REP(i, n + 1) {
        x = n - i - j - k;
        if (x == n) continue;
        if (x < 0) break;
        if (i) dp[i][j][k] += dp[i - 1][j][k] * i * p;
        if (j) dp[i][j][k] += dp[i + 1][j - 1][k] * j * p;
        if (k) dp[i][j][k] += dp[i][j + 1][k - 1] * k * p;
        dp[i][j][k] += 1;
        dp[i][j][k] /= 1 - x * p;
    }
    printf("%.10f\n", dp[a[0]][a[1]][a[2]]);
    return 0;
}

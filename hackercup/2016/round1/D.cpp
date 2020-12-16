#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
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

const int maxn = 1e9;
int dp[maxn][maxn];

int calc(int n) {
    int cnt = 0;
    while (n > 1) {
        cnt++;
        n /= 2;
    }
    return cnt;
}



int solve(int n) {
    int w[n][n], v[n];
    int K = calc(n);
    REP(i, n) REP(j, n) {
        cin >> w[i][j];
        v[i] += w[i][j];
    }
    int best[n], worst[n];
    REP(i, n) {
        if (v[i] == n - 1) worst[i] = 1;
        else worst[i] = n / 2 + 1;
    }
    REP(i, n) dp[1 << i][i] = 1;
    if (n == 1) return !printf("1 1");
    if (n == 2) {

    }
    for (int i = 2; i <= n; i *= 2) {

    }

    return 0;
}

int main() {
    int T, N;
    cin >> T;
    REP(t, T) {
        cin >> N;
        cout << "Case #" << t + 1 << ":" << endl;
        solve();
    }
    return 0;
}

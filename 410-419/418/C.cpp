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
#include <cassert>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1505;
int dp[26][maxn], a[maxn];

int main() {
    int n, q; cin >> n;
    string s; cin >> s;
    cin >> q;
    REP(i, 26) {
        REP(j, n) a[j + 1] = a[j] + (s[j] - 'a' == i);
        REP(j, n) REPP(k, j, n) {
            int sum = a[k + 1] - a[j];
            int x = k - j + 1 - sum;
            dp[i][x] = max(dp[i][x], k - j + 1);
        }
        REP(j, n) dp[i][j + 1] = max(dp[i][j], dp[i][j + 1]);
    }

    int m;
    char c;
    REP(i, q) {
        scanf("%d %c", &m, &c);
        cout << dp[c - 'a'][m] << endl;
    }
    return 0;
}

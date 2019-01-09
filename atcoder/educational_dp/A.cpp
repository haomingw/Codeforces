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

const int maxn = 1e5 + 5;
int a[maxn], dp[maxn];

int main() {
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    dp[1] = abs(a[1] - a[0]);
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]),
                    dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    cout << dp[n - 1] << endl;
    return 0;
}

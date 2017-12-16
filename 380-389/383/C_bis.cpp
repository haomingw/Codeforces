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

const int maxn = 110;
int a[maxn], dt[maxn];
bool used[maxn];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int dfs(int x) {
    if (used[x] != 0) return 0;
    used[x] = true;
    return 1 + dfs(a[x]);
}

int main() {
    int n, ans = 1;
    cin >> n;
    REP(i, n) scanf("%d", a + i), a[i]--, dt[a[i]]++;
    REP(i, n) if (dt[i] != 1) return !printf("-1\n");
    REP(i, n) {
        if (!used[i]) {
            int len = dfs(i);
            ans = lcm(ans, len & 1 ? len : len / 2);
        }
    }
    cout << ans << endl;
    return 0;
}

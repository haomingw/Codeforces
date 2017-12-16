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
int a[maxn], b[maxn], c[maxn], d[maxn];

int main() {
    int n, m;
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", &a[i], &b[i]);
    scanf("%d", &m);
    REP(i, m) scanf("%d%d", &c[i], &d[i]);
    sort(a, a + n), sort(b, b + n);
    sort(c, c + m), sort(d, d + m);
    int ans = max(c[m - 1] - b[0], a[n - 1] - d[0]);
    ans = max(ans, 0);
    cout << ans << endl;
    return 0;
}

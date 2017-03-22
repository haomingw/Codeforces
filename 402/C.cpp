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
int a[maxn], b[maxn];
vector<pii> c;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", &a[i]);
    REP(i, n) scanf("%d", &b[i]);
    REP(i, n) {
        c.push_back(MP(a[i] - b[i], i));
    }
    sort(ALL(c));
    int ans = 0;
    REP(i, n) {
        int x = c[i].second;
        if (i < k) ans += a[x];
        else ans += min(a[x], b[x]);
    }
    cout << ans << endl;
    return 0;
}

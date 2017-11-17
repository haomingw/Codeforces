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

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
const int maxn = 105;
int a[maxn];

int main() {
    int n;
    scanf("%d", &n);
    REP(i, 2 * n) scanf("%d", a + i);
    vector<int> v;
    int ans = inf;
    REP(i, 2 * n) REPP(j, i + 1, 2 * n) {
        v.clear();
        REP(k, 2 * n) if (k != i && k != j)
            v.push_back(a[k]);
        sort(ALL(v));
        int sum = 0;
        REP(k, n - 1) {
            sum += v[2 * k + 1] - v[2 * k];
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}

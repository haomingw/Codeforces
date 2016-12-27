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

const int maxn = 2e5 + 10;
int a[maxn];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", &a[i]);
    vector<int> pos;
    REP(i, n) if (a[i] < 0) pos.push_back(i);
    int cnt = SIZE(pos), ans = 2 * cnt;
    if (cnt > k) return !printf("-1\n");
    if (cnt == 0) return !printf("%d\n", ans);
    int rest = k - cnt, d[cnt];
    REP(i, cnt - 1) d[i] = pos[i + 1] - pos[i];
    sort(d, d + cnt - 1);
    REP(i, cnt - 1) {
        // clog << rest << " " << d[i] - 1 << endl;
        if (rest >= d[i] - 1) {
            rest -= d[i] - 1; ans -= 2;
        } else break;
    }
    if (rest >= n - 1 - pos.back()) ans--;
    cout << ans << endl;
    return 0;
}

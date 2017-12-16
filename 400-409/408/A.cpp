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

const int inf = 1e5;
int a[105];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    REP(i, n) cin >> a[i];
    int ans = inf;
    REPP(i, m, n) {
        if (a[i] == 0) continue;
        if (a[i] <= k) {
            ans = (i - m + 1) * 10;
            break;
        }
    }
    for (int i = m - 2; i >= 0; i--) {
        if (a[i] == 0) continue;
        if (a[i] <= k) {
            ans = min((m - 1 - i) * 10, ans);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

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
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 105;
string s[105];

int main() {
    int n, m;
    cin >> n >> m;
    REP(i, n) cin >> s[i];
    int x1 = inf, y1 = inf, x2 = 0, y2 = 0, cnt = 0;
    REP(i, n) REP(j, m) if (s[i][j] == 'B') {
        cnt++;
        x1 = min(x1, i); y1 = min(y1, j);
        x2 = max(x2, i); y2 = max(y2, j);
    }
    if (cnt == 0) return !printf("1\n");
    int ans, a = max(x2 - x1 + 1, y2 - y1 + 1);
    if (a > min(n, m)) ans = -1;
    else ans = a * a - cnt;
    cout << ans << endl;
    return 0;
}


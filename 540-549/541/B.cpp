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
int a[maxn], b[maxn];

int main() {
    int n;
    scanf("%d", &n);
    REPP(i, 1, n + 1) scanf("%d%d", a + i, b + i);
    int ans = 1;
    REPP(i, 1, n + 1) {
        if (a[i - 1] == b[i - 1]) {
            ans += min(a[i], b[i]) - a[i - 1];
            continue;
        }
        int x = min(a[i], b[i]) - max(a[i - 1], b[i - 1]) + 1;
        ans += max(x, 0);
    }
    cout << ans << endl;
    return 0;
}

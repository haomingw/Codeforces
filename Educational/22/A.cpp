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

int main() {
    int n, m, x, sum = 0;
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d", &x);
        sum += x;
    }
    int l, r, ans = sum;
    bool found = false;
    scanf("%d", &m);
    REP(i, m) {
        scanf("%d%d", &l, &r);
        if ((ans >= l && ans <= r) || ans < l) {
            ans = max(ans, l);
            found = true;
            break;
        }
    }
    if (found) printf("%d\n", ans);
    else printf("-1\n");
    return 0;
}

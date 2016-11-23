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

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], sa[n + 1], ans = 0;
    REP(i, n) {
        scanf("%d", &a[i]);
        sa[i + 1] = sa[i] + a[i];
    }
    int l, r;
    REP(i, m) {
        scanf("%d%d", &l, &r);
        int tmp = sa[r] - sa[l - 1];
        if (tmp > 0) ans += tmp;
    }
    cout << ans << endl;
    return 0;
}

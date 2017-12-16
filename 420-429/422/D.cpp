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

const int mod = 1e9 + 7;
const int maxn = 5e6 + 5;
int p[maxn];

ll solve(int x) {
    ll res = 0;
    while (x > 1) {
        res += 1LL * x * (p[x] - 1) / 2;
        x /= p[x];
    }
    return res;
}

int main() {
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    REP(i, maxn) p[i] = -1;
    REPP(i, 2, maxn) {
        if (p[i] != -1) continue;
        for (int j = i; j < maxn; j += i)
            if (p[j] == -1) p[j] = i;
    }
    int ans = 0;
    for (int i = r; i >= l; i--) {
        ans = (1LL * t * ans + solve(i)) % mod;
    }
    cout << ans << endl;
    return 0;
}

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

const int maxn = 1e5 + 5;
int n, budget, a[maxn];
ll cost, x[maxn];

bool afford(int k) {
    REP(i, n) x[i] = a[i] + 1LL * (i + 1) * k;
    sort(x, x + n);
    ll sum = 0;
    REP(i, k) sum += x[i];
    bool ok = budget >= sum;
    if (ok) cost = sum;
    return ok;
}

int main() {
    scanf("%d%d", &n, &budget);
    REP(i, n) scanf("%d", &a[i]);
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (afford(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << hi << " " << cost << endl;
    return 0;
}

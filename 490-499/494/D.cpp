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

const int maxn = 2e5 + 5;
int a[maxn], b[32];

int solve(int x) {
    int cnt = 0, t;
    PER(i, 32) {
        t = min(x / (1 << i), b[i]);
        cnt += t;
        x -= t * (1 << i);
    }
    return (x == 0) ? cnt : -1;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) REP(j, 32) if (a[i] & (1 << j)) b[j]++;
    int x;
    while (q--) {
        scanf("%d", &x);
        printf("%d\n", solve(x));
    }
    return 0;
}

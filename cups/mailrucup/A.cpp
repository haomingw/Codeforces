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

const int maxn = 1005;
int n, s, a[maxn], b[maxn];

bool solve() {
    if (a[0] == 0) return false;
    if (a[s]) return true;
    if (b[s] == 0) return false;
    REP(i, n) if (a[i] && i >= s) {
        if (b[i]) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &s);
    s--;
    REP(i, n) scanf("%d", a + i);
    REP(i, n) scanf("%d", b + i);
    printf(solve() ? "YES\n" : "NO\n");
    return 0;
}

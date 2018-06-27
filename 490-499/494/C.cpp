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

const int maxn = 5005;
int a[maxn], b[maxn];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) b[i + 1] = b[i] + a[i];
    double ans = 0;
    REPP(i, k, n + 1) REP(j, n - i + 1)
        ans = max(double(b[j + i] - b[j]) / i, ans);
    printf("%.8f\n", ans);
    return 0;
}

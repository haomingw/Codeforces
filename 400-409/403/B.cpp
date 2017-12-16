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

const int maxn = 60005;
int a[maxn], v[maxn];

int main() {
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%d", &a[i]);
    REP(i, n) scanf("%d", &v[i]);
    double t0 = 0, t1 = 1e9;
    while (t1 - t0 > 1e-10) {
        double t = (t0 + t1) / 2;
        double lmax = 0, rmin = 1e9;
        REP(i, n) {
            lmax = max(lmax, a[i] - t * v[i]);
            rmin = min(rmin, a[i] + t * v[i]);
        }
        if (lmax < rmin) t1 = t;
        else t0 = t;
    }
    printf("%.10f\n", t1);
    return 0;
}

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
typedef pair<double, int> pdi;

const int maxn = 1e5 + 5;
int a[maxn], b[maxn];
vector<pdi> t;

int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    ll sum = 0;
    REP(i, n) scanf("%d%d", &a[i], &b[i]), sum += a[i];
    if (p >= sum) return !printf("-1\n");
    REP(i, n) t.push_back(MP(double(b[i]) / a[i], i));
    sort(ALL(t));
    double l = t[0].first, h = 1e10;
    while (h - l > 1e-6) {
        double mid = (h + l) / 2, tot = 0.0;
        REP(i, n) {
            int ind = t[i].second;
            if (mid > t[i].first)
                tot += (mid - t[i].first) * a[ind];
        }
        if (tot > mid * p) h = mid;
        else l = mid;
    }
    printf("%.6f\n", l);
    return 0;
}

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

const int maxn = 1e5 + 5;
int n, m, l, a[maxn];
bool ready[maxn];

int main() {
    scanf("%d%d%d", &n, &m, &l);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) if (a[i] > l) ready[i] = true;
    int cnt = 0, ptr = 0;
    while (ptr < n) {
        if (ready[ptr]) {
            cnt++;
            while (ptr < n && ready[ptr]) ptr++;
        } else ptr++;
    }
    int q, p, d;
    REP(i, m) {
        scanf("%d", &q);
        if (q) {
            scanf("%d%d", &p, &d);
            p--;
            a[p] += d;
            if (!ready[p] && a[p] > l) {
                ready[p] = true;
                if (p == 0) {
                    if (!ready[p + 1]) cnt++;
                } else if (p == n - 1) {
                    if (!ready[p - 1]) cnt++;
                } else {
                    if (ready[p - 1] && ready[p + 1]) cnt--;
                    if (!ready[p - 1] && !ready[p + 1]) cnt++;
                }
            }
        } else {
            printf("%d\n", cnt);
        }
    }
    return 0;
}

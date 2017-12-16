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

const int maxn = 2e5 + 5;
int a[maxn], b[maxn];

int main() {
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);
    int l, r;
    REP(i, n) {
        scanf("%d%d", &l, &r);
        a[l]++, a[r + 1]--;
    }
    REPP(i, 1, maxn) {
        a[i] += a[i - 1];
        if (a[i] >= k) b[i] = 1;
    }
    REP(i, maxn - 1) b[i + 1] += b[i];
    REP(i, q) {
        scanf("%d%d", &l, &r);
        cout << b[r] - b[l - 1] << endl;
    }
    return 0;
}

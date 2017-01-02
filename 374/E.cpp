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

const int maxn = 1e5 + 5;
int L, n, p, t, l, r, f[maxn], g[maxn];

void update(int i, int w, int pos) {
    if (f[i] < w) f[i] = w, g[i] = pos;
    else if (f[i] == w) g[i] = min(g[i], pos);
}

int main() {
    scanf("%d%d%d%d", &L, &n, &p, &t);
    g[0] = -t;
    for (int i = 1, j = 0; i <= n; i++) {
        scanf("%d%d", &l, &r);
        if (j) j--;
        while (j < i && g[j] + t < r) {
            l = max(l, g[j] + t);
            update(i, f[j] + (r - l) / p, l + (r - l) / p * p);
            j++;
        }
        update(i, f[i - 1], g[i - 1]);
    }
    cout << f[n] << endl;
    return 0;
}

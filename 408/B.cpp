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

const int maxn = 1e6 + 5;
bool a[maxn];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int u, v;
    REP(i, m) {
        scanf("%d", &u);
        a[u] = true;
    }
    int x = 1;
    REP(i, k) {
        if (a[x]) return !printf("%d\n", x);
        scanf("%d%d", &u, &v);
        if (u == x) x = v;
        else if (v == x) x = u;
    }
    cout << x << endl;
    return 0;
}

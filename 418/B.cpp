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

const int maxn = 1005;
int a[maxn], b[maxn], c[maxn];
bool used[maxn];

int main() {
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) scanf("%d", b + i);
    vector<int> d, e;
    REP(i, n) {
        if (a[i] != b[i]) d.push_back(i);
        else used[a[i]] = true, c[i] = a[i];
    }
    REPP(i, 1, n + 1) if (!used[i]) e.push_back(i);
    int x, y;
    if (d.size() == 1) {
        x = d[0];
        c[x] = e[0];
    } else {
        x = d[0], y = d[1];
        c[x] = e[0], c[y] = e[1];
        if ((c[x] != a[x] && c[y] != a[y]) || (c[x] != b[x] && c[y] != b[y]))
            swap(c[x], c[y]);
    }
    REP(i, n) cout << c[i] << " ";
    cout << endl;
    return 0;
}

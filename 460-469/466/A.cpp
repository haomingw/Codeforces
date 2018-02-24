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

const int maxn = 105;
int a[maxn], b[maxn];

int main() {
    int n, d;
    cin >> n >> d;
    REP(i, n) cin >> a[i];
    sort(a, a + n);
    int ans = n - 1;
    REP(i, n) REPP(j, i + 1, n) {
        if (a[j] - a[i] <= d) ans = min(ans, n - (j - i + 1));
    }
    cout << ans << endl;
    return 0;
}

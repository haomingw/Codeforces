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

const int maxn = 1e5 + 5;
int n, a[maxn], b1[maxn], b2[maxn];

void solve() {
    cin >> n;
    REP(i, n) cin >> a[i];
    int n1 = 0, n2 = 0;
    REP(i, n) {
        if (i & 1) b2[n2++] = a[i];
        else b1[n1++] = a[i];
    }
    sort(b1, b1 + n1);
    sort(b2, b2 + n2);
    n1 = n2 = 0;
    REP(i, n) {
        if (i & 1) a[i] = b2[n2++];
        else a[i] = b1[n1++];
    }
    REP(i, n - 1) if (a[i] > a[i + 1]) {
        cout << i << endl;
        return;
    }
    cout << "OK" << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}

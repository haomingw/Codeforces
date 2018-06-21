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
int a[maxn];

int main() {
    int n, k;
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    int l = 0, r = n - 1;
    REP(i, n) {
        if (a[i] <= k) l++;
        else break;
    }
    PER(i, n) {
        if (a[i] <= k) r--;
        else break;
    }
    int ans = n - max(r - l + 1, 0);
    cout << ans << endl;
    return 0;
}

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

const int maxn = 1e6 + 5;
int a[maxn], b[maxn];

int main() {
    int n, id = 0, cnt = 0;
    scanf("%d", &n);
    ll diff = 0;
    REPP(i, 1, n + 1) {
        scanf("%d", &a[i]);
        if (a[i] > i) b[a[i] - i]++, cnt++;
        diff += abs(a[i] - i);
    }
    ll ans = diff;
    REPP(i, 1, n) {
        int last = a[n - i + 1];
        diff += last - 1 - (n - last);
        diff += n - 2 * cnt - 1;
        if (diff < ans) ans = diff, id = i;
        cnt -= b[i];
        if (last > 1) {
            cnt++;
            if (last - 1 + i <= n) b[last - 1 + i]++;
        }
    }
    cout << ans << " " << id << endl;
    return 0;
}





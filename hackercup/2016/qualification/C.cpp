#include <iostream>
#include <cstdio>
#include <cmath>
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

const int maxn = 1e5 + 10;
ll a[maxn], b[maxn];

ll solve(int n, int p) {
    ll x;
    REP(i, n) {
        cin >> x;
        b[i] = x;
        a[i+1] = a[i] + x;
    }
    int l = 0, h = upper_bound(a, a + n + 1, p) - a - 1;
    int nb = h - l;
    ll ans = 0, sum = a[h];
    ans += nb;
    REP(i, n - 1) {
        l++;
        h = max(l, h);
        sum = a[h] - a[l];
        while (h < n) {
            if (sum + b[h] <= p) {
                sum += b[h];
                h++;
            } else break;
        }
        nb = h - l;
        ans += nb;
    }
    return ans;
}

int main() {
    int T, N, P;
    cin >> T;
    REP(t, T) {
        cin >> N >> P;
        cout << "Case #" << t + 1 << ": " << solve(N, P) << endl;
    }
    return 0;
}

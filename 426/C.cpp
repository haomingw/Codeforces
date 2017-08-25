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

int n, a, b;

bool solve(ll x) {
    int l = 1, r = 1e6, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        ll res = 1LL * mid * mid * mid;
        if (res < x) l = mid + 1;
        else if (res > x) r = mid - 1;
        else {
            ans = mid;
            break;
        }
    }
    return ans && a % ans == 0 && b % ans == 0;
}

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d %d", &a, &b);
        ll product = 1LL * a * b;
        cout << (solve(product) ? "YES" : "NO") << endl;
    }
    return 0;
}

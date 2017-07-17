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

ll diff(ll a) {
    ll res = a;
    while (a) {
        res -= a % 10;
        a /= 10;
    }
    return res;
}

int main() {
    ll n, s;
    cin >> n >> s;
    ll lo = 0, hi = 2e18;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (diff(mid) >= s) hi = mid;
        else lo = mid + 1;
    }
    cout << max(n - lo + 1, 0LL) << endl;
    return 0;
}

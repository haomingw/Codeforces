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

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> p;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            p.push_back(i);
            if (n / i != i) p.push_back(n / i);
        }
    }
    sort(ALL(p));
    if (SIZE(p) < k) cout << -1 << endl;
    else cout << p[k - 1] << endl;
    return 0;
}

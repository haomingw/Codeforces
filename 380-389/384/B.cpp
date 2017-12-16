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

ll solve(ll n, ll k) {
    k--;
    ll len = (1LL << n) - 1;
    while (k != len / 2) {
        if (k > len / 2) k -= len / 2 + 1;
        len = ((len + 1) >> 1) - 1;
        n--;
    }
    return n;
}

int main() {
    ll n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}

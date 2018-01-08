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
    int n, k;
    cin >> n >> k;
    k = min(k, n - k);
    int cur = 1, cycle = 0;
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        int to = (cur + k - 1) % n + 1;
        if (to < cur && to != 1) cycle++;
        ans += cycle + 1;
        if (to < cur) cycle++;
        cur = to;
        cout << ans << " ";
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define FOR(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define maxn 300010

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
ll t[maxn], w[maxn];
priority_queue<pll, vector<pll>, greater<pll> > pq1;
priority_queue<pll> pq2;

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%lld %lld", &t[i], &w[i]);
        if (i) {
            if (t[i] > t[0]) pq1.push({w[i] - t[i] + 1, t[i]});
            else pq2.push({t[i], w[i]});
        }
    }
    int ans = SIZE(pq1) + 1;
    while (t[0] >= 0 && !pq1.empty()) {
        pll p = pq1.top(); pq1.pop();
        if (p.first > t[0]) break;
        t[0] -= p.first;
        while (!pq2.empty() && pq2.top().first > t[0]) {
            pll q = pq2.top(); pq2.pop();
            pq1.push({q.second - q.first + 1, q.first});
        }
        ans = min(ans, SIZE(pq1) + 1);
    }
    cout << ans << endl;
    return 0;
}

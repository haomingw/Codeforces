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

const int maxn = 2e6 + 5;
int n, k, c[maxn], sum;

int query(int x){
    int s = 0;
    for (; x; x -= x & -x) s += c[x];
    return s;
}

void modify(int x, int s) {
    for (; x <= n; x += x & -x) c[x] += s;
    sum += s;
}

int Query(int x) {
    if (x > n) return query(x - n) + sum;
    else if (x < 0) return query(x + n) - sum;
    else return query(x);
}

int main() {
    cin >> n >> k;
    k = min(k, n - k);
    int x = 1;
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        int b = Query(x + k - 1) - Query(x - k);
        ans += b + 1;
        modify(x, 1);
        x = (x + k - 1) % n + 1;
        cout << ans << " ";
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
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
typedef pair<ll, int> pli;

const int maxn = 1e9 + 10;
int l, n, m, d;
ll a[maxn];

ll solve() {
    ll w[n], lm[n];
    priority_queue<pli, vector<pli>, greater<pli> > pq;
    REP(i, n) {
        cin >> w[i];
        pq.push(MP(w[i], i));
    }
    int cnt = -1;
    fill(a, a + m, 0);
    REP(i, l) {
        cnt++;
        if (cnt >= m) cnt -= m;
        pli p = pq.top(); pq.pop();
        pq.push(MP(p.first + w[p.second], p.second));
        a[cnt] = max(a[cnt], p.first) + d;
    }
    return a[cnt];
}

int main() {
    int T;
    cin >> T;
    REP(t, T) {
        cin >> l >> n >> m >> d;
        const clock_t begin_time = clock();
        cout << "Case #" << t + 1 << ": " << solve() << endl;
        clog << "Case #" << t + 1 << ", time: "
             << float( clock () - begin_time ) /  CLOCKS_PER_SEC * 1000 << "ms" << endl;
    }
    return 0;
}

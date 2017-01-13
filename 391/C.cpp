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

const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
vector<int> t[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int g, x;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &g);
        while (g--) {
            scanf("%d", &x);
            t[x].push_back(i);
        }
    }
    sort(t + 1, t + m + 1);
    int ans = 1, cnt = 1;
    for (int i = 2; i <= m; i++) {
        if (t[i] == t[i - 1]) {
            cnt++;
            ans = 1LL * ans * cnt % mod;
        } else cnt = 1;
    }
    cout << ans << endl;
    return 0;
}

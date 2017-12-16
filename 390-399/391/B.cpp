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

const int maxn = 1e5 + 5;
int cnt[maxn];

int main() {
    int x, n, ans = 1;
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 2; i < maxn; i++) {
        int t = 0;
        for (int j = i; j < maxn; j += i) t += cnt[j];
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}

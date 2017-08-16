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

const int maxn = 2e5 + 5;

int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int t, ans = 0, c = 0;
    REP(i, n) {
        scanf("%d", &t);
        if (t == 1) {
            if (a > 0) a--;
            else if (b > 0) b--, c++;
            else if (c > 0) c--;
            else ans++;
        } else {
            if (b > 0) b--;
            else ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}

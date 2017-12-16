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
bool a[maxn];

int main() {
    int n;
    scanf("%d", &n);
    int x, ans = 0, cnt = 0;
    REP(i, 2 * n) {
        scanf("%d", &x);
        if (!a[x]) a[x] = true, cnt++;
        else a[x] = false, cnt--;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}

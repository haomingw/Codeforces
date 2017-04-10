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
int a[maxn];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int ans = 0;
    REP(i, n) {
        scanf("%d", &a[i]);
        ans += a[i] / k + (a[i] % k != 0);
    }
    ans = ans / 2 + (ans & 1);
    cout << ans << endl;
    return 0;
}

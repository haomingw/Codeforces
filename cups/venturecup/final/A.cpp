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

const int maxn = 2e5 + 5;
int p[maxn];
bool used[maxn];

int main() {
    int n, x, t = 0;
    scanf("%d", &n);
    REPP(i, 1, n + 1) scanf("%d", &p[i]);
    REP(i, n) {
        scanf("%d", &x);
        t += x;
    }
    int ans = 0;
    REPP(i, 1, n + 1) {
        if (!used[i]) {
            ans++;
            int j = i;
            while (!used[j]) {
                used[j] = true;
                j = p[j];
            }
        }
    }
    if (ans == 1) ans = 0;
    if (!(t & 1)) ans++;
    cout << ans << endl;
    return 0;
}


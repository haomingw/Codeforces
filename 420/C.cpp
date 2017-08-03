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

const int maxn = 3e5 + 5;
int a[maxn];
char c[10];

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0, top = 0, cnt = 1, limit = 0;
    REP(i, 2 * n) {
        scanf("%s", c);
        if (c[0] == 'a') { // add element
            scanf("%d", &a[top++]);
        } else { // remove
            if (a[top - 1] != cnt) {
                if (top > limit) limit = top - 1, ans++;
                else limit--;
            }
            top--, cnt++;
        }
    }
    cout << ans << endl;
    return 0;
}

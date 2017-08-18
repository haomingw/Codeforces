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

const int maxn = 2e6 + 5;

int main() {
    int n, k, p, len = 0;
    scanf("%d", &n);
    string s, ans = "";
    REP(i, maxn) ans += " ";
    REP(i, n) {
        cin >> s;
        int m = s.size(), prev = -m;
        scanf("%d", &k);
        REP(i, k) {
            scanf("%d", &p);
            p--;
            len = max(len, p + m);
            for (int j = max(0, prev + m - p); j < m; j++)
                ans[p + j] = s[j], prev = p;
        }
    }
    ans = ans.substr(0, len);
    REP(i, len) if (ans[i] == ' ') ans[i] = 'a';
    cout << ans << endl;
    return 0;
}


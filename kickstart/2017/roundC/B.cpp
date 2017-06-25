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
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

string s[55];

void solve() {
    int n, a, b;
    cin >> n;
    REP(i, n) cin >> s[i];

    REP(i, n) REP(j, n) if (s[i][j] == 'X') {
        a = b = 0;
        REP(k, n) if (s[i][k] == 'X') a++;
        REP(k, n) if (s[k][j] == 'X') b++;
        if (!((a == 1 && b == 1) || (a == 2 && b == 2))) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    REP(i, n) REP(j, n) if (s[i][j] == 'X') {
        a = b = 0;
        REPP(k, j + 1, n) if (s[i][k] == 'X') {
            b = k - j;
            break;
        }
        REPP(k, i + 1, n) if (s[k][j] == 'X') {
            a = k - i;
            break;
        }
        if (s[i][j + b] == 'X' && s[i + a][j] == 'X' && s[i + a][j + b] == 'X') {
            s[i][j] = '.';
            s[i][j + b] = '.';
            s[i + a][j] = '.';
            s[i + a][j + b] = '.';
        }
    }
    // REP(i, n) clog << s[i] << endl;
    REP(i, n) REP(j, n) if (s[i][j] == 'X') {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << "POSSIBLE" << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}

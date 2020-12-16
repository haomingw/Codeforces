#include <iostream>
#include <cstdio>
#include <cmath>
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

int n;
char c[2][1005];

int solve() {
    int debut = 0, fin = n -1;
    bool flag = false;
    vector<pii> segs[2];
    REP(i, 2) REP(j, n) {
        if (c[i][j] == '.') {
            if (!flag) debut = j;
            flag = true;
            if (j == n - 1) {
                segs[i].push_back(MP(debut, n));
                flag = false;
            }
        } else {
            if (flag) segs[i].push_back(MP(debut, j));
            flag = false;
        }
    }
    int len = SIZE(segs[0]) + SIZE(segs[1]), cnt = 0;
    REP(i, 2) REP(j, SIZE(segs[i])) {
        pii p = segs[i][j];
        int d = p.second - p.first, r = abs(i - 1);
        if (d == 1 && c[r][p.first] == '.') {
            int ind = p.first;
            c[i][ind] = 'X';
            while (c[r][ind] == '.' && ind >= 0) c[r][ind--] = 'X';
            ind = p.first + 1;
            while (c[r][ind] == '.' && ind < n) c[r][ind++] = 'X';
            cnt++;
        }
    }
    // clog << c[0] << endl << c[1] << endl;
    return len - cnt;
}

int main() {
    int T;
    cin >> T;
    REP(t, T) {
        cin >> n;
        cin >> c[0] >> c[1];
        cout << "Case #" << t + 1 << ": " << solve() << endl;
    }
    return 0;
}

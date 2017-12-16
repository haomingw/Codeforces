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

const int inf = 510;

int main() {
    int n, m;
    cin >> n >> m;
    char grid[n][m];
    int xmin = inf, xmax = 0, ymin = inf, ymax = 0;
    REP(i, n) REP(j, m) {
        cin >> grid[i][j];
        if (grid[i][j] == 'X') {
            xmin = min(i, xmin);
            xmax = max(i, xmax);
            ymin = min(j, ymin);
            ymax = max(j, ymax);
        }
    }
    REPP(i, xmin, xmax + 1) REPP(j, ymin, ymax + 1) {
        if (grid[i][j] != 'X') return !printf("NO\n");
    }
    cout << "YES" << endl;
    return 0;
}

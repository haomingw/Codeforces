#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <utility>
#include <algorithm>
#include <map>
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

const int maxn = 2005;
bool grid[maxn][maxn], vis[maxn][maxn];
int n, m, r, c, x, y;

struct Node {
    int x, y, left, right;
};

int main() {
    cin >> n >> m;
    cin >> r >> c >> x >> y;
    r--, c--;
    string s;
    REP(i, n) {
        cin >> s;
        REP(j, m) grid[i][j] = s[j] == '.';
    }
    int ans = 0;
    deque<Node> nodes;
    nodes.push_back({r, c, x, y});
    while (!nodes.empty()) {
        Node node = nodes.front(); nodes.pop_front();
        x = node.x, y = node.y;
        if (vis[x][y]) continue;
        vis[x][y] = true, ans++;
        if (x > 0 && grid[x - 1][y])
            nodes.push_front({x - 1, y, node.left, node.right});
        if (x < n - 1 && grid[x + 1][y])
            nodes.push_front({x + 1, y, node.left, node.right});
        if (y > 0 && grid[x][y - 1] && node.left)
            nodes.push_back({x, y - 1, node.left - 1, node.right});
        if (y < m - 1 && grid[x][y + 1] && node.right)
            nodes.push_back({x, y + 1, node.left, node.right - 1});
    }
    cout << ans << endl;
    return 0;
}

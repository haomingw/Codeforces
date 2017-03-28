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

const int maxn = 150005;
vector<int> g[maxn];
bool used[maxn];
ll v, e;

void dfs(int x) {
    v++;
    used[x] = true;
    int n = SIZE(g[x]);
    e += n;
    REP(i, n) {
        if (!used[g[x][i]]) {
            dfs(g[x][i]);
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int a, b;
    REP(i, m) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    REPP(i, 1, n + 1) {
        if (!used[i]) {
            v = e = 0;
            dfs(i);
            if (v * (v - 1) != e) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
 }

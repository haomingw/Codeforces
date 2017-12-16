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

const int inf = 1e9;
const int maxn = 1e4 + 5;
bool fr[maxn], fc[maxn];
int n, m, k, dist[maxn];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
vector<pii> lights;
vector<int> row[maxn], col[maxn];
map<pii, int> label;
priority_queue<pii> todo;

void fillRow(int r, int val) {
    if (r >= 1 && r <= n && !fr[r]) {
        fr[r] = true;
        for (int x : row[r]) if (val < dist[x]) {
            dist[x] = val;
            todo.push(MP(-val, x));
        }
    }
}

void fillCol(int c, int val) {
    if (c >= 1 && c <= m && !fc[c]) {
        fc[c] = true;
        for (int x : col[c]) if (val < dist[x]) {
            dist[x] = val;
            todo.push(MP(-val, x));
        }
    }
}

void adj(int r, int c, int val) {
    if (label.count(MP(r, c))) {
        int x = label[MP(r, c)];
        if (val < dist[x]) {
            dist[x] = val;
            todo.push(MP(-val, x));
        }
    }
}

int main() {
    int r, c;
    scanf("%d%d%d", &n, &m, &k);
    REP(i, k) {
        scanf("%d%d", &r, &c);
        row[r].push_back(i);
        col[c].push_back(i);
        label[MP(r, c)] = i;
        lights.push_back(MP(r, c));
    }
    REP(i, maxn) dist[i] = inf;
    if (!label.count(MP(n, m))) {
        fillRow(n - 1, 1);
        fillRow(n, 1);
        fillCol(m - 1, 1);
        fillCol(m, 1);
    } else todo.push(MP(0, label[MP(n, m)]));

    while (!todo.empty()) {
        pii p = todo.top(); todo.pop();
        p.first = -p.first;
        if (p.first > dist[p.second]) continue;
        r = lights[p.second].first, c = lights[p.second].second;
        REP(i, 4) adj(r + dx[i], c + dy[i], p.first);
        REPP(i, r - 2, r + 3) fillRow(i, p.first + 1);
        REPP(i, c - 2, c + 3) fillCol(i, p.first + 1);
    }
    cout << (dist[0] == inf ? -1 : dist[0]) << endl;
    return 0;
}

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

int n, m, a, b;
char h[10005][105][105], s[105][105], dir[6] = "UDLR";
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

bool can(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '*');
}

int index(char c) {
    if (c == 'U') return 0;
    else if (c == 'D') return 1;
    else if (c == 'L') return 2;
    else return 3;
}

int search() {
    h[0][0][0] = '.';
    REP(k, 10005) REP(i, n) REP(j, m) if (h[k][i][j]) {
        REP(d, 4) {
            int px = i + dx[d], py = j + dy[d];
            if (can(px, py)) {
                h[k + 1][px][py] = dir[d];
                if (s[px][py] == 'F') {
                    return k + 1;
                }
            }
        }
    }
    return 0;
}

inline void flush() {
    fflush(stdout);
    cin >> a >> b;
}

int main() {
    cin >> n >> m;
    REP(i, n) cin >> s[i];
    REP(i, n) REP(j, m) if (s[i][j] == 'F') {
        a = i, b = j;
        break;
    }
    int K = search();
    //clog << "K: " << K << endl;
    string path = "";
    for (int i = K; i > 0; i--) {
        char c = h[i][a][b];
        int d = index(c);
        path = c + path;
        a -= dx[d], b -= dy[d];
    }
    //clog << path << endl;
    map<char, char> mp;
    mp['U'] = 'U', mp['D'] = 'D';
    mp['R'] = 'R', mp['L'] = 'L';

    bool f1 = true, f2 = true;
    REP(i, K) {
        cout << mp[path[i]] << endl;
        flush();
        if ((path[i] == 'L' || path[i] == 'R') && f1) {
            f1 = false;
            if (b == 1) {
                mp['L'] = 'R', mp['R'] = 'L';
                cout << mp[path[i]] << endl;
                flush();
            }
        }
        if ((path[i] == 'U' || path[i] == 'D') && f2) {
            f2 = false;
            if (a == 1) {
                mp['U'] = 'D', mp['D'] = 'U';
                cout << mp[path[i]] << endl;
                flush();
            }
        }
    }
    return 0;
}

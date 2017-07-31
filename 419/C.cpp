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

int n, m, a[105][105];
vector<int> row, col;

void removeRow() {
    bool remove = true;
    REP(i, n) {
        while (true) {
            remove = true;
            REP(j, m) if (a[i][j] == 0) remove = false;
            if (remove) {
                row.push_back(i + 1);
                REP(j, m) a[i][j]--;
            } else break;
        }
    }
}

void removeCol() {
    bool remove = true;
    REP(j, m) {
        while (true) {
            remove = true;
            REP(i, n) if (a[i][j] == 0) remove = false;
            if (remove) {
                col.push_back(j + 1);
                REP(i, n) a[i][j]--;
            } else break;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) REP(j, m) scanf("%d", &a[i][j]);
    if (n > m) {
        removeCol();
        removeRow();
    } else {
        removeRow();
        removeCol();
    }
    REP(i, n) REP(j, m)
        if (a[i][j] != 0) return !printf("-1\n");
    cout << row.size() + col.size() << endl;
    for (int x : row) cout << "row " << x << endl;
    for (int x : col) cout << "col " << x << endl;
    return 0;
}


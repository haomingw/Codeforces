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

const int maxn = 1005;
vector<int> tree[maxn];
int n;

bool solve() {
    int cnt;
    REPP(i, 1, n + 1) if (!tree[i].empty()) {
        cnt = 0;
        for (int x : tree[i]) {
            if (tree[x].empty()) cnt++;
        }
        if (cnt < 3) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    int x;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &x);
        tree[x].push_back(i);
    }
    cout << (solve() ? "Yes" : "No") << endl;
    return 0;
}

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

bool solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a, b;
    int x;
    REP(i, n) {
        scanf("%d", &x);
        if (x) a.push_back(x);
    }
    REP(i, m) {
        scanf("%d", &x);
        if (x) b.push_back(x);
    }
    n = a.size(), m = b.size();
    if (n != m) return true;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    REP(i, n) {
        if (a[i] != b[i]) return true;
    }
    return false;
}

int main() {
    int T; cin >> T;
    REP(i, T) {
        printf(solve() ? "Alice\n" : "Bob\n");
    }
    return 0;
}

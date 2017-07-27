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

int main() {
    int l[4], s[4], r[4], p[4];
    REP(i, 4) cin >> l[i] >> s[i] >> r[i] >> p[i];
    REP(i, 4) if (r[i] && (p[(i + 1) % 4] || p[i])) return !printf("YES\n");
    REP(i, 4) if (s[i] && (p[(i + 2) % 4] || p[i])) return !printf("YES\n");
    REP(i, 4) if (l[i] && (p[(i + 3) % 4] || p[i])) return !printf("YES\n");
    cout << "NO" << endl;
    return 0;
}

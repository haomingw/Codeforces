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

int main() {
    int x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x >> y;
    int dx = x2 - x1, dy = y2 - y1;
    if (dx % x != 0 || dy % y != 0)
        return !printf("NO\n");
    dx /= x, dy /= y;
    bool ko = (dx + dy) & 1 || abs(dx - dy) & 1;
    cout << (ko ? "NO" : "YES") << endl;
    return 0;
}

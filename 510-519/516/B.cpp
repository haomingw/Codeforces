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

int main() {
    int a, n, p[32];
    cin >> n;
    p[0] = 1;
    REP(i, 31) p[i + 1] = 2 * p[i];
    while (n--) {
        cin >> a;
        int cnt = 0;
        REP(i, 32) if (a & (1 << i)) cnt++;
        cout << p[cnt] << endl;
    }
    return 0;
}

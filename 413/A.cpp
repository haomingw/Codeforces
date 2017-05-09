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
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    int a = ((n - 1) / k + 1) * t;
    int b1 = 0, b2 = d;
    while (n > 0) {
        if (b1 > b2) swap(b1, b2);
        b1 += t, n -= k;
    }
    int b = max(b1, b2);
    if (a > b) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

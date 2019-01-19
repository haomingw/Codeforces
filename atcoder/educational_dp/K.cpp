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
#define REPP(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;
int a[105];
bool dp[maxn];

int main() {
    int n, k;
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    REPP(i, 1, k + 1) REP(j, n) {
        if (i < a[j]) break;
        if (!dp[i - a[j]]) dp[i] = true;
    }
    cout << (dp[k] ? "First" : "Second") << endl;
    return 0;
}

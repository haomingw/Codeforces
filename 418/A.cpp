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

const int maxn = 105;
int a[maxn], b[maxn];

int main() {
    int n, k;
    cin >> n >> k;
    if (k > 1) return !printf("Yes\n");
    REP(i, n) cin >> a[i];
    REP(i, k) cin >> b[i];
    REP(i, n) if (a[i] == 0) a[i] = b[0];
    REP(i, n - 1) if (a[i] > a[i + 1]) return !printf("Yes\n");
    cout << "No" << endl;
    return 0;
}

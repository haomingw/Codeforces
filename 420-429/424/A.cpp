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

int n, a[105];

bool check() {
    int p = 0;
    while (p < n - 1 && a[p] < a[p + 1]) p++;
    while (p < n - 1 && a[p] == a[p + 1]) p++;
    while (p < n - 1 && a[p] > a[p + 1]) p++;
    return p == n - 1;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", &a[i]);
    cout << (check() ? "YES" : "NO") << endl;
    return 0;
}


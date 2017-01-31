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
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

int a[55], b[55];

int main() {
    int n, L;
    cin >> n >> L;
    REP(i, n) scanf("%d", &a[i]);
    REP(i, n) scanf("%d", &b[i]);
    if (n == 1) return !printf("YES\n");
    vector<int> va, vb;
    REP(i, n - 1) va.push_back(a[i + 1] - a[i]);
    va.push_back(L - a[n - 1] + a[0]);
    REP(i, n - 1) vb.push_back(b[i + 1] - b[i]);
    vb.push_back(L - b[n - 1] + b[0]);
    REP(i, n) {
        if (va == vb) return !printf("YES\n");
        int x = va[0];
        va.push_back(x);
        va.erase(va.begin());
    }
    cout << "NO" << endl;
    return 0;
}

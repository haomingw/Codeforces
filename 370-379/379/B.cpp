#include <iostream>
#include <cstdio>
#include <cmath>
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

int main() {
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    int a = min(k2, min(k5, k6));
    int b = min(k3, k2 - a);
    int ans = 256 * a + 32 * b;
    cout << ans << endl;
    return 0;
}

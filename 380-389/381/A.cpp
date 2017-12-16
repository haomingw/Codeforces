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

int main() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll nb = 4 - n % 4, ans = 0;
    if (nb == 4) ans = 0;
    else if (nb == 1) ans = min(min(a, b + c), 3 * c);
    else if (nb == 2) ans = min(min(2 * a, b), 2 * c);
    else if (nb == 3) ans = min(min(a + b, c), 3 * a);
    cout << ans << endl;
    return 0;
}

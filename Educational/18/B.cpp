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

int a[105];
bool b[105];

int main() {
    int n, k;
    cin >> n >> k;
    REP(i, k) cin >> a[i];
    int p = 0, nb = n;
    REP(i, k) {
        int x = a[i] % nb--, cnt = 0;
        while (cnt < x) {
            p = (p + 1) % n;
            if (!b[p]) cnt++;
        }
        cout << p + 1 << " ";
        b[p] = true, p = (p + 1) % n;
        while (b[p]) p = (p + 1) % n;
    }
    cout << endl;
    return 0;
}

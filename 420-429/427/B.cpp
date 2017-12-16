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

const int maxn = 1e5 + 5;
int a[maxn];

int main() {
    int k;
    string s;
    cin >> k >> s;
    int n = s.size(), sum = 0;
    REP(i, n) a[i] = s[i] - '0';
    sort(a, a + n);
    REP(i, n) sum += a[i];
    if (sum >= k) return !printf("0\n");
    int diff = sum - k;
    REP(i, n) {
        diff += 9 - a[i];
        if (diff >= 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}

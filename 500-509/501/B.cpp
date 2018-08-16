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

const int maxn = 30;
int a[maxn], b[maxn];
string s, t;
vector<int> v;

void iSwap(int x, int y) {
    assert(y > x);
    int n = y - x;
    REP(i, n) {
        v.push_back(y - i);
        swap(s[y - i - 1], s[y - i]);
    }
}

int main() {
    int n;
    cin >> n >> s >> t;
    REP(i, n) {
        a[s[i] - 'a']++;
        b[t[i] - 'a']++;
    }
    REP(i, maxn) if (a[i] != b[i]) return !printf("-1\n");
    int pos = 0;
    REP(i, n) if (s[i] != t[i]) {
        REPP(j, i + 1, n) if (s[j] == t[i]) {
            pos = j;
            break;
        }
        iSwap(i, pos);
    }
    cout << v.size() << endl;
    REP(i, SZ(v)) cout << v[i] << " "; cout << endl;
    return 0;
}

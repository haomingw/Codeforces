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

int a[55];

int main() {
    int n, k;
    cin >> n >> k;
    REP(i, k - 1) a[i] = i;
    string s;
    REPP(i, k - 1, n) {
        cin >> s;
        if (s[0] == 'Y') a[i] = i;
        else a[i] = a[i - k + 1];
    }
    REP(i, n) {
        s = char('A' + a[i] / 26);
        s += char('a' + a[i] % 26);
        cout << s << " ";
    }
    cout << endl;
    return 0;
}

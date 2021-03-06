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
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    string a[2], s, t;
    cin >> a[0] >> a[1];
    cin >> n;
    cout << a[0] << " " << a[1] << endl;
    REP(i, n) {
        cin >> s >> t;
        int x = (s == a[0]) ? 0 : 1;
        a[x] = t;
        cout << a[0] << " " << a[1] << endl;
    }
    return 0;
}

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
#include <ctime>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;
const int maxn = 200;
int n, a[maxn];

void print(int x) {
    cout << x << endl;
    fflush(stdout);
}

void solve() {
    REP(i, maxn) a[i] = 0;
    cin >> n;
    int k, x;
    set<int> sold;
    vector<int> choices;
    REP(i, n) { // n customers
        choices.clear();
        cin >> k;
        if (k == 0) {
            print(-1);
            continue;
        }
        REP(j, k) {
            cin >> x;
            choices.push_back(x);
            a[x]++;
        }
        int minIndex = -1, minVal = inf;
        for (int x : choices) if (!sold.count(x)) {
            if (a[x] < minVal) minVal = a[x], minIndex = x;
        }
        if (minIndex < 0) {
            print(-1);
            continue;
        }
        vector<int> ps;
        for (int x : choices) if (!sold.count(x)) {
            if (a[x] == minVal) ps.push_back(x);
        }
        int index = rand() % SZ(ps);
        sold.insert(ps[index]);
        print(ps[index]);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    srand(std::time(nullptr));
    int T; cin >> T;
    REP(i, T) {
        solve();
    }
    return 0;
}

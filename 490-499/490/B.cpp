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

void rev(string& s, int n) {
    REP(i, n / 2) swap(s[i], s[n - 1 - i]);
}

int main() {
    int n; cin >> n;
    string s; cin >> s;
    REPP(i, 1, n + 1) if (n % i == 0) {
        rev(s, i);
    }
    cout << s << endl;
    return 0;
}

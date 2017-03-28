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

int a[50];
bool b[50];

string conv(int x) {
    string s = "A";
    while (x) {
        s += char('a' + x % 26);
        x /= 26;
    }
    return s;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    REP(i, n - k + 1) {
        cin >> s;
        b[i] = (s == "YES");
    }
    queue<int> q;
    REP(i, k) q.push(i);
    fill(a, a + 50, -1);
    REP(i, n - k + 1) {
        if (b[i]) {
            REP(j, k) if (a[i + j] == -1) a[i + j] = q.front(), q.pop();
            q.push(a[i]);
        } else {
            if (a[i] != -1) a[i + k - 1] = a[i];
        }
    }
    REP(i, n) if (a[i] == -1) a[i] = 0;
    REP(i, n) cout << conv(a[i] + 1) << " "; cout << endl;
    return 0;
}

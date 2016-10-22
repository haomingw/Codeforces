#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define FOR(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()

typedef pair<int, int> pii;
typedef long long ll;

unordered_map<char, ll> m({ {'f', 1}, {'e', 2}, {'d', 3}, {'a', 4}, {'b', 5}, {'c', 6}});
int main() {
    ll n, r, a, b, t, ans;
    char s;
    cin >> n >> s;
    n--;
    r = n / 4;
    t = n % 4;
    a = t % 2;
    b = 7 * a + m[s];

    ans = 16 * r + b;
    cout << ans << endl;
    return 0;
}

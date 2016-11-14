#include <iostream>
#include <cstdio>
#include <cmath>
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
    ll n, b, d;
    cin >> n >> b >> d;
    ll a, sum = 0, cnt = 0;
    REP(i, n) {
        cin >> a;
        if (a <= b) {
            sum += a;
            if (sum > d) {
                sum = 0;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

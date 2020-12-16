#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
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

int c[100010], s[100010], sum = 0;

double calc(int l, int h, int n) {
    if (l == sum || h == 0 || l == h) return 0.0;
    int ind1 = upper_bound(s, s + n + 1, l) - s - 1,
        ind2 = upper_bound(s, s + n + 1, h) - s - 1;
    double ans = 0.0;
    if (ind1 != ind2) {
        int r1 = c[ind1] - (l - s[ind1]), r2 = h - s[ind2];
        double m1 = (l - s[ind1] + c[ind1]) / 2.0, m2 = r2 / 2.0;
        REPP(i, ind1 + 1, ind2) {
            int len = s[i + 1] - s[i];
            ans += len * len / 2.0;
        }
        ans += (r1 * m1 + r2 * m2);
        ans /= h - l;
    } else {
        ans = (l + h - 2 * s[ind1]) / 2.0;
    }
    return ans;
}

double solve(int n, int a, int b) {
    double ans = 0.0;
    sum = 0;
    memset(s, 0, sizeof(s));
    REP(i, n) {
        cin >> c[i];
        s[i + 1] = s[i] + c[i];
        sum += c[i];
    }
    if (b > sum) {
        int x = a % sum == 0 ? a : (a / sum + 1) * sum, y = (b / sum) * sum;
        double p1 = double(x - a) / (b - a),
               p2 = double(y - x) / (b - a),
               p3 = double(b - y) / (b - a);
        ans = calc(a % sum, sum, n) * p1 + calc(0, sum, n) * p2 + calc(0, b % sum, n) * p3;
    } else {
        ans = calc(a, b, n);
    }
    return ans;
}

int main() {
    int T, N, A, B;
    cin >> T;
    REP(t, T) {
        cin >> N >> A >> B;
        printf("Case #%d: %.7f\n", t + 1, solve(N, A, B));
    }
    return 0;
}

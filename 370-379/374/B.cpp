#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int cal(int cnt, int k) {
    if (cnt == 0) return 0;
    int ans = cnt / k;
    if (cnt % k == 0) ans--;
    return ans;
}

int solve(int cnt, int k) {
    return cnt + 5 * cal(cnt, k);
}

const int l = 1005;

int main() {
    int n, k;
    cin >> n >> k;
    string s, pwd;
    int a[l];
    for (int i = 0; i < n; i++) {
        cin >> s;
        a[s.size()] += 1;
    }
    cin >> pwd;

    int len = pwd.size(), cnt = 0;
    for (int i = 0; i < len; i++) {
        cnt += a[i];
    }
    int best = solve(cnt + 1, k), worst = solve(cnt + a[len], k);
    cout << best << " " << worst << endl;
    return 0;
}

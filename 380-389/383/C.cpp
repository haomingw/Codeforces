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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int n, ans = 1;
    cin >> n;
    int a[n], visited[n];
    REP(i, n) scanf("%d", &a[i]);
    REP(i, n) a[i]--;
    fill(visited, visited + n, 0);
    unordered_map<int, int> hmap;
    REP(i, n) {
        int cnt = 1, next = a[i];
        if (visited[i] > 0) continue;
        visited[i] = 1;
        while (i != next) {
            if (visited[next] > 0) return !printf("-1\n"); // not a loop
            visited[next] = 1;
            cnt++;
            if (next != a[next]) next = a[next];
            else return !printf("-1\n");
        }
        hmap[a[i]] = cnt; // length
    }
    if (SIZE(hmap) == 0) return !printf("-1\n");
    for (auto it : hmap) {
        int val = it.second, tmp;
        tmp = val % 2 == 0 ? val / 2 : val;
        ans = lcm(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}

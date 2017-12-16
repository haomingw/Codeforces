#include <iostream>
#include <cstdio>
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

const int maxn = 1e6 + 10;
int ku[maxn], kd[maxn], posu[maxn], posd[maxn];
ll tl[maxn], tr[maxn];

int main() {
    int n;
    cin >> n;
    char s[maxn];
    scanf("%s", s + 1);
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        ku[i + 1] = ku[i] + (s[i] == 'U');
        kd[n - i] = kd[n - i + 1] + (s[n - i + 1] == 'D');
        tl[i] = tl[i - 1] + 2 * ku[i] + 1;
        tr[n - i + 1] = tr[n - i + 2] + 2 * kd[n - i + 1] + 1;
        if (s[i] == 'U') posu[a++] = i;
        else posd[b++] = i;
    }
    ll ans = 0, nb, ind;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'U') {
            if (ku[i] < kd[i]) {
                nb = kd[i] - ku[i] - 1;
                ind = posd[b - nb - 1];
                ans = tl[i] + tr[i] - tr[ind] - (2 * nb + 1) * (ind - i);
            } else {
                nb = ku[i] - kd[i];
                ind = posu[nb];
                ans = tl[i] + tr[i] - tl[ind] - (2 * nb + 1) * (i - ind);
            }
        } else {
            if (kd[i] < ku[i]) {
                nb = ku[i] - kd[i] - 1;
                ind = posu[nb];
                ans = tl[i] + tr[i] - tl[ind] - (2 * nb + 1) * (i - ind);
            } else {
                nb = kd[i] - ku[i];
                ind = posd[b - nb - 1];
                ans = tl[i] + tr[i] - tr[ind] - (2 * nb + 1) * (ind - i);
            }
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}

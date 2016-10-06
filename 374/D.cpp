#include <iostream>
#include <cstdio>
#include <utility>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

const int maxn = 2e5 + 10;
set<pii> sp;
int sign = 1;

int main() {
    ll n, k, x;
    scanf("%lld %lld %lld", &n, &k, &x);
    ll a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] < 0) sign *= -1;
        sp.insert({abs(a[i]), i});
    }
    while (k--) {
        pii num = *sp.begin();
        sp.erase(num);
        int index = num.second;
        if (a[index] < 0) sign *= -1;
        if (sign == 1) a[index] -= x;
        else a[index] += x;
        if (a[index] < 0) sign *= -1;
        sp.insert({abs(a[index]), index});
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}

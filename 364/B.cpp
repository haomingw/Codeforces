#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ll n, m;
	cin >> n >> m;	
	set<ll> v, h;
	ll x, y, vs, hs;	
	ll total = n * n, ans;
	for (ll i = 0; i < m; i++) {
		cin >> x >> y;
		v.insert(x);
		h.insert(y);
		vs = v.size();
		hs = h.size();
		ans = total - (vs + hs) * n + vs * hs;
		if (i == m - 1)
			cout << ans << endl;
		else
			cout << ans << " ";
	}
	return 0;
}
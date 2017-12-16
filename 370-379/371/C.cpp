#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;

typedef long long ll;

ll convert(ll a) {
	ll r, m = 1, ans = 0;
	while (a > 0) {
		r = a % 10;
		a /= 10;
		ans += m * (r % 2);
		m *= 10;
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	char c;
	ll ti, ai;
	unordered_map<ll, ll> hmap;
	for (int i = 0; i < n; i++){
		scanf(" %c %lld", &c, &ti);
		ai = convert(ti);
		if (c == '?') {
			cout << hmap[ai] << endl;
		} else if (c == '+') {
			hmap[ai] += 1;
		} else {
			hmap[ai] -= 1;
			if (hmap[ai] == 0) hmap.erase(ai);
		}
	}
	return 0;
}

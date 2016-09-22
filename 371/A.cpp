#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	ll l1, r1, l2, r2, k;
	scanf("%lld %lld %lld %lld %lld", &l1, &r1, &l2, &r2, &k);
	ll high, low, ans;
	low = max(l1, l2);
	high = min(r1, r2);

	// clog << low << ", " << high << endl;
	if (low <= high) {
		int c = (k >= low && k <= high) ? 1 : 0;
		ans = high - low + 1 - c;
	} else {
		ans = 0;
	}

	cout << ans << endl;
	return 0;
}

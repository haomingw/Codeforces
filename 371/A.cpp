#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	int n, c;
	cin >> n >> c;
	int ans = 1;

	if (n == 1) return !printf("1\n");
	int prev, cur;
	cin >> prev;
	for (int i = 1; i < n; i++) {		
		scanf("%d", &cur);
		if (cur - prev  <= c) {
			ans++;			
		} else {
			ans = 1;
		}
		prev = cur;
	}
	cout << ans << endl;
	return 0;
}
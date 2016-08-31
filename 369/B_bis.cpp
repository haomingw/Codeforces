#include <iostream>
#include <cstdio>
typedef long long ll;
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	if (n == 1) {
		return !printf("1\n");
	}
	int x, y;
	ll a[500][500], s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {			
			scanf("%lld", &a[i][j]);		
			if (a[i][j] == 0) {
				x = i; y = j;
			}
		}
	}
	int t = 0;
	if (x == 0) t = 1;
	for (int j = 0; j < n; j++) {
		s1 += a[t][j];
		s2 += a[x][j];
	}
	if (s1 <= s2) return !printf("-1\n");
	a[x][y] = s1 - s2;	

	for (int i = 0; i < n; i++) {
		s2 = 0;
		for (int j = 0; j < n; j++) {
			s2 += a[i][j];
		}
		if (s1 != s2) return !printf("-1\n");
	}
	for (int i = 0; i < n; i++) {
		s2 = 0;
		for (int j = 0; j < n; j++) {
			s2 += a[j][i];
		}
		if (s1 != s2) return !printf("-1\n");
	}
	s2 = 0;
	for (int i = 0; i < n; i++) {
		s2 += a[i][i];
	}
	if (s1 != s2) return !printf("-1\n");
	s2 = 0;
	for (int i = 0; i < n; i++) {
		s2 += a[i][n-1-i];
	}
	if (s1 != s2) return !printf("-1\n");

	return !printf("%lld\n", a[x][y]);
}
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	int a, b, n;
	cin >> a >> b;
	cin >> n;		

	double ans = 1000.0;
	int x, y, v;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> v;
		if (v == 0)
			continue;
		double t = sqrt((x - a) * (x - a) + (y - b) * (y - b)) / v;
		ans = min(t, ans);
	}	
	printf("%.10f\n", ans);
	return 0;
}
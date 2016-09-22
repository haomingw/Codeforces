#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	unordered_map<int, int> hmap;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		hmap[a[i]] += 1;
	}

	if (hmap.size() < 3) {
		cout << "YES";
	} else if (hmap.size() == 3) {
		vector<int> cles;
		for (auto& d : hmap) {
			// clog << d.first << ": " << d.second << endl;
			cles.push_back(d.first);
		}
		sort(cles.begin(), cles.end());
		if (cles[2] - cles[1] == cles[1] - cles[0]) {
			cout << "YES";
		} else {
			cout << "NO";
		}
	} else {
		cout << "NO";
	}

	return 0;
}

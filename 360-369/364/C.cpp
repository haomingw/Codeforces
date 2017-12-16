#include <iostream>
#include <climits>
#include <cstring>
#include <unordered_map>
#include <set>
using namespace std;

#define MAX 100000+5

int main() {
	int n;
	cin >> n;
	char s[MAX];
	cin >> s;
			
	set<char> sc(s, s + n);		
	int len[n];
	memset(len, 0, sizeof(len));
	int last, ans = INT_MAX;	
	unordered_map<char, int> hmap;		
	for (int i = 0; i < n; i++) {
		hmap[s[i]] = i;
		for (auto c : sc) {
			if (hmap.find(c) != hmap.end()) {
				last = hmap[c];
				len[i] = max(len[i], i - last + 1);
			} else {				
				len[i] = INT_MAX;				
			}			
		}
		ans = min(ans, len[i]);
	}	
	cout << ans << endl;
	
	return 0;
}
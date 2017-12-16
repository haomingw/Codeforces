#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

set<char> total;

int init() {
	char c;
	for (int i= 0; i < 26; i++) {
		c = 'A' + i;
		total.insert(c);
	}
	return 0;
}

int remplir(string &s, int start) {
	int cnt = 0, n = total.size();
	set<char>::iterator t = total.begin();	
	for (int i = start; i < start + 26; i++) {
		if (s[i] == '?') {
			s[i] = *t;		
			t++;
		}				
	}
	replace(s.begin(), s.end(), '?', 'A');
	return 0;
}

int main() {
	init();
	string s;
	cin >> s;
	int n = s.size();
	if (n < 26) return !printf("-1\n");

	unordered_map<char, int> hmap;
	for (int i = 0; i < 26; i++) {		
		hmap[s[i]] += 1;
		if (s[i] != '?') total.erase(s[i]);
	}
	int fin, cible;
	for (int debut = 0; debut <= n - 26; debut++) {		
		fin = debut + 25;
		if (debut != 0) { // update dict and queue					
			if (hmap[s[debut - 1]] <= 1) {
				hmap.erase(s[debut - 1]);
				total.insert(s[debut - 1]);
			} else {
				hmap[s[debut - 1]] -= 1;
			}
			hmap[s[fin]] += 1;
			total.erase(s[fin]);
		}		
		int c = hmap.find('?') != hmap.end() ? -1 : 0;
		cible = hmap.size() + c + hmap['?'];		
		if (cible == 26) {
			remplir(s, debut);
			cout << s << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}
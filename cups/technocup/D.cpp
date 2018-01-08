#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef pair<int, int> pii;

unordered_map<string, int> dict ({ {"S",0}, {"M",1}, {"L",2}, {"XL", 3}, {"XXL", 4}, {"XXXL", 5} });
string names[6] = {"S","M","L","XL","XXL","XXXL"};

int main() {
    int a[6], ans[100010], n;
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    cin >> n;
    string s;
    int index;
    vector<pii> todo;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int x = s.find(",");
        if (x < 0) { // only one choice
            index = dict[s];
            if (a[index] == 0) return !printf("NO\n");
            a[index]--;
            ans[i] = index;
            continue;
        }
        string s1 = s.substr(0, x);
        todo.push_back({dict[s1], i});
    }

    sort(todo.begin(), todo.end());
    for (auto& t : todo) {
        if (a[t.first] > 0) {
            a[t.first]--;
            ans[t.second] = t.first;
        } else if (a[t.first + 1] > 0) {
            a[t.first + 1]--;
            ans[t.second] = t.first + 1;
        } else
            return !printf("NO\n");
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << names[ans[i]] << endl;
    }
    return 0;
}

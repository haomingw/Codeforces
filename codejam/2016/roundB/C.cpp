#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

typedef int F;
#define F_INF (1<<29)
#define MAXV 10000
#define MAXE 10000 // E*2!

F cap[MAXE],flow[MAXE];
int to[MAXE],pre[MAXE],last[MAXV],used[MAXV],level[MAXV];

struct MaxFlow{
    int V,E;

    MaxFlow(int n){
        int i;
        V = n; E = 0;
        REP(i,V) last[i] = -1;
    }

    void add_edge(int x, int y, F f){
        cap[E] = f; flow[E] = 0; to[E] = y; pre[E] = last[x]; last[x] = E; E++;
        cap[E] = 0; flow[E] = 0; to[E] = x; pre[E] = last[y]; last[y] = E; E++;
    }

    bool bfs(int s, int t){
        int i;
        REP(i,V) level[i] = -1;
        queue <int> q;
        q.push(s); level[s] = 0;
        while(!q.empty()){
            int x = q.front(); q.pop();
            for(i=last[x];i>=0;i=pre[i]) if(level[to[i]] == -1 && cap[i] > flow[i]) {q.push(to[i]); level[to[i]] = level[x] + 1;}
        }
        return (level[t] != -1);
    }

    F dfs(int v, int t, F f){
        int i;
        if(v == t) return f;
        for(i=used[v];i>=0;used[v]=i=pre[i]) if(level[to[i]] > level[v] && cap[i] > flow[i]){
            F tmp = dfs(to[i],t,min(f,cap[i]-flow[i]));
            if(tmp > 0) {flow[i] += tmp; flow[i^1] -= tmp; return tmp;}
        }
        return 0;
    }

    F maxflow(int s, int t){
        int i;
        while(bfs(s,t)){
            REP(i,V) used[i] = last[i];
            while(dfs(s,t,F_INF) != 0);
        }
        F ans = 0;
        for(i=last[s];i>=0;i=pre[i]) ans += flow[i];
        return ans;
    }

};

const int maxn = 1005;
map<string, int> mp1, mp2;
int l[maxn], r[maxn];

void solve() {
    int n; cin >> n;
    string s1, s2;
    int L = 0, R = 0;
    mp1.clear();
    mp2.clear();
    REP(i, n) {
        cin >> s1 >> s2;
        if (!mp1.count(s1)) mp1[s1] = L++;
        if (!mp2.count(s2)) mp2[s2] = R++;
        l[i] = mp1[s1], r[i] = mp2[s2];
    }
    MaxFlow mf(L + R + 2);
    REP(i, L) mf.add_edge(L + R, i, 1);
    REP(i, R) mf.add_edge(L + i, L + R + 1, 1);
    REP(i, n) mf.add_edge(l[i], L + r[i], 1);

    int f = mf.maxflow(L + R, L + R + 1);
    int t = L + R - f;
    int ans = n - t;
    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}

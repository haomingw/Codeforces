typedef int F;
#define F_INF (1<<29)

namespace flow {
    const int MAXV = 10000, MAXE = 10000;
    F cap[MAXE],flow[MAXE];
    int to[MAXE],prev[MAXE],last[MAXV],used[MAXV],level[MAXV];
    int V,E;

    void init(int n){
        int i;
        V = n; E = 0;
        REP(i,V) last[i] = -1;
    }

    void add_edge(int x, int y, F f){
        cap[E] = f; flow[E] = 0; to[E] = y; prev[E] = last[x]; last[x] = E; E++;
        cap[E] = 0; flow[E] = 0; to[E] = x; prev[E] = last[y]; last[y] = E; E++;
    }

    bool bfs(int s, int t){
        int i;
        REP(i,V) level[i] = -1;
        queue <int> q;
        q.push(s); level[s] = 0;
        while(!q.empty()){
            int x = q.front(); q.pop();
            for(i=last[x];i>=0;i=prev[i]) if(level[to[i]] == -1 && cap[i] > flow[i]) {q.push(to[i]); level[to[i]] = level[x] + 1;}
        }
        return (level[t] != -1);
    }

    F dfs(int v, int t, F f){
        int i;
        if(v == t) return f;
        for(i=used[v];i>=0;used[v]=i=prev[i]) if(level[to[i]] > level[v] && cap[i] > flow[i]){
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
        for(i=last[s];i>=0;i=prev[i]) ans += flow[i];
        return ans;
    }

};


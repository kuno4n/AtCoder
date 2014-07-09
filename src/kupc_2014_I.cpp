#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
//#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

const int INF = (1<<30);
typedef pair<int, int> P;
struct edge {int to, cap, cost, rev;};
const int MAX_V = 10010;

int V; // Vは別途忘れずに設定すること。「最後のノード番号＋１」であることに注意。sinkと同じ数ではない。sink+1。
vector <edge> G[MAX_V]; // 使い回す場合は、Gも忘れず初期化すること
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, int cost){
    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (int)G[from].size()-1});
}

int min_cost_flow(int s, int t, int f){
    int res = 0;
    fill(h, h+V, 0);
    while(f > 0){
        priority_queue<P, vector<P>, greater<P> > que;
        fill(dist, dist+V, INF);
        dist[s] = 0;
        que.push(P(0, s));
        while(SZ(que)){
            P p = que.top(); que.pop();
            int v = p.second;
            if(dist[v] < p.first) continue; // costがdoubleの場合は、dist[v] < p.first - EPS とかにしておくと安全
            REP(i, SZ(G[v])){
                edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){ // costがdoubleの場合はここも
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(P(dist[e.to], e.to));
                }
            }
        }
        if(dist[t] == INF) return -1;
        REP(v, V) h[v] += dist[v];
        int d = f;
        for(int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d*h[t];
        for(int v = t; v != s; v = prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

int n, m, k;
int c[20];
int a[20010], b[20010], d[20010];

void init() {
}

void input() {
    cin >> n >> m >> k;
    REP(i, k) cin >> c[i], c[i]--;
    REP(i, m) cin >> a[i] >> b[i] >> d[i], a[i]--, b[i]--;
}

void solve() {
    
    REP(i, 10010) G[i].clear();
    V = n + 2;
    REP(i, m) add_edge(b[i], a[i], INF, d[i]);
    REP(i, k) add_edge(n, a[c[i]], 1, 0);
    REP(i, k) add_edge(b[c[i]], n+1, 1, 0);
    cout << min_cost_flow(n, n+1, k) << endl;
    
}

int main() {
	init();
    input();
    solve();
	return 0;
}







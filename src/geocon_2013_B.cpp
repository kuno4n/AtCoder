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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

double INF = 1e30;
double EPS = 1e-10;

typedef pair<double, int> P;
struct edge {int to, cap; double cost; int rev;};
const int MAX_V = 300;

int V;
vector <edge> G[MAX_V];
double h[MAX_V];
double dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, double cost){
    G[from].push_back((edge){to, cap, cost, G[to].size()});
    G[to].push_back((edge){from, 0, -cost, G[from].size()-1});
}

double min_cost_flow(int s, int t, int f){
    double res = 0;
    fill(h, h+V, 0);
    while(f > 0){
        priority_queue<P, vector<P>, greater<P> > que;
        fill(dist, dist+V, INF);
        dist[s] = 0;
        que.push(P(0, s));
        while(SZ(que)){
            P p = que.top(); que.pop();
            int v = p.second;
            if(dist[v] < p.first-EPS) continue;
            REP(i, SZ(G[v])){
                edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to]-EPS > dist[v] + e.cost + h[v] - h[e.to]){
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

double d(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int n;
double x[100], y[100];

void init() {
}

void input() {
    cin >> n;
    REP(i, n) cin >> x[i] >> y[i];
}

void solve() {
    REP(i, 300) G[i].clear();
    V = 2*n+2;
    REP(i, n) REP(j, n){
        if(i == j) add_edge(i, j+n, 1, abs(x[i])*2);
        else add_edge(i, j+n, 1, d(x[i], y[i], -x[j], y[j]));
    }
    REP(i, n) add_edge(2*n, i, 1, 0);
    REP(i, n) add_edge(i+n, 2*n+1, 1, 0);
    printf("%.10lf\n", min_cost_flow(2*n, 2*n+1, n)/2.0);
}

int main() {
	init();
    input();
    solve();
	return 0;
}







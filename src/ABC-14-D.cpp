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

VI G[100010];
int root;

int parent[25][100010];
int depth[100010];

void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    REP(i, SZ(G[v])) if(G[v][i] != p) dfs(G[v][i], v, d+1);
}

void init(int V) {
    dfs(root, -1, 0);
    REP(k, 24) REP(v, V){
        if(parent[k][v] < 0) parent[k+1][v] = -1;
        else parent[k+1][v] = parent[k][parent[k][v]];
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);
    REP(k, 25) if(((depth[v] - depth[u]) >> k) & 1) v = parent[k][v];
    if(u == v) return u;
    for(int k = 24; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}


int n;
int x[100010], y[100010];
int q;
int a[100010], b[100010];


void input() {
    cin >> n;
    REP(i, n-1) cin >> x[i] >> y[i];
    REP(i, n-1) x[i]--, y[i]--;
    cin >> q;
    REP(i, q) cin >> a[i] >> b[i];
    REP(i, q) a[i]--, b[i]--;
}

void solve() {
    REP(i, 100010) G[i].clear();
    REP(i, n-1){
        G[x[i]].push_back(y[i]);
        G[y[i]].push_back(x[i]);
    }
    root = 0;
    init(n);
    REP(i, q){
        int l = lca(a[i], b[i]);
        int res = depth[a[i]] + depth[b[i]] - depth[l]*2 + 1;
        cout << res << endl;
    }
}

int main() {
    input();
    solve();
	return 0;
}







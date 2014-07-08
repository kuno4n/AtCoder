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


LL INF = (1LL<<60);
LL dp[1010][3010];
LL G[1010][1010];
vector<int> t[1010];

int n;
double x[1010], y[1010];
LL d[1010], c[1010];
int u[1010], v[1010];


int dist(double x1, double y1, double x2, double y2){
    return (int)ceil(sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) - 0.0000001);
}

void init() {
}

void input() {
    cin >> n;
    REP(i, n) cin >> x[i] >> y[i];
    REP(i, n) cin >> d[i] >> c[i];
    REP(i, n-1){
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
    }
}

bool vis[1010];
void make_t(int a){
    vis[a] = true;
    REP(i, 1010) if(G[a][i] != INF && !vis[i]){
        t[a].push_back(i);
        make_t(i);
    }
}

LL rec(int a, int s){
    if(dp[a][s] != -1) return dp[a][s];
    LL res = max((s-d[a]) * c[a], 0LL);
    REP(i, SZ(t[a])){
        res += rec(t[a][i], max(G[a][t[a][i]] - s, 0LL));
    }
    
    if(s == 3000) return dp[a][s] = res;
    return dp[a][s] = min(res, rec(a, s+1));
}

void solve() {
    REP(i, 1010) REP(j, 1010) G[i][j] = INF;
    REP(i, n-1){
        G[u[i]][v[i]] = G[v[i]][u[i]] = dist(x[u[i]], y[u[i]], x[v[i]], y[v[i]]);
    }
    REP(i, 1010) t[i].clear();
    MSET(vis, false);
    make_t(0);
    
    MSET(dp, -1);
    
    cout << rec(0, 0) << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}







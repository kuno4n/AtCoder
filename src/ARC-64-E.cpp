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


	const double INF = 1e20;

	const int MAX_V = 1010;
	double cost[MAX_V][MAX_V];
	double d[MAX_V];
	bool used[MAX_V];
	int V;

	void dijk(int s){
		fill(used, used+V, false);
		fill(d, d+V, INF);
		d[s] = 0;
		while(1){
			int v = -1;
			REP(i, V) if(!used[i] && (v == -1 || d[i] < d[v])) v = i;
			if(v == -1) break;
			used[v] = true;
			REP(i, V) if(d[i] > d[v] + cost[v][i]){
                d[i] = d[v] + cost[v][i];
            }
		}
	}

	double dst(double x1, double y1, double x2, double y2){
		return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	}

double x[1010], y[1010], r[1010];

void init() {
}

void input() {
	double xs, ys, xt, yt;
	cin >> xs >> ys >> xt >> yt;
	int n;
	cin >> n;
	x[0] = xs; y[0] = ys; r[0] = 0;
	x[n+1] = xt; y[n+1] = yt; r[n+1] = 0;
	REP(i, n) cin >> x[i+1] >> y[i+1] >> r[i+1];
	V = n+2;
}

void solve() {
	REP(i, V) REP(j, V) cost[i][j] = max(0.0, dst(x[i], y[i], x[j], y[j])-r[i]-r[j]);
	dijk(0);
	printf("%.10lf\n", d[V-1]);
}

int main() {
	init();
    input();
    solve();
	return 0;
}







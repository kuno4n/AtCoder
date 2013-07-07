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

int n, s;
LL l[510], r[510];
LL g[510][510];
LL dp[510];

void init() {
}

void input() {
	cin >> n >> s; s--;
	REP(i, n) cin >> l[i] >> r[i];
	REP(i, n) REP(j, n) cin >> g[i][j];
}

void solve() {
	REP(k, n) REP(i, n) REP(j, n) chmin(g[i][j], g[i][k]+g[k][j]);
	MSET(dp, 0);
	
	vector<pair<LL, int> > table;
	REP(i, n) table.push_back(make_pair(-r[i], i));
	sort(ALL(table));
	
	REP(i, n){
		int a = table[i].second;
		REP(j, n){
			if(r[a] + g[a][j] >= r[j]) continue;
			chmax(dp[a], r[j] - max(l[j], (r[a]+g[a][j])) + dp[j]);
		}
	}
	
	LL res = 0;
	REP(i, n){
		if(g[s][i] >= r[i]) continue;
		chmax(res, r[i] - max(l[i], g[s][i]) + dp[i]);
	}
	cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}







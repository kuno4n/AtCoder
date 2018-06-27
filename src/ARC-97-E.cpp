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

int n;
char c[4010];
int a[4010];

int wk[2][4010][2010];
int dp[2010][2010];
int idx[2][2010];

int INF = 1<<29;

void init() {

}

void input() {
	cin >> n;
	REP(i, n*2) {
		cin >> c[i] >> a[i];
		idx[c[i]=='B'][a[i]] = i;
	}
}

void solve() {
	MSET(wk, 0);
	for (int i = 0; i <= a[0]; i++) wk[c[0]=='B'][0][i] = 1;
	for (int i = 1; i < n*2; i++) {
		for(int j = 0; j <= n; j++) {
			wk[0][i][j] = wk[0][i-1][j];
			wk[1][i][j] = wk[1][i-1][j];
		}
		for (int j = 0; j <= a[i]; j++) wk[c[i]=='B'][i][j]++;
	}

	REP(i, n*2) for(int j = 1; j <= n; j++){
		// OUT2(i, j);
		// OUT(wk[0][i][j]);
		// OUT(wk[1][i][j]);
	}

	REP(i, n+1) REP(j, n+1) dp[i][j] = INF;
	dp[0][0] = 0;
	REP(i, n+1) REP(j, n+1) {
		if (i==0 && j==0) continue;
		if (i > 0) {
			int id = idx[0][i];
			chmin(dp[i][j], dp[i-1][j] + wk[0][id][i]-1 + wk[1][id][j+1]);
		}
		if (j > 0) {
			int id = idx[1][j];
			chmin(dp[i][j], dp[i][j-1] + wk[1][id][j]-1 + wk[0][id][i+1]);
		}
			// OUT2(i,j);
			// OUT(dp[i][j]);
	}


	cout << dp[n][n] << endl;
}

int main() {
	init();
	input();
	solve();
	return 0;
}

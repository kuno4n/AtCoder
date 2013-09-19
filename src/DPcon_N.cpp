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

const int MOD = 1000000007;


LL C[1010][1010];

void makepas(){
	MSET(C, 0);
	REP(i, 1010){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}
}

int n;
VI g[1010];
int cnt[1010][1010];
LL dp[1010][1010];

void add(LL &a, LL b){
	a = (a + b) % MOD;
}

void mul(LL &a, LL b){
	a = (a * b) % MOD;
}

void dfs(int a, int b){
	if(dp[a][b] > 0) return;
	dp[a][b] = 1;
	REP(i, SZ(g[b])){
		int c = g[b][i];
		if(a == c) continue;
		dfs(b, c);
		cnt[a][b] += cnt[b][c] + 1;
		mul(dp[a][b], (dp[b][c] * C[cnt[a][b]][cnt[b][c]+1]) % MOD);
	}
}


void init() {
	makepas();
}

void input() {
	cin >> n;
	REP(i, n-1){
		int a, b;
		cin >> a >> b; a--; b--;
		g[a].PB(b); g[b].PB(a);
	}
}

void solve() {
	REP(i, n) REP(j, SZ(g[i])) dfs(i, g[i][j]);
	LL res = 0;
	REP(a, n) REP(i, SZ(g[a])){
		int b = g[a][i];
		if(b < a) continue;
		LL tmp = 1;
//		OUT2(a, b);
//		OUT(dp[a][b]);
//		OUT(dp[b][a]);
		mul(tmp, dp[a][b]);
		mul(tmp, dp[b][a]);
		mul(tmp, C[cnt[a][b]+cnt[b][a]][cnt[a][b]]);
		add(res, tmp);
	}
	cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}







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

int dp[52][10010];
int dp2[52][10010];
int N, W, C;
int w[110][10010], v[110][10010], cnt[110];

void init() {
}

void input() {
	cin >> N >> W >> C;
	MSET(w, -1);
	REP(_, N){
		int _w, _v, c;
		cin >> _w >> _v >> c;
		w[c][cnt[c]] = _w;
		v[c][cnt[c]++] = _v;
	}
}

void solve() {
	for(int i = 1; i <= 50; i++) if(w[i][0] != -1){
		REP(j, C) REP(k, 10010) dp2[j][k] = dp[j][k];
		REP(j, C) REP(k, cnt[i]) for(int l = W; l >= w[i][k]; l--) chmax(dp2[j][l], dp2[j][l-w[i][k]] + v[i][k]);
		REP(j, C) REP(k, 10010) chmax(dp[j+1][k], dp2[j][k]);
	}
	int res = 0;
	REP(j, C+1) REP(k, 10010) chmax(res, dp[j][k]);
	cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}







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


const int MX = 80010;
const int ST = MX / 2;
int dp[2][MX];
const int INF = (1<<29);

int n, a[210];

void init() {
}

void input() {
	cin >> n;
	REP(i, n) cin >> a[i];
}

void solve() {
	REP(i, 2) REP(j, MX) dp[i][j] = INF;
	dp[0][ST] = 0;
	queue<pair<int, int> > que;
	que.push(make_pair(ST, 0));
	while(SZ(que)){
		int k = que.front().first;
		int b = que.front().second;
		que.pop();
		REP(i, n){
			int nxt = k + (2 * a[i] * (b ? -1 : 1));
			if(nxt >= 0 && nxt < MX && dp[b^1][nxt] == INF){
				dp[b^1][nxt] = dp[b][k] + 1;
				que.push(make_pair(nxt, b^1));
			}
		}
	}


	int q;
	cin >> q;
	REP(_, q){
		int s, t;
		cin >> s >> t;
		int res = INF;

		if(t-s+ST < MX) chmin(res, dp[0][t-s+ST]);
		if(t+s+ST < MX) chmin(res, dp[1][t+s+ST]);

		if(res == INF) cout << -1 << endl;
		else cout << res << endl;
	}
}

int main() {
	init();
    input();
    solve();
	return 0;
}







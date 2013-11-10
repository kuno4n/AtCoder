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

int n, m, l, s, t;
LL g[305][305];
LL G[305][305];
const int INF = (1<<29);
LL e[305];

LL dp[1<<17][17];


	void dijk(int S){
		bool used[n];
		fill(used, used+n, false);
		REP(i, n) G[S][i] = INF;
		G[S][S] = 0;
		while(1){
			int v = -1;
			REP(i, n) if(!used[i] && (v == -1 || G[S][i] < G[S][v])) v = i;
			if(v == -1) break;
			used[v] = true;
			REP(i, n) if(G[S][i] > G[S][v] + g[v][i]){
                G[S][i] = G[S][v] + g[v][i];
            }
		}
	}


int bitcnt(LL n)
{
    int c;
    for(c=0;n!=0;c++,n&=n-1) ;
    return c;
}


void solve() {
	while(1){
		cin >> n >> m >> l >> s >> t;
		if(n == 0) break;
		s--;
		REP(i, 305) REP(j, 305) g[i][j] = INF;
		REP(i, n) g[i][i] = 0;
		REP(i, m){
			int a, b, c;
			cin >> a >> b >> c;
			a--; b--;
			g[a][b] = c;
			g[b][a] = c;
		}
		
		int SIRO[l+1];
		SIRO[0] = s;
		REP(i, 305) e[i] = INF;
		REP(i, l){
			int j, ee; cin >> j >> ee; j--;
			e[j] = ee;
			SIRO[i+1] = j;
		}
		l++;
		REP(i, l) dijk(SIRO[i]);
		REP(i, (1<<17)) REP(j, 17) dp[i][j] = INF;
		dp[1][0] = 0;
		REP(i, (1<<l)) REP(j, l) if(dp[i][j] != INF) {
			REP(k, l) if(!((i>>k)&1)){
				chmin(dp[i|(1<<k)][k], dp[i][j] + G[SIRO[j]][SIRO[k]] + e[SIRO[k]]);
			}
		}
		int res = 0;
		REP(i, (1<<l)) REP(j, l) if(dp[i][j] + G[SIRO[j]][SIRO[0]] <= t){
			chmax(res, bitcnt(i)-1);
		}
		cout << res << endl;
	}
}

int main() {
    solve();
	return 0;
}







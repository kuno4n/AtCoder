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
#define cpresent(c, e) (find(ALL(c), (e)) != (c).end())

int n, K;
LL MOD = 1000000007;
LL dp[55][55][5200];

void solve() {
  cin >> n >> K;
  dp[1][0][0] = 1;
  dp[1][1][2] = 1;
  FOR(i, 1, n) REP(j, i+1) REP(k, K+10) {
    LL now = dp[i][j][k];
    dp[i+1][j+1][k+j*2+2] = (dp[i+1][j+1][k+j*2+2] + now) % MOD;
    dp[i+1][j][k+j*2] = (dp[i+1][j][k+j*2] + (now*(j*2+1))%MOD) % MOD;
    if(j > 0) {
      dp[i+1][j-1][k+(j-1)*2] = (dp[i+1][j-1][k+(j-1)*2] + (now*j*j)%MOD) % MOD;
    }
  }
  // FOR(i, 1, n+1) REP(j, n+1) REP(k, K+10) {
  //   if(dp[i][j][k] > 0) {
  //     cout << i << " " <<  j << " " << k << endl;
  //     OUT(dp[i][j][k]);
  //   }
  // }
  cout << dp[n][0][K] << endl;
}

int main() {
	solve();
	return 0;
}

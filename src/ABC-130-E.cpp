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

LL s[2002];
LL t[2002];
int n, m;

LL sum[2002][2002];
LL dp[2002][2002];

void init() {

}

void input() {
  cin >> n >> m;
  REP(i, n) cin >> s[i];
  REP(i, m) cin >> t[i];
}

void solve() {
  REP(i, n) REP(j, m) {
    if (i == 0 || j == 0) {
      if (s[i] == t[j]) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = 0;
      }
      if (i > 0) sum[i][j] = dp[i][j] + sum[i-1][j];
      if (j > 0) sum[i][j] = dp[i][j] + sum[i][j-1];
      if (i == 0 && j == 0) sum[i][j] = dp[i][j] + 1;
    } else {
      if (s[i] == t[j]) dp[i][j] = sum[i-1][j-1];
      else dp[i][j] = 0;
      sum[i][j] = (sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + dp[i][j] + 1000000007) % 1000000007;
    }
    // OUT2(i, j);
    // OUT2(dp[i][j], sum[i][j]);
  }
  cout << (sum[n-1][m-1]) % 1000000007 << endl;
}

int main() {
	init();
	input();
	solve();
	return 0;
}

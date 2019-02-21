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



int l;
LL a[200010];
LL dp[200010][5];

void init() {

}

void input() {
  cin >> l;
  REP(i, l) cin >> a[i];
}

LL calc(LL A, LL j) {
  if (j == 1){
    if (A == 0) return 2;
    return A%2;
  }
  if (j == 2){
    return ((A+1)%2);
  }
  if (j == 3){
    if (A == 0) return 2;
    return A%2;
  }
  return A;
}

void solve() {
  REP(i, 5) dp[0][i] = 0;
  FOR(i, 1, l+1) REP(j, 5) dp[i][j] = 1LL<<50;
  REP(i, l) {
    dp[i+1][0] = dp[i][0] + a[i];
    FOR(j, 1, 5) {
      dp[i+1][j] = min(dp[i+1][j-1], dp[i][j] + calc(a[i], j));
    }
  }
  cout << dp[l][4] << endl;
}

int main() {
	init();
	input();
	solve();
	return 0;
}

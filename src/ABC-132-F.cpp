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

LL dp[100][100010];
LL n, k;

LL nn, cnt[100010];

LL MOD = 1000000007;

void solve() {
  cin >> n >> k;

  nn = 0;
  int ptr = 1;
  while(1) {
    nn++;
    LL start = ptr;
    if (n/ptr == 1) {
      cnt[nn-1] = n-ptr+1;
      break;
    }
    ptr += (n%ptr) / (n/ptr) + 1;
    cnt[nn-1] = ptr - start;
  }

  REP(i, nn) dp[0][i] = 1;
  REP(i, k-1) {
    LL sum = 0;
    REP(j, nn) {
      sum = (sum + dp[i][j]*cnt[j]) % MOD;
      dp[i+1][nn-j-1] = (dp[i+1][nn-j-1] + sum) % MOD;
    }
  }
  LL res = 0;
  REP(i, nn) res = (res + dp[k-1][i]*cnt[i]) % MOD;
  cout << res << endl;

}

int main() {
	solve();
	return 0;
}

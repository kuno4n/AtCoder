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

LL sum[55];
LL dp[55];

LL go(int l, LL a) {
  if (a <= 0) {
    return 0;
  }
  if (l == 0) {
    return 1;
  }
  if (a <= sum[l-1]+1) {
    return go(l-1, a-1);
  }
  return dp[l-1] + 1 + go(l-1, a-sum[l-1]-2);
}

void init() {
  sum[0] = 1;
  FOR(i, 1, 55) {
    sum[i] = sum[i-1]*2 + 3;
  }
  dp[0] = 1;
  FOR(i, 1, 55) {
    dp[i] = dp[i-1]*2 + 1;
  }
}

LL n, x;
void input() {
cin >> n >> x;
}

void solve() {
  cout << go(n, x) << endl;
}

int main() {
	init();
	input();
	solve();
	return 0;
}

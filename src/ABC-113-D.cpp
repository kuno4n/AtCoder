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

const LL MOD = 1000000007;

long long modPow(long long x, long long y){
    long long r=1, a=x%MOD;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

LL dp[110][10];
LL dp2[10];
int h, w, k;

void init() {

}

void input() {
  cin >> h >> w >> k;
}

void solve() {
  dp2[0] = 1;
  dp2[1] = 1;
  dp2[2] = 2;
  FOR(i, 3, 10) {
    dp2[i] = (dp2[i-1] + dp2[i-2]) % MOD;
  }

  dp[0][1] = 1;
  FOR(i, 1, h+1) FOR(j, 1, w+1) {
    dp[i][j] = (dp[i][j] + dp[i-1][j] * dp2[j-1] * dp2[w-j]) % MOD;
    if (j >= 2) {
      dp[i][j] = (dp[i][j] + dp[i-1][j-1] * dp2[j-2] * dp2[w-j]) % MOD;
    }
    if (j <= w-1) {
      dp[i][j] = (dp[i][j] + dp[i-1][j+1] * dp2[j-1] * dp2[w-1-j]) % MOD;
    }
  }
  cout << dp[h][k] << endl;;
}

int main() {
	init();
	input();
	solve();
	return 0;
}

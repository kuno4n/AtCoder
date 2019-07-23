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

LL n, m, k;
LL MOD = 1000000007;
LL memo[200010];


//--------------------------------
//繰り返し２乗法を用いたpow。MOD版。
long long modPow(long long x, long long y){
    long long r=1, a=x%MOD;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

//--------------------------------
//ここからはMODが素数の場合のみ可

//--------------------------------
//MODでの逆元。
long long modInverse(long long x){
    return modPow(x, MOD-2);
}

//--------------------------------
//MODでの割り算。
long long modDivision(long long p, long long q){
    return (p*modInverse(q)) % MOD; //((p%MOD)*modInverse(q)) % MOD の方が安全？
}

LL C(LL n, LL k) {
  if(memo[k]) return memo[k];
  if(k > n) return 0;
  if(k == 0 || n == 0) return 1;
  long long p=1, q=1;
  for(int i=1; i<=k; i++){
      q = (q*i) % MOD;
      p = (p*((n-i+1+MOD)%MOD))%MOD;
  }
  memo[k] = modDivision(p, q);
  return memo[k];
}

void solve() {
  cin >> n >> m >> k;
  LL res = 0;

  LL ysum = 0;
  REP(i, n) {
    ysum = (ysum + i*(i+1LL)/2%MOD) % MOD;
  }

  REP(i, m) {
    LL _ysum = ysum;
    if(i > 0) _ysum = _ysum*2%MOD;
    LL l = ((_ysum + i*n%MOD*n%MOD) % MOD) * (m-i) % MOD;
    res = (res + l * C(n*m-2, k-2) % MOD ) % MOD;
  }
  cout << res << endl;
}

int main() {
	solve();
	return 0;
}

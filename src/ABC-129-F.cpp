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

LL L, A, B, M;

long long modPow(long long x, long long y){
    long long r=1, a=x%M;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % M;
        a = (a*a) % M;
        y /= 2;
    }
    return r;
}

long long _Pow(long long x, long long y){
    long long r=1, a=x;
    while(y > 0){
        if((y&1) == 1) r = r*a;
        a = a*a;
        y /= 2;
    }
    return r;
}

int disit(LL n) {
  int res = 0;
  while(n > 0) {
    res++;
    n /= 10;
  }
  return res;
}

LL term(LL a, LL b, LL i) {
  return a + b*i;
}

LL hoge(LL len, LL p) {
  // 1 + p + p^2 + ... + p^(len-1)
  if (len == 1) return 1;
  if (len % 2 == 0) {
    return (hoge(len/2, p) * (1+modPow(p, len/2)%M)%M) % M;
  } else {
    return (hoge(len-1, p) + modPow(p, len-1)%M) % M;
  }
}

LL hoge2(LL len, LL p) {
  // 1*p^(len-1) + 2*p^(len-2) + ... + (len-1)*p + len*1
  // 6 + 500 + 40000 + 3000000 + 200000000 + 10000000000
  if (len == 0) return 0;
  if (len == 1) return 1;
  if (len % 2 == 0) {
    return hoge2(len/2, p)*(1+modPow(p, len/2)%M)%M + (len/2)%M*hoge(len/2, p)%M;
  } else {
    return (len + p*hoge2(len-1, p)%M) % M;
  }
}

void solve() {
  cin >> L >> A >> B >> M;
  LL res = 0;

  LL i = L-1;
  LL zeros = 1;
  while(i >= 0) {
    LL start = term(A, B, i);
    int d = disit(start);
    LL len = min(i+1, (start-_Pow(10, d-1))/B + 1);
    i = i-len+1;
    LL end = term(A, B, i);
    i--;

    LL tmp = (end%M)*hoge(len, modPow(10, d))%M;
    tmp = (tmp + B%M*hoge2(len-1, modPow(10, d))%M) % M;

    res = (res + (tmp*zeros)%M) % M;

    // zeros = zeros * modPow(10, d)%M * modPow(10, len) % M;
    zeros = zeros * modPow(modPow(10, d), len) % M;
  }

  cout << res << endl;
}

int main() {
	solve();
	return 0;
}

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


map<LL, int> prime_factor(long long l){
    map<LL, int> res;
    for(long long i=2; i*i<=l; i++){
        while(l%i == 0){
            res[i]++;
            l /= i;
        }
    }
    if(l!=1) res[l] = 1;
    return res;
}

const int MOD = 1000000007;
long long modPow(long long x, long long y){
    long long r=1, a=x%MOD;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

long long modInverse(long long x){
    return modPow(x, MOD-2);
}

long long modDivision(long long p, long long q){
    return (p*modInverse(q)) % MOD;
}

long long modC(long long n, int k){
    if(k > n) return 0;
    long long p=1, q=1;
    for(int i=1; i<=k; i++){
        q = (q*i) % MOD;
        p = (p*((n-i+1+MOD)%MOD))%MOD;
    }
    return modDivision(p, q);
}

void solve() {
  LL n, m;
  cin >> n>> m;
  map<LL, int> pf = prime_factor(m);
  LL res = 1;
  for (auto a : pf) {
    res = (res * modC(n-1+a.second, a.second)) % MOD;
  }
  cout << res << endl;
}

int main() {
	solve();
	return 0;
}

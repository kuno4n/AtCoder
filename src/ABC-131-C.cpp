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

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

long long lcm(long long a, long long b){
    return a*b/gcd(a,b);
}

void solve() {
  LL a, b, c, d;
  cin >> a >> b >> c >> d;
  LL sumb = (b-b/c + b-b/d) - (b-b/lcm(c,d));
  // cout << b-b/c << endl;
  // cout << b-b/d << endl;
  // cout << b-b/d << endl;
  LL suma = ((a-1)-(a-1)/c + (a-1)-(a-1)/d) - ((a-1)-(a-1)/lcm(c,d));
  cout << sumb - suma << endl;
}

int main() {
	solve();
	return 0;
}

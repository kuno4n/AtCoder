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

LL n, q, a[100010], x[100010];
vector<LL> bound;
LL sum[100010], sumHalf[100010];

void init() {

}

void input() {
  cin >> n >> q;
  REP(i, n) cin >> a[i];
  REP(i, q) cin >> x[i];
}

void solve() {
  bound.clear();
  bound.push_back((1LL<<50)*-1);
  for(LL i = 1; ; i++) {
    LL r = n-1-i;
    LL l = n-1-i*2;
    if (l < 0) break;
    bound.push_back((a[l]+a[r])/2*-1);
  }
  sum[0] = 0;
  sumHalf[0] = 0;
  FOR(i, 1, n+1) {
    sum[i] = sum[i-1] + a[i-1];
    if (i==1) sumHalf[i] = a[i-1];
    else sumHalf[i] = sumHalf[i-2] + a[i-1];
  }
  REP(i, q) {
    LL b = upper_bound(bound.begin(), bound.end(), -x[i]) - bound.begin();
    // cout << b << endl;
    LL s = sum[n] - sum[n-b];
    LL remain = n-b*2;
    if (remain > 0) s += sumHalf[remain];
    cout << s << endl;
  }
}

int main() {
	init();
	input();
	solve();
	return 0;
}

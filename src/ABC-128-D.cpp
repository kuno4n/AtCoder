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

int n, k;
LL V[55];

void solve() {
  cin >> n >> k;
  REP(i, n) cin >> V[i];
  LL res = 0;

  FOR(l, -1, n) for(int r = n; r > l; r--) {
    vector<LL> v;
    REP(i, l+1) v.PB(V[i]);
    for(int i = n-1; i >= r; i--) v.PB(V[i]);
    if (SZ(v) > k) continue;
    int remain = k - SZ(v);
    LL sum = 0;
    sort(ALL(v));
    REP(i, SZ(v)) {
      if (v[i] < 0 && remain > 0) {
        remain--;
        continue;
      }
      sum += v[i];
    }
    chmax(res, sum);
  }
  cout << res << endl;
}

int main() {
	solve();
	return 0;
}

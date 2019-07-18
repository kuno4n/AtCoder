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

int n;
LL s[100010];

void solve() {
  cin >> n;
  REP(i, n) cin >> s[i];
  LL res = 0;
  FOR(c, 1, n-1) {
    set<int> se;
    int l = 0, r = n-1;
    LL sum = 0;
    while(l+c < n-1) {
      sum += s[l];
      sum += s[r];
      chmax(res, sum);
      l += c;
      r -= c;
      if (se.count(l) > 0) break;
      se.insert(l);
      if (se.count(r) > 0) break;
      se.insert(r);
    }
    // if ((n-1)%c == 0) {
    //   while(l<r) {
    //     sum += s[l];
    //     sum += s[r];
    //     chmax(res, sum);
    //     l += c;
    //     r -= c;
    //   }
    // } else {
    //   while(l < n-1) {
    //     sum += s[l];
    //     sum += s[r];
    //     chmax(res, sum);
    //     l += c;
    //     r -= c;
    //   }
    // }
  }
  cout << res << endl;
}

int main() {
	solve();
	return 0;
}

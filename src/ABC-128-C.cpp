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



void solve() {
  int n, m;
  cin >> n >> m;
  int k[10];
  int s[10][10];
  REP(i, m) {
    cin >> k[i];
    REP(j, k[i]) cin >> s[i][j];
    REP(j, k[i]) s[i][j]--;
  }
  int p[10];
  REP(i, m) cin >> p[i];

  int res = 0;
  REP(i, (1<<n)) {
    bool ok = true;
    REP(j, m) {
      int on = 0;
      REP(kk, k[j]) {
        if ((1<<s[j][kk]) & i) on++;
      }
      if (on%2 != p[j]) ok = false;
    }
    if (ok) res++;
  }
  cout << res << endl;

}

int main() {
	solve();
	return 0;
}

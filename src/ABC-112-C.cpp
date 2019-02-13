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



void init() {

}

void input() {

}

void solve() {
  int n;
  int x[110], y[110], h[110];
  cin >> n;
  REP(i, n) cin >> x[i] >> y[i] >> h[i];
  while(1) {
    REP(X, 101) REP(Y, 101) {
      bool ok = true;
      LL H;
      REP(i, n) if (h[i] > 0) H = h[i] + abs(X-x[i]) + abs(Y-y[i]);
      REP(i, n) {
        int tmph = h[i] + abs(X-x[i]) + abs(Y-y[i]);
        if (h[i] == 0) {
          if (H > tmph) ok = false;
        } else {
          if (H != tmph) ok = false;
        }
      }

      if (ok) {
        cout << X <<" " << Y <<" "<< H << endl;
        return;
      }
    }
  }
}

int main() {
	init();
	input();
	solve();
	return 0;
}

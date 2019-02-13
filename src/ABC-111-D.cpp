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
int x[1010];
int y[1010];

void init() {

}

void input() {
  cin >> n;
  REP(i, n) cin >> x[i] >> y[i];
}

void solve() {
REP(i, n) if(abs(x[i])>10 || abs(y[i])>10){
  cout << -1 << endl;
  return;
}

  REP(i, n-1) if(((x[i]+y[i])&1) != ((x[i+1]+y[i+1])&1)) {
    cout << -1 << endl;
    return;
  }

  int m = 2;
  REP(i, n) chmax(m, abs(x[i])+abs(y[i]));
  cout << m << endl;
  REP(i, m) cout << 1 << " ";
  cout << endl;

  REP(i, n) {
    int remain = m;
    REP(a, abs(x[i])){
      if (x[i] > 0) cout <<'R';
      else cout <<'L';
      remain--;
    }
    REP(a, abs(y[i])){
      if (y[i] > 0) cout <<'U';
      else cout <<'D';
      remain--;
    }
    REP(a, remain) {
      if (a&1) cout <<'R';
      else cout <<'L';
    }
    cout << endl;
  }
}

int main() {
	init();
	input();
	solve();
	return 0;
}

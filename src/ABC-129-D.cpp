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

int h, w;
string s[2020];
int hori[2020][2020];
int vert[2020][2020];


void init() {

}

void input() {
  cin >> h >> w;
  REP(i, h) cin >> s[i];
}

void solve() {
  REP(i, 2020) REP(j, 2020) {
    hori[i][j] = 0;
    vert[i][j] = 0;
  }
  REP(i, h) {
    int start = -1;
    REP(j, w+1) {
      if (j == w || s[i][j] == '#') {
        if (start != -1) {
          FOR(k, start, j) hori[i][k] = j-start;
          start = -1;
        }
      } else {
        if (start == -1) start = j;
      }
    }
  }
  REP(i, w) {
    int start = -1;
    REP(j, h+1) {
      if (j == h || s[j][i] == '#') {
        if (start != -1) {
          FOR(k, start, j) vert[k][i] = j-start;
          start = -1;
        }
      } else {
        if (start == -1) start = j;
      }
    }
  }

  int res = 0;
  REP(i, h) REP(j, w) chmax(res, hori[i][j] + vert[i][j] - 1);
  cout << res << endl;
}

int main() {
	init();
	input();
	solve();
	return 0;
}

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

int n, a, b, c;
int l[10];

void init() {

}

void input() {
  cin >> n >> a >> b >> c;
  REP(i, n) cin >>l[i];
}

int go(int A, int B, int C, int m, int i) {
  if (i == n) {
    if (A == 0 || B == 0 || C == 0) {
      return 99999999;
    }
    else return abs(a-A) + abs(b-B) + abs(c-C) + m;
  }
  int res = 88888888;
  chmin(res, go(A+l[i], B, C, (A==0 ? m : m+10), i+1));
  chmin(res, go(A, B+l[i], C, (B==0 ? m : m+10), i+1));
  chmin(res, go(A, B, C+l[i], (C==0 ? m : m+10), i+1));
  chmin(res, go(A, B, C, m, i+1));
  return res;
}

void solve() {
  cout << go(0, 0, 0, 0, 0) << endl;
}

int main() {
	init();
	input();
	solve();
	return 0;
}

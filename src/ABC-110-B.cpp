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
  int n, m, x, y;
  VI X, Y;
  cin >> n >> m>> x >> y;
  X.push_back(x);
  Y.push_back(y);
  REP(i, n) {
    int a;
    cin >> a;
    X.push_back(a);
  }
  REP(i, m) {
    int a;
    cin >> a;
    Y.push_back(a);
  }
  sort(ALL(X), greater<int>());
  sort(ALL(Y));
  if (X[0] < Y[0]) cout << "No War" << endl;
  else cout << "War" << endl;

}

int main() {
	init();
	input();
	solve();
	return 0;
}
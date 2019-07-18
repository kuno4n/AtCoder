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

// vector<LL> rx, lx, uy, dy, xs, ys;
// int n;
// LL INF = 1LL<<60;
// set<LL> t;
//
// void solve() {
//   cin >> n;
//   REP(i, n) {
//     LL x, y;
//     char d;
//     cin >> x >> y >> d;
//     if (d == 'U') {
//       xs.push_back(x*2);
//       uy.push_back(y*2);
//     }
//     if (d == 'D') {
//       xs.push_back(x*2);
//       dy.push_back(y*2);
//     }
//     if (d == 'R') {
//       rx.push_back(x*2);
//       ys.push_back(y*2);
//     }
//     if (d == 'L') {
//       lx.push_back(x*2);
//       ys.push_back(y*2);
//     }
//   }
//   sort(ALL(rx));
//   sort(ALL(lx));
//   sort(ALL(uy));
//   sort(ALL(dy));
//   sort(ALL(xs));
//   sort(ALL(ys));
//
//   t.insert(0);
//
//   if(SZ(rx) > 0 && SZ(lx) > 0) {
//     t.insert((lx.front()-rx.front())/2);
//     t.insert((lx.front()-rx.back())/2);
//     t.insert((lx.back()-rx.front())/2);
//     t.insert((lx.back()-rx.back())/2);
//   }
//   if(SZ(rx) > 0 && SZ(xs) > 0) {
//     t.insert((xs.front()-rx.front()));
//     t.insert((xs.front()-rx.back()));
//     t.insert((xs.back()-rx.front()));
//     t.insert((xs.back()-rx.back()));
//   }
//   if(SZ(lx) > 0 && SZ(xs) > 0) {
//     t.insert((lx.front()-xs.front()));
//     t.insert((lx.front()-xs.back()));
//     t.insert((lx.back()-xs.front()));
//     t.insert((lx.back()-xs.back()));
//   }
//
//   if(SZ(uy) > 0 && SZ(dy) > 0) {
//     t.insert((dy.front()-uy.front())/2);
//     t.insert((dy.front()-uy.back())/2);
//     t.insert((dy.back()-uy.front())/2);
//     t.insert((dy.back()-uy.back())/2);
//   }
//   if(SZ(uy) > 0 && SZ(ys) > 0) {
//     t.insert((ys.front()-uy.front()));
//     t.insert((ys.front()-uy.back()));
//     t.insert((ys.back()-uy.front()));
//     t.insert((ys.back()-uy.back()));
//   }
//   if(SZ(dy) > 0 && SZ(ys) > 0) {
//     t.insert((dy.front()-ys.front()));
//     t.insert((dy.front()-ys.back()));
//     t.insert((dy.back()-ys.front()));
//     t.insert((dy.back()-ys.back()));
//   }
//
//   LL res = INF;
//   for (auto i : t) if (i >= 0) {
//     LL maxx = -INF;
//     if (SZ(rx) > 0) chmax(maxx, rx.back()+i);
//     if (SZ(xs) > 0) chmax(maxx, xs.back());
//     if (SZ(lx) > 0) chmax(maxx, lx.back()-i);
//     LL minx = INF;
//     if (SZ(rx) > 0) chmin(minx, rx.front()+i);
//     if (SZ(xs) > 0) chmin(minx, xs.front());
//     if (SZ(lx) > 0) chmin(minx, lx.front()-i);
//     LL maxy = -INF;
//     if (SZ(uy) > 0) chmax(maxy, uy.back()+i);
//     if (SZ(ys) > 0) chmax(maxy, ys.back());
//     if (SZ(dy) > 0) chmax(maxy, dy.back()-i);
//     LL miny = INF;
//     if (SZ(uy) > 0) chmin(miny, uy.front()+i);
//     if (SZ(ys) > 0) chmin(miny, ys.front());
//     if (SZ(dy) > 0) chmin(miny, dy.front()-i);
//     chmin(res, (maxx-minx)*(maxy-miny));
//   }
//   printf("%.2f\n", res/4.0);
// }

int n;
LL x[100010], y[100010];
int dx[100010], dy[100010];

double cal(double t) {
  double minx = 1e16;
  double maxx = -1e16;
  double miny = 1e16;
  double maxy = -1e16;
  REP(i, n) {
    chmin(minx, x[i] + dx[i]*t);
    chmax(maxx, x[i] + dx[i]*t);
    chmin(miny, y[i] + dy[i]*t);
    chmax(maxy, y[i] + dy[i]*t);
  }
  return (maxx-minx) * (maxy-miny);
}

void solve() {
  cin >> n;
  REP(i, n) {
    char d;
    cin >> x[i] >> y[i] >> d;
    if (d == 'U') dy[i] = 1;
    if (d == 'D') dy[i] = -1;
    if (d == 'R') dx[i] = 1;
    if (d == 'L') dx[i] = -1;
  }

  double mn = 0, mx = 1e16;
  double res = 1e16;
  REP(_, 400) {
    double a = (mn*2 + mx) / 3;
    double b = (mn + mx*2) / 3;
    double aa = cal(a);
    double bb = cal(b);
    res = min(aa, bb);
    if (aa > bb) mn = a;
    else mx = b;
  }

  printf("%.2f\n", res);
}

int main() {
	solve();
	return 0;
}

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


int par[100010];  //親
int _rank[100010]; //木の深さ

// n要素で初期化
void init(int n){
      REP(i, n){
		par[i] = i;
          _rank[i] = 0;
	}
}
//木の根を求める
int find(int x){
	if(par[x] == x) return x;
	else return par[x] = find(par[x]);
}
//xとyの属する集合を結合
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(_rank[x] < _rank[y]) par[x] = y;
	else{
		par[y] = x;
		if(_rank[x] == _rank[y]) _rank[x]++;
	}
}

int n, x[100010], y[100010];
set<int> xs[100010], ys[100010];

map<int, int> mapx;
map<int, int> mapy;

void solve() {
  cin >> n;
  init(n);
  REP(i, n) {
    cin >> x[i] >> y[i];
    if (mapx.count(x[i])) unite(i, mapx[x[i]]);
    mapx[x[i]] = i;
    if (mapy.count(y[i])) unite(i, mapy[y[i]]);
    mapy[y[i]] = i;
  }
  REP(i, n) {
    xs[find(mapx[x[i]])].insert(x[i]);
    ys[find(mapy[y[i]])].insert(y[i]);
  }
  LL res = 0;
  REP(i, n) {
    res += (LL)SZ(xs[i]) * SZ(ys[i]);
  }
  cout << res - n  << endl;
}

int main() {
	solve();
	return 0;
}

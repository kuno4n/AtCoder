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


int h, w, res;
LL blackCnt, whiteCnt;
string s[410];
bool visit[410][410];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0 ,-1, 1};

void go(int x, int y) {
  // cout << "go: " << x << " " << y << endl;
  visit[x][y] = true;
  if(s[x][y] == '.') whiteCnt++;
  else blackCnt++;
  REP(i, 4) {
    int _x = x + dx[i];
    int _y = y + dy[i];
    // cout << "_x:" << _x << " _y:" << _y << endl;
    if (_x >= 0 && _x < h && _y >= 0 && _y < w && !visit[_x][_y] && s[x][y] != s[_x][_y]) {
      go(_x, _y);
    }
  }
}

void init() {

}

void input() {
  cin >> h >> w;
  REP(i, h) cin >> s[i];
  res = 0;
  REP(i, h) REP(j, w) visit[i][j] = false;
}

void solve() {
  LL res = 0;
  REP(i, h) REP(j, w) {
    if (!visit[i][j] && s[i][j] == '#') {
      blackCnt = 0;
      whiteCnt = 0;
      // cout << i << " " << j << endl;
      go(i, j);
      // cout << blackCnt << " " << whiteCnt << endl << endl;
      res += blackCnt*whiteCnt;
    }
  }
  cout << res << endl;
}

int main() {
	init();
	input();
	solve();
	return 0;
}

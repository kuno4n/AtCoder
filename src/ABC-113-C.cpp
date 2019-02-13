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

bool pairCompare(pair<int, int> firstElof, pair<int, int> secondElof)
{
    return firstElof.second < secondElof.second;
}

void init() {

}

void input() {

}

vector < pair<int, int> > v[100010];
pair<int, int> res[100010];

void solve() {
  int n, m;
  cin >> n >> m;
  REP(i, m) {
    int p, y;
    cin >> p >> y;
    pair<int, int> pa = make_pair(i, y);
    v[p].push_back(pa);
  }
  FOR(i, 1, n+1) {
    sort(ALL(v[i]), pairCompare);
    REP(j, SZ(v[i])) {
      res[v[i][j].first] = make_pair(i, j+1);
    }
  }
  REP(i, m) {
    printf( "%06d%06d\n", res[i].first, res[i].second);
  }
}

int main() {
	init();
	input();
	solve();
	return 0;
}

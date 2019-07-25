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

int m, k;

void solve() {
  cin >> m >> k;
  if (k >= (1<<m)) {
    cout << -1 << endl;
    return;
  }
  if (m == 0) {
    cout << 0 << " " << 0 << endl;
    return;
  }
  if (m == 1) {
    if (k == 0) {
      cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl;
      return ;
    }
    cout << -1 << endl;
    return;
  }
  REP(i, (1<<m)) if(i!=k){
    cout << i << " ";
  }
  cout << k << " ";
  for(int i = (1<<m)-1; i >= 0; i--) if(i!=k) {
    cout << i << " ";
  }
  cout << k << " " << endl;
}

int main() {
	solve();
	return 0;
}

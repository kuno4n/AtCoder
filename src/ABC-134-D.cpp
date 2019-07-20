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
int a[200010];
int m;
int b[200010];

void solve() {
  cin >> n;
  REP(i, n) cin >> a[i+1];
  m = 0;
  for(int i = n; i >= 1; i--) {
    int ptr = n-n%i;
    int x = 0;
    while(ptr > i) {
      x ^= b[ptr];
      ptr -= i;
    }
    b[i] = x ^ a[i];
    if(b[i] == 1) m++;
  }
  cout << m << endl;
  FOR(i, 1, n+1) if(b[i]) cout << i << " " ;
  if (m > 0) cout << endl;

}

int main() {
	solve();
	return 0;
}

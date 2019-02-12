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


int cnt[101];
int n;

void init() {

}

void input() {

}

void solve() {
  cin >> n;
  REP(i, 101) cnt[i] = 0;
  for(int i=2;i<=n;i++) {
  		int x=i;
  		for(int j=2;x>1;j++) {
  			while(x%j==0) {
  				cnt[j]++;
  				x/=j;
  			}
  		}
  	}


  LL dp[110];
  REP(i, 101) dp[i] = 0;
  dp[1] = 1;

  FOR(i, 1, 101) if (cnt[i]){
    for(int j = 75; j >=1; j--) {
      FOR(k, 1, cnt[i]+1) {
        if (j*(k+1) <= 75) {
          dp[j*(k+1)] += dp[j];
        }
      }
    }
  }

  cout << dp[75] << endl;

}

int main() {
	init();
	input();
	solve();
	return 0;
}

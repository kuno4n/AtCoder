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
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

int A;
double dp[1<<16];
double INF = (1LL<<60);

void init() {
}

void input() {
	int n; cin >> n;
	REP(_, n){
		int a; cin >> a;
		A |= (1<<a);
	}
}

void solve() {
	REP(i, (1<<16)) dp[i] = INF;
	dp[0] = 0.0;
	for(int i = 1; i < (1<<16); i++){
		REP(target, 16){
			VI x;
			for(int j = max(0, target-1); j <= min(15, target+1); j++) if(i & (1<<j)) x.PB(j);
			if(SZ(x) == 1) chmin(dp[i], 3.0 + dp[i^(1<<x[0])]);
			if(SZ(x) == 2) chmin(dp[i], 1.5 + (dp[i^(1<<x[0])] + dp[i^(1<<x[1])]) / 2.0);
			if(SZ(x) == 3) chmin(dp[i], 1.0 + (dp[i^(1<<x[0])] + dp[i^(1<<x[1])] + dp[i^(1<<x[2])]) / 3.0);
		}
	}
	
	printf("%.10lf\n", dp[A]);
}

int main() {
	init();
    input();
    solve();
	return 0;
}







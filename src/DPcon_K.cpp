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

const int INF = (1<<29);
int n;
pair<int, int> pii[100010];
int dp[100010];

void init() {
}

void input() {
	cin >> n;
	REP(i, n){
		int x, r; cin >> x >> r;
		pii[i] = make_pair(x+r, x-r);
	}
	sort(pii, pii+n);
}

void solve() {
	
	REP(i, 100010) dp[i] = -INF;
	REP(i, n){
		int hi = 100009, lo = -1;
		while(hi - lo > 1){
			int md = ((hi + lo) >> 1);
			if(dp[md] > pii[i].second) lo = md;
			else hi = md;
		}
		dp[hi] = pii[i].second;
	}
	for(int i = n; i >= 0; i--) if(dp[i] != -INF){
		cout << i+1 << endl;
		return;
	}
}

int main() {
	init();
    input();
    solve();
	return 0;
}







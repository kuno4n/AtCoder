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



LL dp[55][2];
const LL MOD = 1000000007;
string s[3];
int n;

void init() {
}

void input() {
}

void add(LL &a, LL b){
	a = (a + b) % MOD;
}


LL rec(int d, int ku){
	if(dp[d][ku] >= 0) return dp[d][ku];
	LL res = 0;
	
	REP(i, 10) REP(j, 10){
		if(d == 0 && i == 0) continue;
		if(d == 0 && j == 0) continue;
		if(s[0][d] != '?' && s[0][d]-'0' != i) continue;
		if(s[1][d] != '?' && s[1][d]-'0' != j) continue;
		if(d < n-1) REP(k, 2){
			if(i+j+k >= 10 && ku == 0) continue;
			if(i+j+k < 10 && ku == 1) continue;
			if(s[2][d] != '?' && s[2][d]-'0' != (i+j+k)%10) continue;
			add(res, rec(d+1, k));
		}
		else{
			if(i+j >= 10 && ku == 0) continue;
			if(i+j < 10 && ku == 1) continue;
			if(s[2][d] != '?' && s[2][d]-'0' != (i+j)%10) continue;
			add(res, 1);
		}
		
	}
	
	return dp[d][ku] = res;
}

void solve() {
	while(1){
		cin >> s[0];
		if(s[0] == "0") break;
		cin >> s[1] >> s[2];
		n = SZ(s[0]);
		MSET(dp, -1);
		cout << rec(0, 0) << endl;
	}
}

int main() {
	init();
    input();
    solve();
	return 0;
}







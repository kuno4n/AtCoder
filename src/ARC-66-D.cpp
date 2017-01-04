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

string _10to2(long long l){
    if (l == 0) return "0";
    string res = "";
    while(l != 1){
        if ( l & 1 ) res = '1' + res;
        else res = '0' + res;
        l >>= 1;
    }
    return '1' + res;
}

LL n;
LL MOD = 1000000007;

void init() {
}

void input() {
	cin >> n;
}

void solve() {
	int bit = SZ(_10to2(n));
	LL dp[100][3]; MSET(dp, 0);
	dp[bit-1][0] = 1;
	dp[bit-1][1] = 1;
	dp[bit-1][2] = 0;
	for(int b = bit-2; b >= 0; b--){
		if((n>>b)&1){
			dp[b][0] = dp[b+1][0];
			dp[b][1] = (dp[b+1][0] + dp[b+1][1]) % MOD;
			dp[b][2] = (dp[b+1][1]*2 + dp[b+1][2]*3) % MOD;
		}
		else{
			dp[b][0] = (dp[b+1][0] + dp[b+1][1]) % MOD;
			dp[b][1] = dp[b+1][1];
			dp[b][2] = (dp[b+1][1] + dp[b+1][2]*3) % MOD;
		}
	}
	cout << (dp[0][0] + dp[0][1] + dp[0][2])%MOD << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}







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

int n, k;
LL dp[1000010], sum[1000010];
const int MOD = 1000000007;

void add(LL &a, LL b){
    a = (a + b) % MOD;
}

void init() {
}

void input() {
    cin >> n >> k;
}


void solve() {
    dp[0] = sum[0] = 1;
    for(int i = 1; i <= n+1; i++){
        if(i != 1 && i != n) add(dp[i], (sum[i-1] - (i-k-1 >= 0 ? sum[i-k-1] : 0) + MOD));
        sum[i] = (sum[i-1] + dp[i]) % MOD;
    }
    
    cout << dp[n+1] << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}







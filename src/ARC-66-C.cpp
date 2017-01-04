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

int n;
int a[100010];
#define MOD 1000000007;

long long modPow(long long x, long long y){
    long long r=1, a=x%MOD;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

void init() {
}

void input() {
	cin >> n;
	REP(i, n) cin >> a[i];
}

void solve() {
	int b[n];
	REP(i, n) b[i] = 0;
	REP(i, n) b[a[i]]++;

	if(n%2) {
		for(int i = 1; i < n; i+=2) if(b[i] != 0){
			cout << 0 << endl;
			return;
		}
		for(int i = 2; i < n; i+=2) if(b[i] != 2){
			cout << 0 << endl;
			return;
		}
		if(b[0]!=1){
			cout << 0 << endl;
			return;
		}
		cout << modPow(2, (n-1)/2) << endl;
	}
	else {
		for(int i = 1; i < n; i+=2) if(b[i] != 2){
			cout << 0 << endl;
			return;
		}
		for(int i = 0; i < n; i+=2) if(b[i] != 0){
			cout << 0 << endl;
			return;
		}
		cout << modPow(2, n/2) << endl;
	}
}

int main() {
	init();
    input();
    solve();
	return 0;
}







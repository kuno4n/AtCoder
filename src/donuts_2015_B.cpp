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


int bitcnt(LL n)
{
    int c;
    for(c=0;n!=0;c++,n&=n-1) ;
    return c;
}

int n, m, A[20], B[55], C[55], I[55][20];

void init() {
}

void input() {
	cin >> n >> m;
	REP(i, n) cin >> A[i];
	REP(i, m){
		cin >> B[i] >> C[i];
		REP(j, C[i]){
			cin >> I[i][j];
			I[i][j]--;
		}
	}
}

void solve() {
	int res = 0;
	REP(i, (1<<n)) if(bitcnt(i) == 9){
		int tmp = 0;
		REP(j, n) if((i>>j) & 1) tmp += A[j];
		REP(j, m){
			int cnt = 0;
			REP(k, C[j]) if(i & (1<<I[j][k])) cnt++;
			if(cnt >= 3) tmp += B[j];
		}
		chmax(res, tmp);
	}
	cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}







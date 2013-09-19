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
#define VL vector < LL >
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


const int MOD = 1000000007;

    typedef vector < VL > mat;
    
    mat mul(mat &A, mat &B){
        mat C(SZ(A), VL(SZ(B[0])));
        REP(i, SZ(A)){
            REP(k, SZ(B)){
                REP(j, SZ(B[0])){
                    C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % MOD; 
                }
            }
        }
        return C;
    }
    
    mat pow(mat A, LL n){
        mat B(SZ(A), VL(SZ(A)));
        REP(i, SZ(A)) B[i][i] = 1;
        while(n > 0){
            if(n&1) B = mul(B, A);
            A = mul(A, A);
            n >>= 1;
        }
        return B;
    }

int h, r, g[16][16];
LL dp[16][1<<16][16];

void add(LL &a, LL b){
	a = (a + b) % MOD;
}

void init() {
}

void input() {
	cin >> h >> r;
	REP(i, r) REP(j, r) cin >> g[i][j];
}

void solve() {
	REP(i, r) dp[i][1<<i][i] = 1;
	REP(i, r) REP(j, (1<<r)) REP(k, r) if(dp[i][j][k] > 0)
		REP(l, r) if(!(j&(1<<l)) && g[k][l])
			add(dp[i][j|(1<<l)][l], dp[i][j][k]);
	mat m;
	REP(i, r){
		VL tmp;
		REP(j, r){
			LL sum = 0;
			REP(k, (1<<r)) add(sum, dp[i][k][j]);
			tmp.PB(sum);
		}
		m.PB(tmp);
	}
	
	mat A(1, VL(r));
	A[0][0] = 1;
	for(int i = 1; i < r; i++) A[0][i] = 0;
	mat B = pow(m, h);
	mat C = mul(A, B);
	cout << C[0][0] << endl;
	
}

int main() {
	init();
    input();
    solve();
	return 0;
}







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


typedef vector < vector<LL> > mat;

mat mul(mat &A, mat &B){
    mat C(SZ(A), vector<LL>(SZ(B[0])));
    REP(i, SZ(A)){
        REP(k, SZ(B)){
            REP(j, SZ(B[0])){
                C[i][j] = (C[i][j] ^ (A[i][k] & B[k][j]));
            }
        }
    }
    return C;
}

mat pow(mat A, LL n){
    mat B(SZ(A), vector<LL>(SZ(A)));
    REP(i, SZ(A)) B[i][i] = (1LL<<32)-1;
    while(n > 0){
        if(n&1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}


int k, m;
LL a[110], c[110];

void init() {
}

void input() {
    cin >> k >> m;
    REP(i, k) cin >> a[i];
    REP(i, k) cin >> c[i];
}

void solve() {
    if(m <= k){
        cout << a[m-1] << endl;
        return;
    }
    
    mat A(k, vector<LL>(k, 0));
    mat B(k, vector<LL>(1, 0));
    REP(j, k) A[0][j] = c[j];
    FOR(j, 1, k) A[j][j-1] = (1LL<<32)-1;
    REP(j, k) B[k-j-1][0] = a[j];
    mat C = pow(A, m-k);
    cout << mul(C, B)[0][0] << endl;
}

int main() {
    init();
    input();
    solve();
}








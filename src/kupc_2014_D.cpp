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

LL same, diff;
string s1, s2;
LL d1, d2;
LL n;

const LL MOD = 1000000007;

long long modPow(long long x, long long y){
    long long r=1, a=x%MOD;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}


//--------------------------------
//MODでの逆元。
long long modInverse(long long x){
    return modPow(x, MOD-2);
}

//--------------------------------
//MODでの割り算。
long long modDivision(long long p, long long q){
    return (p*modInverse(q)) % MOD; //((p%MOD)*modInverse(q)) % MOD の方が安全？
}

//--------------------------------
//MODでの組み合わせ。
long long modC(long long n, int k){
    if(k > n) return 0;
    if(k == 0 || n == 0) return 1; // 問題に応じて設定
    long long p=1, q=1;
    for(int i=1; i<=k; i++){
        q = (q*i) % MOD;
        p = (p*((n-i+1+MOD)%MOD))%MOD;
    }
    return modDivision(p, q);
}

void init() {
}

void input() {
    cin >> s1 >> d1 >> s2 >> d2;
}

void solve() {
    n = SZ(s1);
    same = diff = 0;
    REP(i, n){
        if(s1[i] == s2[i]) same++;
        else diff++;
    }
    LL tmp = diff;
    LL cnt = 0;
    while(tmp > 0){
        if(d1 > d2) d1--, cnt++;
        else d2--;
        tmp--;
    }
    if(d1 != d2 || d1 < 0 || d2 < 0){
        cout << 0 << endl;
        return;
    }
    if(same < d1){
        cout << 0 << endl;
        return;
    }
    
    LL res = (modC(diff, cnt) * modC(same, d1)) % MOD;
    
    cout << res << endl;
}

int main() {
    init();
    input();
    solve();
}








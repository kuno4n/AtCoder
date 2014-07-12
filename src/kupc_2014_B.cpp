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

bool isPrime(long long l){
    if(l < 2) return false;
    for(long long i=2; i*i<=l; i++)
        if(l%i == 0 )
            return false;
    return true;
}

bool isp[1010];

void init() {
    MSET(isp, false);
    for(LL i = 2; i < 1010; i++){
        isp[i] = isPrime(i);
    }
}

void input() {
}

void solve() {
    int res = 1;
    for(int i = 2; i <= 1000; i++) if(isp[i]){
        int tar = 1;
        int tmp = 1;
        while(1){
            tmp *= i;
            if(tmp > 1000) break;
            printf("? %d\n", tmp); fflush(stdout);
            string judge; cin >> judge;
            if(judge == "N") break;
            tar = tmp;
        }
        res *= tar;
    }
    printf("! %d\n", res); fflush(stdout);
}

int main() {
    init();
    input();
    solve();
}








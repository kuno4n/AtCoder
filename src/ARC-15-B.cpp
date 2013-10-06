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


int cal1(double a, double b){
    if(a >= 35.0) return 0;
    if(a >= 30.0) return 1;
    if(a >= 25.0) return 2;
    if(a < 0.0) return 5;
    else return 6;
}

int cal2(double b){
    if(b >= 25.0) return 3;
    else return 6;
}

int cal3(double a, double b){
    if(a >= 0.0 && b < 0.0) return 4;
    else return 6;
}

int n;

void init() {
}

void input() {
}

void solve() {
    cin >> n;
    int res[10];
    MSET(res, 0);   
    REP(_, n){
        double a, b;
        cin >> a >> b;
        res[cal1(a, b)]++;
        res[cal2(b)]++;
        res[cal3(a, b)]++;
    }
    REP(i, 6){
        cout << res[i];
        if(i == 5) cout << endl;
        else cout << " ";
    }
}

int main() {
    init();
    input();
    solve();
}








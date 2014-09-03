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

double txa, tya, txb, tyb, T, V;
int n;
double x[1010], y[1010];
double eps = 1e-9;

double p(double a){
    return a*a;
}

double d(double x1, double y1, double x2, double y2){
    return sqrt(p(x1-x2) + p(y1-y2));
}

void init() {
}

void input() {
    cin >> txa >> tya >> txb >> tyb >> T >> V >> n;
    REP(i, n) cin >> x[i] >> y[i];
}

void solve() {
    REP(i, n){
        double D = d(x[i], y[i], txa, tya) + d(x[i], y[i], txb, tyb);
        double t = D / V;
        if(t - eps < T){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}







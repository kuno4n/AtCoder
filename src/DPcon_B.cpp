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


const int INF = (1<<30);
int memo[1010][1010];
int A[1010], B[1010];
int na, nb;

int rec(int a, int b, bool turn){
    if(memo[a][b] >= 0) return memo[a][b];
    if(a == na && b == nb) return memo[a][b] = 0;
    if(a == na) return memo[a][b] = rec(a, b+1, turn^1) + (turn ? B[b] : 0);
    if(b == nb) return memo[a][b] = rec(a+1, b, turn^1) + (turn ? A[a] : 0);
    
    int tmpa = rec(a+1, b, turn^1) + (turn ? A[a] : 0);
    int tmpb = rec(a, b+1, turn^1) + (turn ? B[b] : 0);
    if(turn ^ (tmpa > tmpb)) return memo[a][b] = tmpb;
    else return memo[a][b] = tmpa;
}


void init() {
}

void input() {
    cin >> na >> nb;
    REP(i, na) cin >> A[i];
    REP(i, nb) cin >> B[i];
}

void solve() {
    MSET(memo, -1);
    cout << rec(0, 0, true) << endl;
}

int main() {
    init();
    input();
    solve();
}








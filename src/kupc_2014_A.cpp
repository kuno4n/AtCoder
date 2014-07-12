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


int a[3], b[3];
//int L1[6] = {0, 0, 1, 1, 2, 2};
//int L2[6] = {1, 2, 2, 0, 1, 0};
//int L3[6] = {2, 1, 0, 2, 0, 1};


void init() {
}

void input() {
    REP(i, 3) cin >> a[i];
    REP(i, 3) cin >> b[i];
    sort(a, a+3);
}

void solve() {
    int res = 1000000;
    do{
        int cnt = 0;
        REP(i, 3) cnt += abs(a[i] - b[i]);
        chmin(res, cnt);
    }while(next_permutation(a, a+3));
    cout << res << endl;
}

int main() {
    init();
    input();
    solve();
}








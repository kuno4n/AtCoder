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

set< VI > se;
LL n, k;
string s;

void init() {
}

void input() {
    cin >> n >> k >> s;
    
}

void solve() {
    VI a(26, 0);
    VI b(26, 0);
    REP(i, n){
        a[s[i]-'a']++;
        if(i >= k) a[s[i-k]-'a']--;
        if(i >= k) b[s[i-k]-'a']++;
        if(i >= k*2) b[s[i-k*2]-'a']--;
        if(i >= k*2-1) se.insert(b);
        if(se.count(a)){
            cout << "YES" << endl;
//            OUT(i);
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







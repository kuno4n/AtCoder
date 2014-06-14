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

int n;
int x[1010], y[1010];

void init() {
}

void input() {
    cin >> n;
    REP(i, n) cin >> x[i] >> y[i];
}

void solve() {
    set<pair<int, int> > s;
    s.clear();
    REP(i, n){
        s.insert(make_pair(x[i], y[i]));
    }

    
    
    
    
//    if(n > 100) return; 
    
    
//    set<pair<int, int> > s;
//    set<int> X, Y;
//    s.clear();
//    X.clear();
//    Y.clear();
//    REP(i, n){
//        s.insert(make_pair(x[i], y[i]));
//        X.insert(x[i]);
//        Y.insert(y[i]);
//    }
//
//    int m = 0;
//    set<pair<int, int> > res;
//    for(auto a = X.begin(); a != X.end(); a++){
//        for(auto b = Y.begin(); b != Y.end(); b++){
//            if(s.count(make_pair((*a), (*b))) == 0){
//                m++;
//                res.insert(make_pair((*a), (*b)));
//            }
//        }
//    }
//    
//    cout << m << endl;
//    for(auto c = res.begin(); c != res.end(); c++){
//        pair<int , int> ans = *c;
//        cout << ans.first << " " << ans.second << endl;
//    }
}

int main() {
	init();
    input();
    solve();
	return 0;
}







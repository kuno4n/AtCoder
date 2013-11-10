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

    const int MAX_N = 100010;
	int par[MAX_N];  //e
	int rank[MAX_N]; //–Ø‚Ì[‚³
    
	// n—v‘f‚Å‰Šú‰»
	void init(int n){
        REP(i, n){
			par[i] = i;
            rank[i] = 0;
		}
	}
	//–Ø‚Ìª‚ð‹‚ß‚é
	int find(int x){
		if(par[x] == x) return x;
		else return par[x] = find(par[x]);
	}
	//x‚Æy‚Ì‘®‚·‚éW‡‚ðŒ‹‡
	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(rank[x] < rank[y]) par[x] = y;
		else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
		}
	}
	//x‚Æy‚ª“¯‚¶W‡‚É‘®‚·‚é‚©
	bool same(int x, int y){
		return find(x) == find(y);
	}

const int MOD = 1000000007;

long long modPow(long long x, long long y){
    long long r=1, a=x%MOD;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

void solve() {
	int n, m;
	while(1){
		cin >> n >> m;
		if(n == 0) return;
		init(n);
		REP(i, m){
			int a, b; 
			cin >> a >> b;a--; b--;
			unite(a, b);
		}
		set<int> s, ss;
		REP(i, n) if(find(i) != i) s.insert(find(i)), ss.insert(i), ss.insert(find(i));
		if(SZ(s) == 0){
			cout << modPow(2, n) << endl;
		}
		else if(SZ(s) == 1){
			cout << modPow(2, n-SZ(ss)+1) + 1 << endl;
		}
		else {
			cout << modPow(2, n-SZ(ss)+SZ(s))+1 << endl;
		}
	}
}

int main() {
    solve();
	return 0;
}







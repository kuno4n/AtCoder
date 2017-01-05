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



    const int MAX_N = 200010;
	int par_K[MAX_N];
	int _rank_K[MAX_N];
	int par_L[MAX_N];
	int _rank_L[MAX_N];

	void UF_init(int n){
        REP(i, n){
			par_K[i] = i;
            _rank_K[i] = 0;
			par_L[i] = i;
            _rank_L[i] = 0;
		}
	}

	int find_K(int x){
		if(par_K[x] == x) return x;
		else return par_K[x] = find_K(par_K[x]);
	}

	int find_L(int x){
		if(par_L[x] == x) return x;
		else return par_L[x] = find_L(par_L[x]);
	}

	void unite_K(int x, int y){
		x = find_K(x);
		y = find_K(y);
		if(x == y) return;
		if(_rank_K[x] < _rank_K[y]) par_K[x] = y;
		else{
			par_K[y] = x;
			if(_rank_K[x] == _rank_K[y]) _rank_K[x]++;
		}
	}

	void unite_L(int x, int y){
		x = find_L(x);
		y = find_L(y);
		if(x == y) return;
		if(_rank_L[x] < _rank_L[y]) par_L[x] = y;
		else{
			par_L[y] = x;
			if(_rank_L[x] == _rank_L[y]) _rank_L[x]++;
		}
	}

int N, K, L;

void init() {
}

void input() {
	cin >> N >> K >> L;
	UF_init(N);
	REP(i, K){
		int p, q; cin >> p >> q; p--; q--;
		unite_K(p, q);
	}
	REP(i, L){
		int p, q; cin >> p >> q; p--; q--;
		unite_L(p, q);
	}
}

map<pair<int, int>, VI> m;
int res[200010];

void solve() {
	m.clear();
	REP(i, N) m[make_pair(find_K(i), find_L(i))].PB(i);
	MSET(res, 0);
	FIT(it, m) {
		REP(a, SZ(it->second)){
			res[(it->second)[a]] = SZ(it->second);
		}
	}
	REP(i, N) cout << res[i] << " ";
	cout << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}







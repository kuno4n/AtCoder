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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())


set <string> s;
int n;

void init() {
}

void input() {
	cin >> n;
}

void solve() {
	string prv;
	cin >> prv;
	s.insert(prv);
	for(int i = 1; i < n; i++){
		string st; cin >> st;
		if(s.count(st) || prv[SZ(prv)-1] != st[0]){
			if(i&1) cout << "WIN" << endl;
			else cout << "LOSE" << endl;
			return;
		}
		s.insert(st);
		prv = st;
	}
	cout << "DRAW" << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}







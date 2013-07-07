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

bool table[110][110];
int n ,m;


void init() {
}

void input() {
	cin >> n >> m;
	REP(j, m) cin >> table[0][j];
	for(int i = 1; i < n; i++) REP(j, m) {
		cin >> table[i][j];
		table[i][j] = !table[i][j];
	}
}

void solve() {
	int res = 0;
	REP(i, n){
//		int one = 0;
//		if(table[i][0]) one++;
//		if(table[i][m-1]) one++;
//		for(int j = 1; j < m-1; j++) if(!table[i][j]) one++;
//		if(one < m) res += one+1;
//		else res += one-1;
		int a = 0, b = m-1;
		while(a <= b){
			if(table[i][a]){
				res++;a++;
				table[i][a] = !table[i][a];
			}
			else if(table[i][b]){
				res++;b--;
				table[i][b] = !table[i][b];
			}
			else{
				a++;
				table[i][a] = !table[i][a];
			}
		}
	}
	cout << res << endl;
}

int main() {
	init();
    input();
    solve();
	return 0;
}







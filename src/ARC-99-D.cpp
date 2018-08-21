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
#define cpresent(c, e) (find(ALL(c), (e)) != (c).end())


vector < pair<LL, double> > v;
int k;

void init() {
	// v.push_back(make_pair(1, 1));
	// for (int i = 2; i < 6666666; i++) {
	// 	int s = 0;
	// 	int tmp = i;
	// 	while(tmp) {
	// 		s += tmp%10;
	// 		tmp /= 10;
	// 	}
	// 	double su = (double)i/s;
	// 	while(v[SZ(v)-1].second > su) v.pop_back();
	// 	v.push_back(make_pair(i, su));
	// }
	// REP(i, SZ(v)) {
	// 	OUT2(v[i].first, v[i].second);
	// }
}

void input() {
	cin >> k;
}

void solve() {
	v.push_back(make_pair(1, 1));
	LL i = 2;
	LL offset = 1;

	while(1) {
		LL s = 0;
		LL tmp = i;
		while(tmp) {
			s += tmp%10;
			tmp /= 10;
		}
		double su = (double)i/s;
		if (v[SZ(v)-1].second > su) {
			i -= offset * 2;
			offset *= 10;
			v.pop_back();
		} else {
			v.push_back(make_pair(i, su));
			if (SZ(v) > k + 20) {
				REP(j, k) cout << v[j].first << endl;
				return ;
			}
		}
		i += offset;
	}
}

int main() {
	init();
	input();
	solve();
	return 0;
}

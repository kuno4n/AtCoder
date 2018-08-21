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

int n;
LL a[1<<20];
pair<int, int> max_id_pair[1<<20];
pair<int, int> max_id_pair2[1<<20];

void init() {

}

void input() {
	cin >> n;
	REP(i, 1<<n) cin >> a[i];
}

void solve() {
	max_id_pair[1] = make_pair(0, 1);
	for(int i = 2; i < 1<<n; i++) {
		set<int> ids;
		ids.insert(i);
		REP(j, n) if(i & (1<<j)) {
			ids.insert(max_id_pair[i-(1<<j)].first);
			ids.insert(max_id_pair[i-(1<<j)].second);
		}
		vector< pair<LL, int> > v;
		for(auto id : ids) v.push_back(make_pair(a[id], id));
		sort(ALL(v));
		reverse(ALL(v));
		max_id_pair[i] = make_pair(v[0].second, v[1].second);
	}

	cout << a[0] + a[1] << endl;
	max_id_pair2[1] = make_pair(0, 1);
	for(int i = 2; i < 1<<n; i++) {
		int id11 = max_id_pair2[i-1].first;
		int id12 = max_id_pair2[i-1].second;
		int id21 = max_id_pair[i].first;
		int id22 = max_id_pair[i].second;
		if (a[id11] + a[id12] > a[id21] + a[id22]) {
			cout << a[id11] + a[id12] << endl;
			max_id_pair2[i] = max_id_pair2[i-1];
		} else {
			cout << a[id21] + a[id22] << endl;
			max_id_pair2[i] = max_id_pair[i];
		}
	}
}

int main() {
	init();
	input();
	solve();
	return 0;
}

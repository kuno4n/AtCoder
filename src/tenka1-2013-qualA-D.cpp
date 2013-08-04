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




struct Node {
	string s;
	LL len, repeat;
	vector<Node *> children;
	Node(){
		len = 0, repeat = 0;
	}
};


pair<Node *, int> build(const char *s, int p){
	Node *n = new Node();
	while(s[p] != ')' && s[p] != '\0'){
		if(s[p] == '('){
			pair<Node *, int> q = build(s, p+1);
			Node *m = q.first;
			p = q.second + 1;
			m->repeat = 0;
			while(isdigit(s[p])){
				m->repeat *= 10;
				m->repeat += s[p++] - '0';
			}
			m->len *= m->repeat;
			if(m->repeat == 1) REP(i, SZ(m->children)) n->children.push_back(m->children[i]);
			else n->children.push_back(m);
		}
		else{
			Node *m = new Node();
			while(s[p] != '(' && s[p] != ')' && s[p] != '\0'){
				m->s += s[p++];
				m->len++;
			}
			m->repeat = 1;
			n->children.push_back(m);
		}
	}
	REP(i, SZ(n->children)) n->len += n->children[i]->len;
	n->repeat = 1;
	return make_pair(n, p);
}


void dump(const Node *node, int depth = 0){
	cout << string(depth * 2, ' ');
	if(node->children.empty()){
		cout << "\"" << node->s << "\"" << " " << node->len << endl;
	}else{
		cout << "(" << node->len << ", " << node->repeat << ")" << endl;
		REP(i, SZ(node->children)){
			dump(node->children[i], depth + 1);
		}
	}
}

char get(const Node *node, LL pos){
	if(SZ(node->children) == 0) return node->s[pos];
	LL sum = 0;
	REP(i, SZ(node->children)){
		Node *n = node->children[i];
		if(pos < sum + n->len) return get(n, (pos-sum) % (n->len/n->repeat));
		sum += n->len;
	}
	return ' ';
}

void solve() {
	
	LL b, l, n;
	string s;
	cin >> b >> l >> n >> s ;
	
	Node *root = build(s.c_str(), 0).first;
//	dump(root);
	LL allLen = root->len;
	
	string res = "";
	REP(i, l) res += get(root, (b+i+allLen) % allLen);
	cout << res << endl;
	

}

int main() {
    solve();
	return 0;
}







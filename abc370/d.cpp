#include <bits/stdc++.h>
using namespace std;
#include <cmath>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0 ; --i)
#define rrep1(i,n) for(int i = (n); i > 0; --i)
using mint = modint998244353;
using mint2 = modint1000000007;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vs = vector<string>;
using vsi = vector<set<int>>;
using vsl = vector<set<ll>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int INF = 1001001001;
ll LINF = 1001001001001001001;
using mytpl = tuple<ll,int,int>;

// struct S {
//     int a;
// };

// struct F {
//     int a;
// };

// int op(int l, int r) { return l + r; }

// int e() { return 0; }

// int mapping(int f, int x) { return x+f; }

// int composition(int f, int g) { return f+g; }

// int id() { return 0; }

// struct S {
//     int a;
// };

// struct F {
//     int a;
// };

// S op(S l, S r) { return S{l.a + r.a}; }

// S e() { return S{0}; }

// S mapping(F f, S x) { return S{x.a + f.a}; }

// F composition(F f, F g) { return F{f.a + g.a}; }

// F id() { return F{0}; }

using S = int;
using F = int;
S op(S l, S r) { return l + r; }
S e() { return 0; }
S mapping(F f, S x) { return x + f; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }


int main(){
    int h, w, q;
    cin >> h >> w >> q;

    lazy_segtree<int, op, e, int, mapping, composition, id> segw(w+1);
    lazy_segtree<int, op, e, int, mapping, composition, id> segh(h+1);

    rep(i,w+1){
        segw.set(i, i);
    }
    rep(i,h+1){
        segh.set(i, i);
    }

    rep(i,w+1){
        cerr << segw.get(i) << " ";
    }
    cerr << endl;

    rep(i,h+1){
        cerr << segh.get(i) << " ";
    }
    cerr << endl;

    segw.apply(4, w, -1);
    segh.apply(4, h, -1);

    rep(i,w+1){
        cerr << segw.get(i) << " ";
    }
    cerr << endl;

    rep(i,h+1){
        cerr << segh.get(i) << " ";
    }
    cerr << endl;

}
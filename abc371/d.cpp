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
int main(){
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> p(n);
    set<ll> sx;
    map<ll, int> inv_x;
    
    rep(i,n) cin >> x[i];
    rep(i,n) cin >> p[i];
    rep(i,n) sx.insert(x[i]);
    rep(i,n) inv_x[x[i]] = i;

    vector<ll> acc_p(n, 0);
    acc_p[0] = p[0];
    rep1(i,n-1) {
        acc_p[i] = acc_p[i-1] + p[i];
    }

    set<pair<ll,ll>> sp;
    rep(i,n) sp.insert({x[i], acc_p[i]});
    sp.insert({LINF, 0});
    sp.insert({-LINF, 0});

    int q;
    cin >> q;

    while(q--) {
        ll lx, rx;
        cin >> lx >> rx;

        ll ans = 0;
        auto lit = sp.lower_bound({lx, -LINF});
        auto rit = sp.lower_bound({rx, LINF});
        auto lit_ = prev(lit);
        auto rit_ = prev(rit);


        ans = rit_ -> second - lit_ -> second;
        cout << ans << endl;
    }

    return 0;
}
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

ll longmin(ll a, ll b){
    return a < b ? a : b;
}

int main(){
    int n, x;
    cin >> n >> x;
    vi a(n), p(n), b(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];

    int l = 0;
    int r = INF;

    auto f = [&](int a, int p, int b, int q, int w){
        ll res = LINF;
        ll i = w/a + 1;
        ll j = 0;
        for(;i >= 0; i--){
            // while(a * i + b * j < w){
            //     j++;
            // }
            j = (w - a * i) / b + (w - a * i) % b;
            res = longmin(res, p * i + q * j);
        }
        return res;
    };

    auto check = [&](int w){
        ll sum = 0;
        rep(i, n){
            sum += f(a[i], p[i], b[i], q[i], w);
        }
        return sum <= x;
    };

    while(r - l > 1){
        int m = (l + r) / 2;
        if(check(m)){
            l = m;
        }else{
            r = m;
        }
    }

    cout << l << endl;

    return 0;
}

//was not able to solve
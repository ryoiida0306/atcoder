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
    vector<vector<vector<ll>>> a(n+1, vector<vector<ll>>(n+1, vector<ll>(n+1)));
    rep1(i,n){
        rep1(j,n){
            rep1(k,n){
                cin >> a[i][j][k];
            }
        }
    }
    int q;
    cin >> q;
    vector<vector<ll>> l(q, vector<ll>(3));
    vector<vector<ll>> r(q, vector<ll>(3));
    rep(i,q){
        rep(j,3){
            cin >> l[i][j];
            cin >> r[i][j];
        }
    }

    rep(i,n+1){
        rep(j,n+1){
            rep1(k,n){
                a[i][j][k] += a[i][j][k-1];
            }
        }
    }
    rep(k,n+1){
        rep(i,n+1){
            rep1(j,n){
                a[i][j][k] += a[i][j-1][k];
            }
        }
    }
    rep(j,n+1){
        rep(k,n+1){
            rep1(i,n){
                a[i][j][k] += a[i-1][j][k];
            }
        }
    }

    vector<ll> ans(q);

    rep(i,q){
        ans[i] += a[r[i][0]][r[i][1]][r[i][2]];
        ans[i] -= a[l[i][0]-1][r[i][1]][r[i][2]];
        ans[i] -= a[r[i][0]][l[i][1]-1][r[i][2]];
        ans[i] -= a[r[i][0]][r[i][1]][l[i][2]-1];
        ans[i] += a[l[i][0]-1][l[i][1]-1][r[i][2]];
        ans[i] += a[l[i][0]-1][r[i][1]][l[i][2]-1];
        ans[i] += a[r[i][0]][l[i][1]-1][l[i][2]-1];
        ans[i] -= a[l[i][0]-1][l[i][1]-1][l[i][2]-1];
    }

    rep(i,q){
        cout << ans[i] << endl;
    }

}
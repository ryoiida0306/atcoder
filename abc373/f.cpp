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
    ll n, w;
    cin >> n >> w;
    vl weight(n), value(n);
    rep(i,n) cin >> weight[i] >> value[i];
    ll dp[n+1][w+1];
    rep(i,n+1) rep(j,w+1) dp[i][j] = 0;
    rep(i,n){
        rep(j,w+1){
            rep(k,w/weight[i]+1){
                if(j < k*weight[i]) break;
                if(value[i] < k) break;
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-k*weight[i]]+k*value[i]-k*k);
            }
        }
    }
    ll ans = 0;
    rep(i,w+1) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}

//wa
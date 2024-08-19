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
    int n, s;
    cin >> n >> s;
    vi a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    vs dp(s+1, "");
    dp[0] = "O";

    rep(i,n){
        vs next_dp(s+1, "");
        rep(j,s+1){
            if(dp[j] == ""){
                continue;
            }
            if(j + a[i] <= s){
                next_dp[j + a[i]] = dp[j] + "A";
            }
            if(j + b[i] <= s){
                next_dp[j + b[i]] = dp[j] + "B";
            }
        }
        dp = next_dp;
    }

    if(dp[s] == ""){
        cout << "Impossible" << endl;
    }else{
        cout << dp[s].substr(1) << endl;
    }

    // rep(i,s+1){
    //     cerr << i << " " << dp[i] << endl;
    // }

    return 0;

}
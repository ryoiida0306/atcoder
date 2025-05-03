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

vector<string> rot90(const vector<string> &s){
    int n = s.size(), m = s[0].size();
    vector<string> t(m, string(n, ' '));
    rep(i,n) rep(j,m) t[j][n-i-1] = s[i][j];
    return t;
}

int diff(const vector<string> &s, const vector<string> &t){
    int n = s.size(), m = s[0].size();
    int ans = 0;
    rep(i,n) rep(j,m) if(s[i][j] != t[i][j]) ans++;
    return ans;
}

int main(){
    int n; cin >> n;
    vector<string> s(n), t(n);
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> t[i];

    int ans = INF;

    for(int i = 0; i < 4; i++){
        ans = min(ans, diff(s, t)+i);
        s = rot90(s);
    }

    cout << ans << endl;
    return 0;



}
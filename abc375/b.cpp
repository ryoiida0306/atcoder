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

    vd x(n), y(n);
    rep(i,n){
        cin >> x[i] >> y[i];
    }

    double ans = 0;
    double prev_x = 0, prev_y = 0;
    rep(i,n){
        double res = sqrt((x[i]-prev_x)*(x[i]-prev_x) + (y[i]-prev_y)*(y[i]-prev_y));
        ans += res;
        prev_x = x[i];
        prev_y = y[i];
    }

    ans += sqrt(prev_x*prev_x + prev_y*prev_y);

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
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
    int n, m; cin >> n >> m;
    vl b(n), w(m);
    rep(i,n) cin >> b[i];
    rep(i,m) cin >> w[i];

    sort(b.begin(), b.end());
    sort(w.begin(), w.end());
    reverse(b.begin(), b.end());
    reverse(w.begin(), w.end());

    vl bacc(n+5), wacc(m+5);
    rep(i,n) bacc[i+1] = bacc[i] + b[i];
    rep(i,m) wacc[i+1] = wacc[i] + w[i];
    bacc[n+1] = -INF;
    wacc[m+1] = -INF;
    bacc[n+2] = -INF;
    wacc[m+2] = -INF;

    ll ans = 0;

    int bi = 0, wi = 0;

    while(bi < n+1 && wi < m+1){
        if(bi == wi){
            bi++;
            ans = max(ans, bacc[bi] + wacc[wi]);
            continue;
        }
        if(bacc[bi+1] - bacc[bi] > wacc[wi+1] - wacc[wi]){
            bi++;
            ans = max(ans, bacc[bi] + wacc[wi]);
        }else{
            wi++;
            ans = max(ans, bacc[bi] + wacc[wi]);
        }
    }

    cout << ans << endl;

    return 0;

}
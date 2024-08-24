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

int op(int a, int b){return max(a,b);}
int e(){return 0;}

int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];

    // int op(int a, int b){return max(a,b);}
    // int e(){return 0;}
    segtree<int, op, e> upseg(n);
    segtree<int, op, e> downseg(n);

    vi updp(n+1, 0);
    vi downdp(n+1, 0);

    rep(i,n){
        upseg.set(a[i]-1, upseg.prod(0, a[i]-1) + 1);
        updp[i] = upseg.all_prod();
        downseg.set(a[n-i-1]-1, downseg.prod(0, a[i]-1) + 1);
        downdp[i] = downseg.all_prod();
    }

    int ans = 0;
    rep (i,n){
        ans = max(ans, updp[i] + downdp[n-i-1] - 1);
        // cerr << i << " " << n-i-1 << endl;
    }
    cout << ans << endl;

    // rep(i,n){
    //     cerr << updp[i] << " ";
    // }
    // cerr << endl;
    // rep(i,n){
    //     cerr << downdp[i] << " ";
    // }
    // cerr << endl;
    return 0;


}
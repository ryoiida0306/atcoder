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
    vi a(n);
    rep(i,n) cin >> a[i];
    vi up(n), down(n);

    set<int> up_s;
    rep(i,n){
        auto it = up_s.lower_bound(a[i]);
        if(it == up_s.end()){
            up_s.insert(a[i]);
        }else{
            up_s.erase(it);
            up_s.insert(a[i]);
        }
        up[i] = (int)up_s.size();
    }

    set<int> down_s;
    rrep(i,n){
        auto it = down_s.lower_bound(a[i]);
        if(it == down_s.end()){
            down_s.insert(a[i]);
        }else{
            down_s.erase(it);
            down_s.insert(a[i]);
        }
        down[i] = (int)down_s.size();
    }

    int ans = 0;
    rep(i,n){
        ans = max(ans, up[i] + down[i] - 1);
    }

    cout << ans << endl;



}
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
    int n, q;
    cin >> n >> q;
    vector<char> h(q);
    vector<int> t(q);
    rep(i,q) cin >> h[i] >> t[i];
    rep(i,q) t[i]--;

    // vi ring(n, 0);
    // ring[0] = 1; // L = 1
    // ring[1] = 2; // R = 2
    int l = 0, r = 1;

    reverse(h.begin(), h.end());
    reverse(t.begin(), t.end());

    int ans = 0;

    while(q--){
        if(h[q] == 'L') {
            if(l == t[q]) continue;
            if((l < r && r < t[q]) ||(t[q] < r && r < l)){
                ans += n - abs((t[q] - l)%n);
            }else{
                ans += abs((t[q] - l)%n);
            }
            l = t[q];
        }
        if(h[q] == 'R') {
            if(r == t[q]) continue;
            if((r < l && l < t[q]) ||(t[q] < l && l < r)){
                ans += n - abs((t[q] - r)%n);
            }else{
                ans += abs((t[q] - r)%n);
            }
            r = t[q];
        }

        // cerr << ans << endl;
        // cerr << l << " " << r << endl;


    }

    cout << ans << endl;

}
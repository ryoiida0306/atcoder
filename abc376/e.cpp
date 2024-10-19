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
int main() {
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> p;
        vector<ll> a(n), b(n);
        rep(i,n) cin >> a[i];
        rep(i,n) cin >> b[i];
        rep(i,n) p.push_back({a[i], b[i]});

        sort(p.begin(), p.end());

        multiset<ll> sbk;
        ll sum = 0;
        rep(i,k){
            sum += p[i].second;
            sbk.insert(p[i].second);
        }
        ll ans = p[k-1].first * sum;

        // cerr << p[k-1].first << " " << sum << endl;
        for(int i = k; i < n; i++){
            auto it = prev(sbk.end());
            if(*it > p[i].second){
                sum -= *it;
                sum += p[i].second;
                sbk.erase(it);
                sbk.insert(p[i].second);
                ans = min(ans, p[i].first * sum);
            }
            // cerr << p[i].first << " " << sum << endl;
        }
        // cerr << endl;
        cout << ans << endl;


    }
}
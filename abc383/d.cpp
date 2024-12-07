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
    ll n;
    cin >> n;
    n = sqrt(n);
    vl p(n+10, 0);


    // // エラトステネスの篩
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; i++){
        if (!is_prime[i]) continue;
        for (ll j = i * 2; j <= n; j += i){
            is_prime[j] = false;
        }
    }

    // is[1] = true;

    rep1(i,n){
        if (is_prime[i]){
            p[i] = 1;
        }
        p[i] += p[i-1];
    }

    ll ans = 0;

    rep1(i,n/2){
        if (i == 1) continue;
        if (!is_prime[i]) continue;
        // cerr << i << " " << n/i << " " << p[n/i] << endl;
        ans += p[n/i] -1;
        if(n/i < i) ans++;

    }
    ans /= 2;

    ll num = 2;
    while(true){
        if(pow(num, 4) > n) break;
        if(!is_prime[num]){
            num++;
            continue;
        }
        num++;
        ans++;
    }

    cout << ans << endl;

}
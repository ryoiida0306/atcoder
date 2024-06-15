#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
#include <cmath>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0 ; --i)
#define rrep1(i,n) for(int i = (n); i > 0; --i)
// #define all(a) (a).begin, (a).end()
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

int main(){
  int n, m;
  cin >> n >> m;
  multiset<ll> a;
  vl b(m);
  rep(i,n){
    ll aa;
    cin >> aa;
    a.insert(aa);
  }
  rep(i,m) cin >> b[i];
  sort(b.begin(),b.end());
  
  ll ans = 0;
  rep(i,m){
    auto it = a.lower_bound(b[i]);
    if(it == a.end()){
      cout << -1 << endl;
      return 0;
    }
    a.erase(it);
    ans += *it;
  }
  cout << ans << endl;
  return 0;
}
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
using mytpl = tuple<ll,int,int>;

vector<ll> f(vector<ll> in, vector<ll> x){
  vector<ll> b((int)in.size());
  rep1(i,(int)in.size()-1){
    b[i] = in[x[i]];
  }
  return b;
}

int main(){
  ll n, k;
  cin >> n >> k;
  vector<ll> x(n+1L), a(n+1L);
  rep1(i,n) cin >> x[i];
  rep1(i,n) cin >> a[i];
  
  vector<vector<ll>> pow2(80,vector<ll>(n+1L));
  pow2[0] = x;
  rep(i,80){
    if(i == 0)continue;
    pow2[i] = f(pow2[i-1],pow2[i-1]);
  }
  ll itr = 0;
  while(k!=0){
    cerr << k << endl;
    if(k & 1L) a = f(a,pow2[itr]);
    k = k>>1L;
    itr++;
  }
  rep1(i,n){
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
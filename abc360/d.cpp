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

int main(){
  int n, t;
  cin >> n >> t;
  string s;
  cin >> s;
  vector<ll> pos, neg;
  rep(i,n){
    ll x;
    cin >> x;
    if(s[i] == '1'){
      pos.push_back(x);
    }else{
      neg.push_back(x);
    }
  }
  neg.push_back(LINF);
  neg.push_back(-LINF);
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  
  ll ans = 0;
  rep(i,(int)pos.size()){
    int now_num = 0;
    int to2t_num = 0;
    int l = 0;
    int r = (int)neg.size()-1;
    while(r - l > 1){
      int m = (r+l)/2;
      if(pos[i] < neg[m]) r = m;
      else l = m;
    }
    now_num = l;
    l = 0;
    r = (int)neg.size()-1;
    while(r - l > 1){
      int m = (r+l)/2;
      if(pos[i]+2*t < neg[m]) r = m;
      else l = m;
    }
    to2t_num = l;
    ll res = to2t_num - now_num;
    ans += res;
    // cerr << res << endl;
    // cerr << now_num << " " << to2t_num << endl;
  }
  cout << ans << endl;
  return 0;
}
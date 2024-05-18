#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
#include <cmath>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
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

void show(set<int> s){
  while((int)s.size()){
    int t = *s.begin();
    cerr << t << " ";
    s.erase(*s.begin());
  }
  cerr << endl;
  
}
int main(){
  int n, k;
  cin >> n >> k;
  if(k == 1){
    cout << 0 << endl;
    return 0;
  }
  vi p(n+1);
  rep(i,n){
    int pp;
    cin >> pp;
    p[pp] = i+1;
  }
  
  set<int> s;
  rep(i,k+1){
    if(!i)continue;
    s.insert(p[i]);
  }
  // show(s);
  int ans = INF;
  // int a = *s.end();
  // cout << a << endl;
  ans = (int)*s.rbegin() - (int)*s.begin();
  // cout << ans << endl;
  for(int i = k+1; i <= n; i++){
    s.erase(p[i-k]);
    s.insert(p[i]);
    ans = min(ans, *s.rbegin() - *s.begin());
    // show(s);
    // cout << ans << endl;
  }
  
  cout << ans << endl;
  
  
  
  
  return 0;
}
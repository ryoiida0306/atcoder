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
  int n, k;
  cin >> n >> k;
  vector<int> r(n);
  rep(i,n) cin >> r[i];
  set<string> ans;
  
  int m = pow(10,n-1);
  rep(i,m){
    string s = to_string(i);
    if((int)s.size() != n-1)continue;
    bool ok = true;
    rep(j,(int)s.size()){
      if('1' <= s[j] && s[j] <= (r[j] + '0')) continue;
      ok = false;
    }
    if(ok) ans.insert(s);
  }
  set<string> newans;
  
  for(auto& s : ans){
    int sum = 0;
    for(char c : s){
      sum += (c - '0');
    }
    int init = k - (sum % k);
    while(init <= r.back()){
      if(init == 0){
        init +=k;
        continue;
      }
      string news = s;
      news += (char)(init + '0');
      newans.insert(news);
      init += k;
    }
  }
  if(n == 1){
    int init = k;
    while(init <= r.back()){
      string s = "";
      s += (char)(init + '0');
      newans.insert(s);
      init += k;
    }
  }
  
  for(auto& value : newans){
    for(char c : value){
      cout << c << " ";
    }
    cout << endl;
  }
  return 0;
}
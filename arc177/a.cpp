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
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  int n;
  cin >> n;
  vi x(n);
  rep(i,n)cin >> x[i];
  rep(i,n){
    while(x[i]){
      // cerr << x[i] << endl;
      if(f > 0 && x[i] - 500 >= 0){
        x[i]-=500;
        f--;
        continue;
      }
      if(e > 0 && x[i] - 100 >= 0){
        x[i]-=100;
        e--;
        continue;
      }
      if(d > 0 && x[i] - 50 >= 0){
        x[i]-=50;
        d--;
        continue;
      }
      if(c > 0 && x[i] - 10 >= 0){
        x[i]-=10;
        c--;
        continue;
      }
      if(b > 0 && x[i] - 5 >= 0){
        x[i]-=5;
        b--;
        continue;
      }
      if(a > 0 && x[i] - 1 >= 0){
        x[i]-=1;
        a--;
        continue;
      }
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
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

int cross(int a, int b, int c, int d){
  int ok = 0;
  if(a>b) swap(a,b);
  if(c>d) swap(c,d);
  return max(a,c) < min(b,d);
  return ok;
}

int main(){
  int a,b,c,d,e,f,g,h,i,j,k,l;
  cin >> a >> b >> c >> d >> e >> f;
  cin >> g >> h >> i >> j >> k >> l;
  
  int ok = 0;
  ok += cross(a,d,g,j);
  ok += cross(b,e,h,k);
  ok += cross(c,f,i,l);
  
  if(ok == 3)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
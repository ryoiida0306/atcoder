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


void show(vector<vector<bool>> card){
  rep(i,(int)card.size()){
    rep(j,(int)card[i].size()){
      if(card[i][j]) cerr << 1 << " ";
      else cerr << 0 << " ";
    }
    cerr << endl;
  }
  cerr << endl;
}
int main(){
  int n, t;
  cin >> n >> t;
  
  vector<vector<bool>> card(n,vector<bool>(n,false));
  vector<int> h(n,0);
  vector<int> w(n,0);
  int nana1 = 0;
  int nana2 = 0;
  rep(k,t){
    int a;
    cin >> a;
    a--;
    int l = a/n;
    int m = a%n;
    card[l][m] = true;
    // show(card);
    h[l]++;
    w[m]++;
    if(l == m)nana1++;
    if(l == n-m-1)nana2++;
    if(h[l] == n || w[m] == n || nana1 == n || nana2 == n){
      cout << k+1 << endl;
      return 0;
    }
  }
  cout << "-1" << endl;
  
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
#include <cmath>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using mint = modint998244353;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  set<string> S;
  vi day;
  rep(i,n){
    string s;
    cin >> s;
    if(S.count(s))continue;
    day.push_back(i+1);
    S.insert(s);
  }
  
  for(int v : day){
    cout << v << endl;
  }
  cout << endl;
  
  return 0;
}



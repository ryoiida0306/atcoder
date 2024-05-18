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
  string s;
  cin >> s;
  set<string> S;
  rep(i,(int)s.size()){
    for(int j = 1; j <= (int)s.size(); j++){
      if(i+j>(int)s.size())continue;
      S.insert(s.substr(i,j));
    }
  }
  
  cout << S.size() << endl;
  // for(string ss : S){
  //   cerr << ss << endl;
  // }
  
  return 0;
}



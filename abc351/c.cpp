#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using mint = modint998244353;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void show(deque<int> q, int ss){
  rep(i,ss){
    cerr << q.front() << " ";
    q.pop_front();
  }
  cerr << endl;
}
int main() {
  int n;
  cin >> n;
  vi a(n);
  deque<int> Q;
  rep(i,n){
    cin >> a[i];
  }
  // cout << (int)Q.size() << endl;
  rep(i,n){
    // show(Q,(int)Q.size());
    int now = a[i];
    Q.push_back(now);
    if((int)Q.size() <= 1) continue;
    // Q.pop_front();
    while((int)Q.size() >1){
      int back1 = Q.back();
      Q.pop_back();
      int back2 = Q.back();
      if(back1 == back2) Q.back()++;
      else{
        Q.push_back(back1);
        break;
      }
    }
  }
  
  cout << Q.size() << endl;
  return 0;
}

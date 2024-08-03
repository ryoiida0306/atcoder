#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  
  sort(a.begin(),a.end());
  
  vector<ll> sum_a(n);
  sum_a[0] = a[0];
  for(int i = 1; i < n; ++i){
    sum_a[i] = sum_a[i-1] + a[i];
  }
  
  auto f = [&](ll x) -> bool {
    ll idx = lower_bound(a.begin(), a.end(), x) - a.begin();
    ll res = 0;
    if (idx > 0) res += sum_a[idx-1];
    res += (n - idx) * x;
    return res <= m;
  };

  ll l = 0, r = *max_element(a.begin(), a.end()) + 1;
  while (r - l > 1) {
    ll x = (l + r) / 2;
    if (f(x)) {
      l = x;
    } else {
      r = x;
    }
  }

  if (l == *max_element(a.begin(), a.end())) cout << "infinite" << endl;
  else cout << l << endl;
  
  return 0;
}

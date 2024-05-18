#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i<(n); ++i)
using ll = long long;


int main() {
 string s;
 cin >> s;
 vector<char> v(100); 
 for(char c : s){
   v[(int)(c - 'a')]++;
  // cout << (int)(c - 'a') << endl;
 }
 char tigau;
 rep(i,v.size()){
   if(v[i] == 1){
     tigau = i + 'a';
     break;
   }
 }
// cout << tigau << endl;
 
 int ans;
 
 rep(i,100){
   if(tigau == s[i]){
     ans = i+1;
     break;
   }
 }
 cout << ans << endl;
 
  
}

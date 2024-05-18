#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i<(n); ++i)
using ll = long long;


int main() {
 int n;
 string s;
 int q;
 vector<int> change(100);
 
 rep(i,change.size()){
   change[i] = i;
 }
 
 cin >> n >> s >> q;
 rep(i,q){
   char c,d;
   cin >> c >> d;
  // change[(int)(c - 'a')] = (int)(d - 'a');
   rep(j,change.size()){
    if(change[j]==(int)(c - 'a')){
      change[j] = (int)(d - 'a');
    }
   }
  // cout << (char)('a' + change['s' - 'a']) << endl;
 }
 
// for(int n : change){
//   cout << n << endl;
// }
 
 for(char c : s){
   cout << (char)(change[c - 'a'] + 'a');
 }
 cout << endl;
}

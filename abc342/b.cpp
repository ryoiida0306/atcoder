#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i<(n); ++i)
using ll = long long;


int main() {
 int n;
 cin >> n;
 vector<int> p(n);
 rep(i,n){
   int a;
   cin >> a;
   p[i] = a;
 }
 
 int q;
 cin >> q;
 
 rep(i,q){
   int a,b;
   cin >> a >> b;
   int aa,bb;
   rep(j,p.size()){
     if(p[j] == a){
       aa = j;
       break;
     }
   }
   rep(j,p.size()){
     if(p[j] == b){
       bb = j;
       break;
     }
   }
   
   if(aa < bb){
     cout << a << endl;
   }else{
     cout << b << endl;
   }
 }
 return 0;
}

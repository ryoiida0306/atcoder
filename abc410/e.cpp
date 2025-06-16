// #include <bits/stdc++.h>
// using namespace std;
// #include <cmath>
// #include <atcoder/all>
// using namespace atcoder;
// #define rep(i,n) for(int i = 0; i < (n); ++i)
// #define rep1(i,n) for(int i = 1; i <= (n); ++i)
// #define rrep(i,n) for(int i = (n)-1; i >= 0 ; --i)
// #define rrep1(i,n) for(int i = (n); i > 0; --i)
// using mint = modint998244353;
// using mint2 = modint1000000007;
// using ll = long long;
// using P = pair<int,int>;
// using vi = vector<int>;
// using vvi = vector<vector<int>>;
// using vl = vector<ll>;
// using vvl = vector<vector<ll>>;
// using vd = vector<double>;
// using vvd = vector<vector<double>>;
// using vc = vector<char>;
// using vvc = vector<vector<char>>;
// using vs = vector<string>;
// using vsi = vector<set<int>>;
// using vsl = vector<set<ll>>;
// using vb = vector<bool>;
// using vvb = vector<vector<bool>>;
// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {1, 0, -1, 0};
// int INF = 1001001001;
// ll LINF = 1001001001001001001;
// using mytpl = tuple<ll,int,int>;
// int main(){
//     int n, h, m; cin >> n >> h >> m;
//     vector<pair<int,int>> x(n);

//     rep(i,n) {
//         int a, b; cin >> a >> b;
//         x[i] = {a, b};
//     }

//     vector<pair<int,int>> v(n);


//     rep(i,n){
//         int a = x[i].first;
//         int b = x[i].second;

//         set<pair<int,int>> s;
//         rep(j,(int)v.size()){
//             int c = v[j].first;
//             int d = v[j].second;
//             if(c+a <= h && d <= m) {
//                 s.insert({c+a, d});
//             }
//             if(c <= h && d+b <= m) {
//                 s.insert({c, d+b});
//             }
//         }
//         int maxsecond = -1;
//         set<pair<int,int>> erases;
//         for(auto [c, d] : s){
//             if(d > maxsecond){
//                 maxsecond = d;
//             }else{
//                 erases.insert({c, d});
//             }
//         }

//         for(auto [c, d] : erases){
//             s.erase({c, d});
//         }
//         v.clear();
//         for(auto [c, d] : s){
//             v.push_back({c, d});
//         }
//         if(v.empty()){
//             cout << i << endl;
//             return 0;
//         }

//     }
//     cout << n << endl;
//     return 0;
// }
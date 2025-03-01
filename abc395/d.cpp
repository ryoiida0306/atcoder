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
//     int n, q; cin >> n >> q;
//     vi bard(n, -1);
//     vi label(n, -1);

//     rep(i,n){
//         bard[i] = i;
//         label[i] = i;
//     }

//     while(q--){
//         int query; cin >> query;
//         if(query == 1){
//             int a, b; cin >> a >> b;
//             a--; b--;
//             bard[a] = label[b];

//         }
//         if(query == 2){
//             int a, b; cin >> a >> b;
//             a--; b--;
//             swap(label[a], label[b]);
//         }
//         if(query == 3){
//             int x; cin >> x;
//             x--;
//             cout << label[bard[x]] + 1 << endl;
//         }
//     }

//     return 0;
// }
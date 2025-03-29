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
// int main() {
//     int n; cin >> n;
//     string s, t; cin >> s >> t;

//     vvi G(26, vi(26, 0));

//     rep(i,n){
//         G[s[i]-'a'][t[i]-'a'] = 1;
//     }

//     vi g_sum(26,0);

//     rep(i, 26)rep(j,26){
//         g_sum[i] += G[i][j];
//     }

//     for(auto g : g_sum){
//         if(g > 1){
//             cout << "-1" << endl;
//             return 0;
//         }
//     }

//     rep(i,26){
//         G[i][i] = 0;
//     }

//     int ans = 0;

//     for(auto g : G)for(auto gg : g){
//         ans += gg;
//     }

//     cout << ans << endl;
// }
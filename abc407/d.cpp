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

// int dfs(int i, int j, vvi &a, vector<vector<bool>> &used, int ans){
//     if(j >= (int)a[0].size()){
//         j = 0;
//         i++;
//     }
//     if(i >= (int)a.size()){
//         int res = 0;
//         rep(x, (int)a.size()) rep(y, (int)a[0].size()){
//             if(!used[x][y]) res ^= a[x][y];
//         }

//         return res;
//     }

//     if(used[i][j]) ans = max(ans, dfs(i, j + 1, a, used, ans));
//     else {
//         if(j + 1 < (int)a[0].size() && !used[i][j + 1]) {
//             used[i][j] = true;
//             used[i][j + 1] = true;
//             ans = max(ans, dfs(i, j + 2, a, used, ans));
//             used[i][j] = false;
//             used[i][j + 1] = false;
//         }
//         if(i + 1 < (int)a.size() && !used[i + 1][j]) {
//             used[i][j] = true;
//             used[i + 1][j] = true;
//             ans = max(ans, dfs(i, j + 1, a, used, ans));
//             used[i][j] = false;
//             used[i + 1][j] = false;
//         }
//         ans = max(ans, dfs(i, j + 1, a, used, ans));
//     }

//     return ans;

// }



// int main(){
//     int h, w; cin >> h >> w;
//     vvi a(h, vi(w));
//     rep(i, h) rep(j, w) cin >> a[i][j];

//     vector<vector<bool>> used(h, vector<bool>(w, false));
//     ll ans = 0;

//     ans = dfs(0, 0, a, used, ans);
//     cout << ans << endl;
//     return 0;



// }
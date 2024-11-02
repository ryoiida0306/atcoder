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
//     int h, w, k;
//     cin >> h >> w >> k;
//     vector<string> s(h);
//     rep(i,h) cin >> s[i];

//     ll ans = 0;

//     rep(x, h)rep(y, w){
//         if(s[x][y] == '#')continue;
//         ll cnt = 0;
//         deque<P> q;
//         set<P> st;
//         q.push_back({x,y});
//         st.insert({x,y});
//         cerr << "x: " << x << " y: " << y << endl;
//         while(!q.empty()){
//             auto [i, j] = q.front(); q.pop_front();
//             rep(d,4){
//                 int nx = i + dx[d];
//                 int ny = j + dy[d];
//                 if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
//                 if(st.count({nx,ny}))continue;
//                 if(s[nx][ny] == '#')continue;
//                 cerr << "nx: " << nx << " ny: " << ny << endl;
//                 q.push_front({nx,ny});
//                 st.insert({nx,ny});
//                 if ((int)st.size() == k + 1) {
//                     cnt++;
//                     cerr << "^^^" << endl;
//                     st.erase({nx,ny});
//                     q.pop_front();
//                 }
//             }
//             st.erase({i,j});
//         }
//         ans += cnt;
//     }

//     cout << ans << endl;
//     return 0;
// }
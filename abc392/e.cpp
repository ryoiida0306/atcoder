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
//     int n, m; cin >> n >> m;
//     dsu g(n);
//     vector<set<int>> d(n);
//     map<P, int> e;
//     map<int, P> re;
//     set<int> rooper;
//     rep(i,m){
//         int a, b; cin >> a >> b;
//         a--; b--;
//         re[i] = P(a,b);
//         d[a].insert(b);
//         d[b].insert(a);
//         e[P(a,b)] = i;
//         e[P(b,a)] = i;
//         if(g.same(a,b)){
//             rooper.insert(i);
//             continue;
//         }
//         g.merge(a, b);
//     }

//     set<P> rooper2;
//     for(auto i : rooper){
//         rooper2.insert({g.leader(re[i].first), i});
//     }

//     vi leaders;

//     for(auto i : g.groups()){
//         leaders.push_back(i.front());
//     }

//     vector<tuple<int,int,int>> ans;

//     for(auto i : leaders){
//         if((int)ans.size() == (int)leaders.size()-1) break;
//         for(auto j : rooper2){
//             if(i == j.first) continue;
//             ans.push_back({j.second, re[j.second].first, i});
//             d[re[j.second].first].insert(i);
//             d[i].insert(re[j.second].first);
//             rooper2.erase(j);
//             break;
//         }
//     }


//     cout << (int)ans.size() << endl;

//     for(auto i : ans){
//         cout << get<0>(i)+1 << " " << get<1>(i)+1 << " " << get<2>(i)+1 << endl;
//     }

//     // for(auto i : rooper){
//     //     cerr << i << endl;
//     // }

//     // for(auto i : rooper2){
//     //     cerr << i.first << " " << i.second << endl;
//     // }

//     // for(auto i : re){
//     //     cerr << i.first << " " << i.second.first << " " << i.second.second << endl;
//     // }

// }
#include <bits/stdc++.h>
using namespace std;
#include <cmath>
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0 ; --i)
#define rrep1(i,n) for(int i = (n); i > 0; --i)
using mint = modint998244353;
using mint2 = modint1000000007;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vs = vector<string>;
using vsi = vector<set<int>>;
using vsl = vector<set<ll>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int INF = 1001001001;
ll LINF = 1001001001001001001;
using mytpl = tuple<ll,int,int>;
int main(){
    int n, k;
    cin >> n >> k;
    vvi p(n, vi(3));
    rep(i, n){
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    }

    vector<int> p_sum(n);
    rep(i, n){
        p_sum[i] = p[i][0] + p[i][1] + p[i][2];
    }

    vi sort_p_sum = p_sum;
    sort(sort_p_sum.begin(), sort_p_sum.end());
    // reverse(sort_p_sum.begin(), sort_p_sum.end());
    for(auto x: sort_p_sum){
        cerr << x << " ";
    }
    cerr << endl;
    int ss = (int)sort_p_sum.size();
    cerr << sort_p_sum[ss-k] << endl;
    cerr << lower_bound(sort_p_sum.begin(), sort_p_sum.end(), sort_p_sum[ss-k]) - sort_p_sum.begin() << endl;
    int m = sort_p_sum[lower_bound(sort_p_sum.begin(), sort_p_sum.end(), sort_p_sum[ss-k]) - sort_p_sum.begin()];

    cerr << m << endl;
    rep(i, n){
        if(p_sum[i]+300 >= m){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
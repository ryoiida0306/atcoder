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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans = 0;

    unordered_set<int> unique_elements(a.begin(), a.end());
    unordered_map<int, int> rs_count;
    
    for(int i = 1; i < n; i++) rs_count[a[i]]++;

    unordered_map<int, int> ls_count;
    ls_count[a[0]] = 1;

    int tmp = unique_elements.size() + (rs_count[a[0]] > 0);
    ans = tmp;

    for(int i = 1; i < n - 1; i++){
        if(ls_count[a[i]] == 0) tmp++;
        if(rs_count[a[i]] == 1) tmp--;
        ls_count[a[i]]++;
        rs_count[a[i]]--;

        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}

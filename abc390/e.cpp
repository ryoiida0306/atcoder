#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define INF 1001001001

int main() {
    int n, x; cin >> n >> x;
    vector<int> v(n), a(n), c(n);
    rep(i, n) cin >> v[i] >> a[i] >> c[i];

    vector<int> dp1(x + 1, 0), dp2(x + 1, 0), dp3(x + 1, 0);

    rep(i, n) {
        if (v[i] == 1) {
            for (int j = x; j >= c[i]; --j) {
                dp1[j] = max(dp1[j], dp1[j - c[i]] + a[i]);
            }
        } else if (v[i] == 2) {
            for (int j = x; j >= c[i]; --j) {
                dp2[j] = max(dp2[j], dp2[j - c[i]] + a[i]);
            }
        } else if (v[i] == 3) {
            for (int j = x; j >= c[i]; --j) {
                dp3[j] = max(dp3[j], dp3[j - c[i]] + a[i]);
            }
        }
    }

    int max_min_vitamin = 0;
    for (int cal1 = 0; cal1 <= x; ++cal1) {
        for (int cal2 = 0; cal2 + cal1 <= x; ++cal2) {
            int cal3 = x - cal1 - cal2;
            int vitamin1 = dp1[cal1];
            int vitamin2 = dp2[cal2];
            int vitamin3 = dp3[cal3];
            max_min_vitamin = max(max_min_vitamin, min({vitamin1, vitamin2, vitamin3}));
        }
    }

    cout << max_min_vitamin << endl;
    return 0;
}

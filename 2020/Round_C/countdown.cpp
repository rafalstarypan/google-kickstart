#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Kickstart 2020 Round C
    Problem name: Countdown
    Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003380d2
*/

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 2e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 1e9;
const ll MOD = 998244353LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i = 0;
    int ans = 0;
    while (i < n) {
        if (a[i] == k) {
            int now = k;
            while (i < n && a[i] == now && now > 0) {
                i++;
                now--;
            }
            if (now == 0) ans++;
        } else {
            i++;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }


    return 0;
}

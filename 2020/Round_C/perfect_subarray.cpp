#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Kickstart 2020 Round C
    Problem name: Perfect Subarray
    Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003381cb
*/

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 1e5+5;
const int M = 1e7;
const ll INF = (ll)(1e18);
const int inf = 1e9;
const ll MOD = 998244353LL;

int n;
int a[MAX_N];
int mp[2*M+1];

void solve() {
    memset(mp, 0, sizeof(mp));
    cin >> n;
    int stop = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) stop += a[i];
    }

    mp[M] = 1;
    ll ans = 0LL;
    int curSum = 0;

    for (int i = 0; i < n; i++) {
        curSum += a[i];
        for (int k = 0; k*k <= stop; k++) {
            ans += mp[M + (curSum - k*k)];
        }
        mp[M + curSum]++;
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

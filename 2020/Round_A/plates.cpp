#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Kickstart 2020 Round A
    Problem name: Plates
    Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d40bb
*/

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 1e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 1e9;
const ll MOD = 1000000007LL;

int n, k, p;
int a[55][35];
int pref[55][35];
int dp[55][1550];

int getSum(int i, int j) {
    return pref[i][j];
}

int solve() {
    cin >> n >> k >> p;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j];
            pref[i][j] = pref[i][j-1] + a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p; j++) {
            dp[i][j] = -inf;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= p; j++) {
            for (int x = 0; x <= k; x++) {
                if (j+x > p) break;
                dp[i][j+x] = max(dp[i][j+x], dp[i-1][j] + getSum(i, x));
            }
        }
    }

    return dp[n][p];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << "\n";
    }






    return 0;
}

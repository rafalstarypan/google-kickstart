#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Kickstart 2020 Round D
    Problem name: Alien Piano
    Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387174
*/

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 1e4+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 2e9;
const ll MOD = 1000000007LL;

int n;
int a[MAX_N];
int dp[MAX_N][4];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 0; j < 4; j++) {
			dp[i][j] = inf;
		}
	}
	
	for (int i = 0; i < 4; i++) {
		dp[1][i] = 0;
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (a[i] > a[i-1] && k >= j) {
					dp[i][j] = min(dp[i][j], dp[i-1][k] + 1);
					continue;
				}
				if (a[i] < a[i-1] && j >= k) {
					dp[i][j] = min(dp[i][j], dp[i-1][k] + 1);
					continue;
				}
				if (a[i] == a[i-1] && j != k) {
					dp[i][j] = min(dp[i][j], dp[i-1][k] + 1);
					continue;
				}
				dp[i][j] = min(dp[i][j], dp[i-1][k]);
			}
		}
	}
	
	int ans = inf;
	for (int i = 0; i < 4; i++) {
		ans = min(ans, dp[n][i]);
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

#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Kickstart 2020 Round G
    Problem name: Maximum Coins
    Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069/0000000000414a23
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
const int inf = 2e9;
const ll MOD = 1000000007LL;

int n;
ll a[1005][1005];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	ll ans = 0LL;
	
	for (int col = 1; col <= n; col++) {
		int i = n;
		int j = col;
		ll tmp = 0LL;
		while (i >= 1 && j >= 1) {
			tmp += a[i][j];
			i--;
			j--;
		}
		ans = max(ans, tmp);
	}
	
	for (int row = n; row >= 1; row--) {
		int i = row;
		int j = n;
		ll tmp = 0LL;
		while (i >= 1 && j >= 1) {
			tmp += a[i][j];
			i--;
			j--;
		}
		ans = max(ans, tmp);
	}
	
	cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cout << "Case #" << tt << ": ";
		solve();
	}
	
	
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Kickstart 2020 Round E
    Problem name: Longest Arithmetic
    Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff47/00000000003bf4ed
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

void solve() {
	int n; cin >> n;
	vector<int> a(n), diff;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0) diff.push_back(a[i] - a[i-1]);
	}
	
	int ans = 0;
	int i = 0;
	while (i < diff.size()) {
		int cur = diff[i];
		int len = 1;
		while (i < diff.size() && diff[i] == cur) {
			i++;
			len++;
		}
		ans = max(ans, len);
	}
	
	cout << ans << '\n';
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

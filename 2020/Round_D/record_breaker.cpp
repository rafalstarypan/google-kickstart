#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Kickstart 2020 Round D
    Problem name: Record Breaker
    Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387171
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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	set<int> st;
	int curMax = -1;
	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		if (a[i] > curMax) {
			if (i == n-1) ans++;
			else if (a[i] > a[i+1]) ans++;
		}
		curMax = max(curMax, a[i]);
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

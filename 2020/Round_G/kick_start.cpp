#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Kickstart 2020 Round G
    Problem name: Kick_Start
    Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069/0000000000414bfb
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
	string s; cin >> s;
	int n = (int)s.size();
	ll cnt = 0LL;
	ll ans = 0LL;
	
	for (int i = n-5; i >= 0; i--) {
		if (s.substr(i, 5) == "START") cnt++;
		if (s.substr(i, 4) == "KICK") ans += cnt;
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

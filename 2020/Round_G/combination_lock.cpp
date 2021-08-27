#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Kickstart 2020 Round G
    Problem name: Combination Lock
    Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069/0000000000414a24
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

int w;
ll n;

ll check(const vector<ll>& a, ll x) {
	if (x < 1 || x > n) return INF;
	ll res = 0LL;
	for (int i = 0; i < w; i++) {
		ll b = abs(a[i] - x);
		ll c = n - a[i] + x;
		ll d = (a[i] - 1) + 1 + (n - x);
		res += min({b, c, d});
	}
	return res;
}

void solve() {
	cin >> w >> n;
	vector<ll> a(w);
	for (int i = 0; i < w; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll ans = INF;
	
	vector<ll> who;
	for (ll i : a) {
		ans = min(ans, check(a, i));
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

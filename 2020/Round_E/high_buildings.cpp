#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Kickstart 2020 Round E
    Problem name: High Buildings
    Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff47/00000000003bef73
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

int n, a, b, c;

void solve() {
	cin >> n >> a >> b >> c;
	
	if (a+b-c > n || (a+b-c == 1 && n >= 2)) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	
	if (n == 1) {
		cout << "1\n";
		return;
	}
	if (n == 2) {
		if (c == 2) cout << "1 1\n";
		else if (a == 2) cout << "1 2\n";
		else if (b == 2) cout << "2 1\n";
		return;
	}
	
	vector<int> res;
	for (int i = 0; i < a-c; i++) res.push_back(2);
	for (int i = 0; i < c; i++) res.push_back(3);
	for (int i = 0; i < b-c; i++) res.push_back(2);
	
	int todo = n - a - b + c;
	if (todo > 0) res.insert(res.begin()+1, todo, 1);
	
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << '\n';
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
